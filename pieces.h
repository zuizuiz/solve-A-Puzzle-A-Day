#ifndef PIECES_H
#define PIECES_H

#include <vector>
#include <array>

#include "puzzle.h"

constexpr UINT128 PIECE_A1 = 
	(UINT128)1 << 24 | (UINT128)1 << 23 | (UINT128)1 << 22 |
	(UINT128)1 << 13 | 
	(UINT128)1 << 2;

constexpr UINT128 PIECE_A2 = 
	(UINT128)1 << 24 | (UINT128)1 << 23 | (UINT128)1 << 22 |
										  (UINT128)1 << 11 |
										  (UINT128)1 <<  0;
constexpr UINT128 PIECE_A3 = 
	(UINT128)1 << 24 |
	(UINT128)1 << 13 | 
	(UINT128)1 << 2  | (UINT128)1 << 1 | (UINT128)1 << 0;

constexpr UINT128 PIECE_A4 = 
										(UINT128)1 << 22 | 
										(UINT128)1 << 11 |
	(UINT128)1 << 2 | (UINT128)1 << 1 | (UINT128)1 << 0;

constexpr UINT128 PIECE_B1 = 
	(UINT128)1 << 13 | (UINT128)1 << 12 | (UINT128)1 << 11 |
	(UINT128)1 << 2  | (UINT128)1 << 1  | (UINT128)1 << 0;

constexpr UINT128 PIECE_B2 = 
	(UINT128)1 << 23 | (UINT128)1 << 22 | 
	(UINT128)1 << 12 | (UINT128)1 << 11 |
	(UINT128)1 << 1  | (UINT128)1 << 0;

constexpr UINT128 PIECE_C1 = 
										(UINT128)1 << 12 | (UINT128)1 << 11 |
	(UINT128)1 << 3 | (UINT128)1 << 2 | (UINT128)1 << 1;

constexpr UINT128 PIECE_C2 = 
	(UINT128)1 << 14 | (UINT128)1 << 13 | (UINT128)1 << 12 |
										  (UINT128)1 << 1  | (UINT128)1 << 0;

constexpr UINT128 PIECE_C3 = 
					  (UINT128)1 << 13 | (UINT128)1 << 12 | (UINT128)1 << 11 |
	(UINT128)1 << 3 | (UINT128)1 << 2;

constexpr UINT128 PIECE_C4 = 
	(UINT128)1 << 14 | (UINT128)1 << 13 |
					   (UINT128)1 << 2  | (UINT128)1 << 1 | (UINT128)1 << 0;

constexpr UINT128 PIECE_C5 = 
	(UINT128)1 << 34 | 
	(UINT128)1 << 23 | 
	(UINT128)1 << 12 | (UINT128)1 << 11 | 
					   (UINT128)1 << 0;
constexpr UINT128 PIECE_C6 = 
					   (UINT128)1 << 33 | 
					   (UINT128)1 << 22 | 
	(UINT128)1 << 12 | (UINT128)1 << 11 | 
	(UINT128)1 << 1;

constexpr UINT128 PIECE_C7 = 
					   (UINT128)1 << 33 |
	(UINT128)1 << 23 | (UINT128)1 << 22 | 
	(UINT128)1 << 12 | 
	(UINT128)1 << 1;

constexpr UINT128 PIECE_C8 = 
	(UINT128)1 << 34 |
	(UINT128)1 << 23 | (UINT128)1 << 22 | 
					   (UINT128)1 << 11 | 
					   (UINT128)1 << 0;

constexpr UINT128 PIECE_D1 = 
	(UINT128)1 << 34 | 
	(UINT128)1 << 23 | 
	(UINT128)1 << 12 |
	(UINT128)1 << 1  | (UINT128)1 << 0;

constexpr UINT128 PIECE_D2 = 
					  (UINT128)1 << 33 | 
					  (UINT128)1 << 22 | 
					  (UINT128)1 << 11 |
	(UINT128)1 << 1 | (UINT128)1 << 0;

constexpr UINT128 PIECE_D3 = 
	(UINT128)1 << 34 | (UINT128)1 << 33 |
	(UINT128)1 << 23 | 
	(UINT128)1 << 12 | 
	(UINT128)1 << 1;

constexpr UINT128 PIECE_D4 = 
	(UINT128)1 << 34 | (UINT128)1 << 33 |
					   (UINT128)1 << 22 | 
					   (UINT128)1 << 11 | 
					   (UINT128)1 << 0;

constexpr UINT128 PIECE_D5 = 
	(UINT128)1 << 14 | (UINT128)1 << 13 | (UINT128)1 << 12 | (UINT128)1 << 11 | 
															 (UINT128)1 << 0;

constexpr UINT128 PIECE_D6 = 
	(UINT128)1 << 14 | (UINT128)1 << 13 | (UINT128)1 << 12 | (UINT128)1 << 11 | 
	(UINT128)1 << 3;

constexpr UINT128 PIECE_D7 = 
														  (UINT128)1 << 11 |
	(UINT128)1 << 3 | (UINT128)1 << 2 | (UINT128)1 << 1 | (UINT128)1 << 0;

constexpr UINT128 PIECE_D8 = 
	(UINT128)1 << 14 |
	(UINT128)1 << 3  | (UINT128)1 << 2 | (UINT128)1 << 1 | (UINT128)1 << 0;


constexpr UINT128 PIECE_E1 = 
	(UINT128)1 << 14 | (UINT128)1 << 13 | (UINT128)1 << 12 |(UINT128)1 << 11 | 
					   (UINT128)1 << 2;

constexpr UINT128 PIECE_E2 = 
	(UINT128)1 << 14 | (UINT128)1 << 13 | (UINT128)1 << 12 |(UINT128)1 << 11 | 
										  (UINT128)1 << 1;

