#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <iostream>
#include <ctime>

#include "puzzle.h"
#include "pieces.h"

void insertDays(std::map<std::string, UINT64> &map){

	UINT64 index = (UINT64)1 << 38;
	for(int day = 1; day <= 31; day++){
		std::string key = "DAY_" + std::to_string(day);
		map.insert({key, index});

		index = day % 7 ? index >> 1 : index >> 2;
	}
}

void insertMonths(std::map<std::string, UINT64> &map){

	UINT64 index = (UINT64)1 << 54;
	for(int month = 1; month <= 12; month++){
		std::string key = "MONTH_" + std::to_string(month);
		map.insert({key, index});

		index = month % 6 ? index >> 1 : index >> 3;
	}
}

void removeCurrentDate(std::map<std::string, UINT64> &map){

	std::time_t now = std::time(nullptr);
	std::tm tm = *std::localtime(&now);

	std::string day = "DAY_" + std::to_string(tm.tm_mday);
	std::string month = "MONTH_" + std::to_string(tm.tm_mon + 1);

	//std::string month = "MONTH_10";
	//std::string day = "DAY_6";

	map.erase(day);
	map.erase(month);
}

void setBoard(std::map<std::string, UINT64> map, UINT64 &board){

	for(auto const& [key, val] : map){
		board |= val;
	}
}

std::bitset<128> to_bitset(UINT64 bitboard){

	std::bitset<128> bitset;
	bitset |= bitboard >> 64;
	bitset <<= 64;
	bitset |= bitboard;

	return bitset;
}

void print(UINT64 bitboard){

	std::bitset<64> bitset = bitboard;

	std::cout << std::endl;
	for(int i = 0; i < 8; i++){
		std::cout << bitset.to_string().substr(i * 8, 8) << std::endl;
	}
	std::cout << std::endl;
}

void print(std::vector<UINT64> history, FILE* file = stdout){
	
	std::vector<std::bitset<64>> bitsets;
	for(auto bitboard: history){
		bitsets.push_back(std::bitset<64>(bitboard));
	}

	fprintf(file, "\n");
	for(int i = 63; i >= 0; i--){
		char square = 'X';
		for(int j = 0; j < bitsets.size(); j++){
			if(bitsets[j][i] == 1){
				square = codes[j];
				break;
			}
		}
		fprintf(file, " %c ", square);
		if(i % 8 == 0){
			fprintf(file, "\n");
		}
	}
	fprintf(file, "\n");
	
}

std::vector<UINT64> fitPiece(UINT64 piece, UINT64 not_board){
	
	std::vector<UINT64> fits;

	for(int i = 4; i < 54; i++){
		if((piece & not_board) == 0 && piece != 0){
			fits.push_back(piece);
		}

		piece <<= 1;
	}

	return fits;
}

std::pair<UINT64, std::vector<UINT64>> recursive(std::array<std::vector<UINT64>, 8> &fits, int index, UINT64 bitboard, std::vector<UINT64> history, int &counter){

	std::pair<UINT64, std::vector<UINT64>> result = index < 8 ? std::pair((UINT64)0, history) : std::pair(bitboard, history);

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

	UINT64 board = 0;
	std::map<std::string, UINT64> map;

	insertDays(map);
	insertMonths(map);
	removeCurrentDate(map);
	setBoard(map, board);

	print(board);

	std::array<std::vector<UINT64>, 8> fits;
	for(int i = 0; i < PIECES.size(); i++){
		std::vector<UINT64> pieceFits;
		for(UINT64 subpiece: PIECES[i]){
			std::vector<UINT64> subpieceFits = fitPiece(subpiece, ~board);
			pieceFits.insert(pieceFits.end(), subpieceFits.begin(), subpieceFits.end());
		}
		fits[i] = pieceFits;
	}


	int counter = 0;
	recursive(fits, 0, 0, std::vector<UINT64>(), counter);
	printf("Total: %d\n", counter);
/*
*/
}
