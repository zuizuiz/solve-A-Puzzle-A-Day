#include <array>
#include <numbers>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <iostream>
#include <ctime>
#include <fstream>
#include <filesystem>

#include "puzzle.h"
#include "pieces.h"

using namespace std;

void insertDays(map<string, UINT64> &map){

    UINT64 index = (UINT64)1 << 38;
    for(int day = 1; day <= 31; day++){
        string key = "DAY_" + to_string(day);
        map.insert({key, index});

        index = day % 7 ? index >> 1 : index >> 2;
    }
}

void insertMonths(map<string, UINT64> &map){

    UINT64 index = (UINT64)1 << 54;
    for(int month = 1; month <= 12; month++){
        string key = "MONTH_" + to_string(month);
        map.insert({key, index});

        index = month % 6 ? index >> 1 : index >> 3;
    }
}

map<string, UINT64> removeDate(map<string, UINT64> map, int day, int month){

    time_t now = time(nullptr);
    tm tm = *localtime(&now);

    string day_ = "DAY_" + to_string(day);
    string month_ = "MONTH_" + to_string(month);

    map.erase(day_);
    map.erase(month_);

    return map;
}

UINT64 createBoard(map<string, UINT64> map){

    UINT64 board = 0;
    for(auto const& [key, val] : map) board |= val;
    return board;
}

vector<UINT64> fitPiece(UINT64 piece, UINT64 not_board){

    vector<UINT64> fits;

    for(int i = 4; i < 54; i++){
        if((piece & not_board) == 0 && piece != 0){
            fits.push_back(piece);
        }

        piece <<= 1;
    }

    return fits;
}
array<vector<UINT64>, 8> fit(UINT64 board, array<vector<UINT64>, 8> &pieces){

    array<vector<UINT64>, 8> fits;

    for(int i = 0; i < pieces.size(); i++){
        vector<UINT64> pieceFits;

        for(UINT64 subpiece: pieces[i]){
            vector<UINT64> subpieceFits = fitPiece(subpiece, ~board);
            pieceFits.insert(pieceFits.end(), subpieceFits.begin(), subpieceFits.end());
        }
        fits[i] = pieceFits;
    }

    return fits;
}
void solve(
        int index, UINT64 bitboard, 
        vector<UINT64> history, 
        array<vector<UINT64>, 8> &fits,
        multimap<UINT64, vector<UINT64>> &solutions){

    if(index >= 8){
        solutions.emplace(bitboard, history);
        return;
    }

    for(int i = 0; i < fits[index].size(); i++){
        if((bitboard & fits[index][i]) == 0){
            history.push_back(fits[index][i]);
            solve(index + 1, bitboard | fits[index][i], history, fits, solutions);
            history.pop_back();
        }
    }
}

void print(UINT64 bitboard){

    bitset<64> bitset = bitboard;

    cout << "\n";
    for(int i = 0; i < 8; i++){
        cout << bitset.to_string().substr(i * 8, 8) << "\n";
    }
    cout << "\n";
}

void print(vector<UINT64> history, ostream &os = cout){

    vector<bitset<64>> bitsets;
    for(auto bitboard: history){
        bitsets.push_back(bitset<64>(bitboard));
    }

    os << "\n";
    for(int i = 63; i >= 0; i--){
        char square = 'X';
        for(int j = 0; j < bitsets.size(); j++){
            if(bitsets[j][i] == 1){
                square = pieces::codes[j];
                break;
            }
        }
        os << " " << square << " ";
        if(i % 8 == 0) os << "\n";
    }
    os << "\n";
}

void print(map<string, UINT64> map, multimap<UINT64, vector<UINT64>> &solution){

    filesystem::path year = "year";
    filesystem::create_directory(year);

    for(int i = 1; i <= 12; i++){

        filesystem::path month = "month_" + to_string(i);   
        filesystem::create_directory(year / month);

        for(int j = 1; j <= 31; j++){

            filesystem::path day = "day_" + to_string(j);   
            UINT64 board = createBoard(removeDate(map, j, i));
            ofstream file(year / month / day);

            auto range = solution.equal_range(board);
            int count = 0;
            for (auto it = range.first; it != range.second; ++it) {
                print(it->second, file);
                count++;
            }
            file << "Total: " << count;
            file.close();
        }
    }
}

int main(){

    multimap<UINT64, vector<UINT64>> solution;
    map<string, UINT64> map;

    insertDays(map);
    insertMonths(map);
    UINT64 board = createBoard(map);

    array<vector<UINT64>, 8> fits = fit(board, pieces::pieces);
    solve(0, 0, vector<UINT64>(), fits, solution);

    print(map, solution);
}