constexpr UINT128 PIECE_E3 = 
					  (UINT128)1 << 13 |
	(UINT128)1 << 3 | (UINT128)1 << 2  | (UINT128)1 << 1 |(UINT128)1 << 0;

constexpr UINT128 PIECE_E4 = 
										(UINT128)1 << 12 |
	(UINT128)1 << 3 | (UINT128)1 << 2 | (UINT128)1 << 1  |(UINT128)1 << 0;

constexpr UINT128 PIECE_E5 = 
	(UINT128)1 << 34 |
	(UINT128)1 << 23 | (UINT128)1 << 22 |
	(UINT128)1 << 12 |
	(UINT128)1 << 1;

constexpr UINT128 PIECE_E6 = 
						(UINT128)1 << 33 |
	 (UINT128)1 << 23 | (UINT128)1 << 22 |
						(UINT128)1 << 11 |
						(UINT128)1 << 0;

constexpr UINT128 PIECE_E7 = 
						(UINT128)1 << 33 |
						(UINT128)1 << 22 |
	 (UINT128)1 << 12 | (UINT128)1 << 11 |
						(UINT128)1 << 0;

constexpr UINT128 PIECE_E8 = 
	(UINT128)1 << 34 |
	(UINT128)1 << 23 |
	(UINT128)1 << 12 | (UINT128)1 << 11 |
	(UINT128)1 << 1;

constexpr UINT128 PIECE_F1 = 
	(UINT128)1 << 13 				  | (UINT128)1 << 11 |
	(UINT128)1 << 2 | (UINT128)1 << 1 | (UINT128)1 << 0;

constexpr UINT128 PIECE_F2 = 
	(UINT128)1 << 13 | (UINT128)1 << 12 | (UINT128)1 << 11 |
	(UINT128)1 << 2 					| (UINT128)1 << 0;

constexpr UINT128 PIECE_F3 = 
	(UINT128)1 << 23 | (UINT128)1 << 22 |
	(UINT128)1 << 12 |
	(UINT128)1 << 1  | (UINT128)1 << 0;

constexpr UINT128 PIECE_F4 = 
	(UINT128)1 << 23 | (UINT128)1 << 22 |
					   (UINT128)1 << 11 |
	(UINT128)1 << 1  | (UINT128)1 << 0;


constexpr UINT128 PIECE_G1 = 
	(UINT128)1 << 24 | 
	(UINT128)1 << 13 | (UINT128)1 << 12 | (UINT128)1 << 11 | 
										  (UINT128)1 << 0;

constexpr UINT128 PIECE_G2 = 
										  (UINT128)1 << 22 | 
	(UINT128)1 << 13 | (UINT128)1 << 12 | (UINT128)1 << 11 | 
	(UINT128)1 << 2;

constexpr UINT128 PIECE_G3 = 
	(UINT128)1 << 24 | (UINT128)1 << 23 | 
					   (UINT128)1 << 12 | 
					   (UINT128)1 << 1  | (UINT128)1 << 0;

constexpr UINT128 PIECE_G4 = 
					  (UINT128)1 << 23 | (UINT128)1 << 22 | 
					  (UINT128)1 << 12 | 
	(UINT128)1 << 2 | (UINT128)1 << 1;

constexpr UINT128 PIECE_H1 = 
	(UINT128)1 << 13 | (UINT128)1 << 12 | (UINT128)1 << 11 |
					   (UINT128)1 << 1  | (UINT128)1 << 0;

constexpr UINT128 PIECE_H2 = 
					  (UINT128)1 << 12 | (UINT128)1 << 11 |
	(UINT128)1 << 2 | (UINT128)1 << 1  | (UINT128)1 << 0;

constexpr UINT128 PIECE_H3 = 
	(UINT128)1 << 13 | (UINT128)1 << 12 | (UINT128)1 << 11 |
	(UINT128)1 << 2  | (UINT128)1 << 1;

constexpr UINT128 PIECE_H4 = 
	(UINT128)1 << 13 | (UINT128)1 << 12 |
	(UINT128)1 << 2  | (UINT128)1 << 1  | (UINT128)1 << 0;

constexpr UINT128 PIECE_H5 = 
	(UINT128)1 << 23 | 
	(UINT128)1 << 12 | (UINT128)1 << 11 |
	(UINT128)1 << 1  | (UINT128)1 << 0;

constexpr UINT128 PIECE_H6 = 
					   (UINT128)1 << 22 | 
	(UINT128)1 << 12 | (UINT128)1 << 11 |
	(UINT128)1 << 1  | (UINT128)1 << 0;

constexpr UINT128 PIECE_H7 = 
	(UINT128)1 << 23 | (UINT128)1 << 22 |
	(UINT128)1 << 12 | (UINT128)1 << 11 |
					   (UINT128)1 << 0;

constexpr UINT128 PIECE_H8 = 
	(UINT128)1 << 23 | (UINT128)1 << 22 |
	(UINT128)1 << 12 | (UINT128)1 << 11 |
	(UINT128)1 << 1;


extern std::vector<UINT128> SUBPIECES_A;
extern std::vector<UINT128> SUBPIECES_B;
extern std::vector<UINT128> SUBPIECES_C;
extern std::vector<UINT128> SUBPIECES_D;
extern std::vector<UINT128> SUBPIECES_E;
extern std::vector<UINT128> SUBPIECES_F;
extern std::vector<UINT128> SUBPIECES_G;
extern std::vector<UINT128> SUBPIECES_H;
extern std::array<std::vector<UINT128>, 8> PIECES;
extern std::array<char, 8> codes;

#endif
