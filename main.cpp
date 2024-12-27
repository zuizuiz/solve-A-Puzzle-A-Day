#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <iostream>
#include <ctime>

#include "puzzle.h"
#include "pieces.h"

void insertDays(std::map<std::string, UINT128> &map){

	UINT128 index = (UINT128)1 << 74;
	for(int day = 1; day <= 31; day++){
		std::string key = "DAY_" + std::to_string(day);
		map.insert({key, index});

		index = day % 7 ? index >> 1 : index >> 5;
	}
}

void insertMonths(std::map<std::string, UINT128> &map){

	UINT128 index = (UINT128)1 << 96;
	for(int month = 1; month <= 12; month++){
		std::string key = "MONTH_" + std::to_string(month);
		map.insert({key, index});

		index = month % 6 ? index >> 1 : index >> 6;
	}
}

void removeCurrentDate(std::map<std::string, UINT128> &map){

	std::time_t now = std::time(nullptr);
	std::tm tm = *std::localtime(&now);

	std::string day = "DAY_" + std::to_string(tm.tm_mday);
	std::string month = "MONTH_" + std::to_string(tm.tm_mon + 1);

	map.erase(day);
	map.erase(month);
}

void setBoard(std::map<std::string, UINT128> map, UINT128 &board){

	for(auto const& [key, val] : map){
		board |= val;
	}
}

std::bitset<128> to_bitset(UINT128 bitboard){

	std::bitset<128> bitset;
	bitset |= bitboard >> 64;
	bitset <<= 64;
	bitset |= bitboard;

	return bitset;
}

void print(UINT128 bitboard){

	std::bitset<128> bitset = to_bitset(bitboard);

	std::cout << std::endl;
	for(int i = 0; i < 11; i++){
		std::cout << bitset.to_string().substr(i * 11 + 7, 11) << std::endl;
	}
	std::cout << std::endl;
}

void print(std::vector<UINT128> history, FILE* file = stdout){
	
	std::vector<std::bitset<128>> bitsets;
	for(auto bitboard: history){
		bitsets.push_back(to_bitset(bitboard));
	}

	fprintf(file, "\n");
	for(int i = 120; i >= 0; i--){
		char square = 'X';
		for(int j = 0; j < bitsets.size(); j++){
			if(bitsets[j][i] == 1){
				square = codes[j];
				break;
			}
		}
		fprintf(file, " %c ", square);
		if(i % 11 == 0){
			fprintf(file, "\n");
		}
	}
	fprintf(file, "\n");
	
}

std::vector<UINT128> fitPiece(UINT128 piece, UINT128 not_board){
	
	std::vector<UINT128> fits;

	for(int i = 0; i < 128; i++){
		if((piece & not_board) == 0 && piece != 0){
			fits.push_back(piece);
		}

		piece <<= 1;
	}

	return fits;
}

std::pair<UINT128, std::vector<UINT128>> recursive(std::array<std::vector<UINT128>, 8> &fits, int index, UINT128 bitboard, std::vector<UINT128> history, int &counter){

	std::pair<UINT128, std::vector<UINT128>> result = index < 8 ? std::pair((UINT128)0, history) : std::pair(bitboard, history);

	for(int i = 0; i < fits[index].size(); i++){
		if((bitboard & fits[index][i]) == 0){
			history.push_back(fits[index][i]);
			result = recursive(fits, index + 1, bitboard | fits[index][i], history, counter);
			if(result.first > 0 && history.size() == 8){
				print(result.second);
				counter++;
			}
			history.pop_back();
		}
	}

	return result;
}

int main(){

	UINT128 board = 0;
	std::map<std::string, UINT128> map;

	insertDays(map);
	insertMonths(map);
	removeCurrentDate(map);
	setBoard(map, board);

	std::array<std::vector<UINT128>, 8> fits;

	for(int i = 0; i < PIECES.size(); i++){
		std::vector<UINT128> pieceFits;
		for(UINT128 subpiece: PIECES[i]){
			std::vector<UINT128> subpieceFits = fitPiece(subpiece, ~board);
			pieceFits.insert(pieceFits.end(), subpieceFits.begin(), subpieceFits.end());
		}
		fits[i] = pieceFits;
	}

	int counter = 0;
	recursive(fits, 0, 0, std::vector<UINT128>(), counter);
	printf("Total: %d\n", counter);
}
