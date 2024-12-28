#ifndef PIECES_H
#define PIECES_H

#include <vector>
#include <array>

#include "puzzle.h"

namespace pieces {

	constexpr UINT64 PIECE_A1 = 
		(UINT64)1 << 18 | (UINT64)1 << 17 | (UINT64)1 << 16 |
		(UINT64)1 << 10 | 
		(UINT64)1 << 2;

	constexpr UINT64 PIECE_A2 = 
		(UINT64)1 << 18 | (UINT64)1 << 17 | (UINT64)1 << 16 |
											(UINT64)1 << 8  |
											(UINT64)1 << 0;
	constexpr UINT64 PIECE_A3 = 
		(UINT64)1 << 18 |
		(UINT64)1 << 10 | 
		(UINT64)1 << 2  | (UINT64)1 << 1 | (UINT64)1 << 0;

	constexpr UINT64 PIECE_A4 = 
										  (UINT64)1 << 16 | 
										  (UINT64)1 << 8  |
		(UINT64)1 << 2 | (UINT64)1 << 1 | (UINT64)1 << 0;

	constexpr UINT64 PIECE_B1 = 
		(UINT64)1 << 10 | (UINT64)1 << 9 | (UINT64)1 << 8 |
		(UINT64)1 << 2  | (UINT64)1 << 1 | (UINT64)1 << 0;

	constexpr UINT64 PIECE_B2 = 
		(UINT64)1 << 17 | (UINT64)1 << 16 | 
		(UINT64)1 << 9  | (UINT64)1 << 8  |
		(UINT64)1 << 1  | (UINT64)1 << 0;

	constexpr UINT64 PIECE_C1 = 
										  (UINT64)1 << 9 | (UINT64)1 << 8 |
		(UINT64)1 << 3 | (UINT64)1 << 2 | (UINT64)1 << 1;

	constexpr UINT64 PIECE_C2 = 
		(UINT64)1 << 11 | (UINT64)1 << 10 | (UINT64)1 << 9 |
											(UINT64)1 << 1 | (UINT64)1 << 0;

	constexpr UINT64 PIECE_C3 = 
						 (UINT64)1 << 10 | (UINT64)1 << 9 | (UINT64)1 << 8 |
		(UINT64)1 << 3 | (UINT64)1 << 2;

	constexpr UINT64 PIECE_C4 = 
		(UINT64)1 << 11 | (UINT64)1 << 10 |
						  (UINT64)1 << 2  | (UINT64)1 << 1 | (UINT64)1 << 0;

	constexpr UINT64 PIECE_C5 = 
		(UINT64)1 << 25 | 
		(UINT64)1 << 17 | 
		(UINT64)1 << 9  | (UINT64)1 << 8 | 
						  (UINT64)1 << 0;
	constexpr UINT64 PIECE_C6 = 
						 (UINT64)1 << 24 | 
						 (UINT64)1 << 16 | 
		(UINT64)1 << 9 | (UINT64)1 << 8  | 
		(UINT64)1 << 1;

	constexpr UINT64 PIECE_C7 = 
						  (UINT64)1 << 24 |
		(UINT64)1 << 17 | (UINT64)1 << 16 | 
		(UINT64)1 << 9  | 
		(UINT64)1 << 1;

	constexpr UINT64 PIECE_C8 = 
		(UINT64)1 << 25 |
		(UINT64)1 << 17 | (UINT64)1 << 16 | 
						  (UINT64)1 << 8  | 
						  (UINT64)1 << 0;

	constexpr UINT64 PIECE_D1 = 
		(UINT64)1 << 25 | 
		(UINT64)1 << 17 | 
		(UINT64)1 << 9  |
		(UINT64)1 << 1  | (UINT64)1 << 0;

	constexpr UINT64 PIECE_D2 = 
						 (UINT64)1 << 24 | 
						 (UINT64)1 << 16 | 
						 (UINT64)1 << 8  |
		(UINT64)1 << 1 | (UINT64)1 << 0;

	constexpr UINT64 PIECE_D3 = 
		(UINT64)1 << 25 | (UINT64)1 << 24 |
		(UINT64)1 << 17 | 
		(UINT64)1 << 9  | 
		(UINT64)1 << 1;

	constexpr UINT64 PIECE_D4 = 
		(UINT64)1 << 25 | (UINT64)1 << 24 |
						  (UINT64)1 << 16 |
						  (UINT64)1 << 8  |
						  (UINT64)1 << 0;

	constexpr UINT64 PIECE_D5 = 
		(UINT64)1 << 11 | (UINT64)1 << 10 | (UINT64)1 << 9 | (UINT64)1 << 8 | 
															 (UINT64)1 << 0;

	constexpr UINT64 PIECE_D6 = 
		(UINT64)1 << 11 | (UINT64)1 << 10 | (UINT64)1 << 9 | (UINT64)1 << 8 | 
		(UINT64)1 << 3;

	constexpr UINT64 PIECE_D7 = 
														   (UINT64)1 << 8 |
		(UINT64)1 << 3 | (UINT64)1 << 2 | (UINT64)1 << 1 | (UINT64)1 << 0;

	constexpr UINT64 PIECE_D8 = 
		(UINT64)1 << 11 |
		(UINT64)1 << 3  | (UINT64)1 << 2 | (UINT64)1 << 1 | (UINT64)1 << 0;


	constexpr UINT64 PIECE_E1 = 
		(UINT64)1 << 11 | (UINT64)1 << 10 | (UINT64)1 << 9 | (UINT64)1 << 8 | 
						  (UINT64)1 << 2;

	constexpr UINT64 PIECE_E2 = 
		(UINT64)1 << 11 | (UINT64)1 << 10 | (UINT64)1 << 9 | (UINT64)1 << 8 | 
											(UINT64)1 << 1;

	constexpr UINT64 PIECE_E3 = 
						 (UINT64)1 << 10 |
		(UINT64)1 << 3 | (UINT64)1 << 2  | (UINT64)1 << 1 |(UINT64)1 << 0;

	constexpr UINT64 PIECE_E4 = 
										  (UINT64)1 << 9 |
		(UINT64)1 << 3 | (UINT64)1 << 2 | (UINT64)1 << 1  |(UINT64)1 << 0;

	constexpr UINT64 PIECE_E5 = 
		(UINT64)1 << 25 |
		(UINT64)1 << 17 | (UINT64)1 << 16 |
		(UINT64)1 << 9  |
		(UINT64)1 << 1;

	constexpr UINT64 PIECE_E6 = 
						   (UINT64)1 << 24 |
		 (UINT64)1 << 17 | (UINT64)1 << 16 |
						   (UINT64)1 << 8  |
						   (UINT64)1 << 0;

	constexpr UINT64 PIECE_E7 = 
						 (UINT64)1 << 24 |
						 (UINT64)1 << 16 |
		(UINT64)1 << 9 | (UINT64)1 << 8  |
						 (UINT64)1 << 0;

	constexpr UINT64 PIECE_E8 = 
		(UINT64)1 << 25 |
		(UINT64)1 << 17 |
		(UINT64)1 << 9  | (UINT64)1 << 8 |
		(UINT64)1 << 1;

	constexpr UINT64 PIECE_F1 = 
		(UINT64)1 << 10                 | (UINT64)1 << 8 |
		(UINT64)1 << 2 | (UINT64)1 << 1 | (UINT64)1 << 0;

	constexpr UINT64 PIECE_F2 = 
		(UINT64)1 << 10 | (UINT64)1 << 9 | (UINT64)1 << 8 |
		(UINT64)1 << 2                   | (UINT64)1 << 0;

	constexpr UINT64 PIECE_F3 = 
		(UINT64)1 << 17 | (UINT64)1 << 16 |
		(UINT64)1 << 9  |
		(UINT64)1 << 1  | (UINT64)1 << 0;

	constexpr UINT64 PIECE_F4 = 
		(UINT64)1 << 17 | (UINT64)1 << 16 |
						  (UINT64)1 << 8  |
		(UINT64)1 << 1  | (UINT64)1 << 0;


	constexpr UINT64 PIECE_G1 = 
		(UINT64)1 << 18 | 
		(UINT64)1 << 10 | (UINT64)1 << 9 | (UINT64)1 << 8 | 
										   (UINT64)1 << 0;

	constexpr UINT64 PIECE_G2 = 
										   (UINT64)1 << 16 | 
		(UINT64)1 << 10 | (UINT64)1 << 9 | (UINT64)1 << 8 | 
		(UINT64)1 << 2;

	constexpr UINT64 PIECE_G3 = 
		(UINT64)1 << 18 | (UINT64)1 << 17 | 
						  (UINT64)1 << 9  | 
						  (UINT64)1 << 1  | (UINT64)1 << 0;

	constexpr UINT64 PIECE_G4 = 
						 (UINT64)1 << 17 | (UINT64)1 << 16 | 
						 (UINT64)1 << 9  | 
		(UINT64)1 << 2 | (UINT64)1 << 1;

	constexpr UINT64 PIECE_H1 = 
		(UINT64)1 << 10 | (UINT64)1 << 9 | (UINT64)1 << 8 |
						  (UINT64)1 << 1 | (UINT64)1 << 0;

	constexpr UINT64 PIECE_H2 = 
						 (UINT64)1 << 9 | (UINT64)1 << 8 |
		(UINT64)1 << 2 | (UINT64)1 << 1 | (UINT64)1 << 0;

	constexpr UINT64 PIECE_H3 = 
		(UINT64)1 << 10 | (UINT64)1 << 9 | (UINT64)1 << 8 |
		(UINT64)1 << 2  | (UINT64)1 << 1;

	constexpr UINT64 PIECE_H4 = 
		(UINT64)1 << 10 | (UINT64)1 << 9 |
		(UINT64)1 << 2  | (UINT64)1 << 1 | (UINT64)1 << 0;

	constexpr UINT64 PIECE_H5 = 
		(UINT64)1 << 17 | 
		(UINT64)1 << 9  | (UINT64)1 << 8 |
		(UINT64)1 << 1  | (UINT64)1 << 0;

	constexpr UINT64 PIECE_H6 = 
						  (UINT64)1 << 16 | 
		(UINT64)1 << 9  | (UINT64)1 << 8  |
		(UINT64)1 << 1  | (UINT64)1 << 0;

	constexpr UINT64 PIECE_H7 = 
		(UINT64)1 << 17 | (UINT64)1 << 16 |
		(UINT64)1 << 9  | (UINT64)1 << 8  |
						  (UINT64)1 << 0;

	constexpr UINT64 PIECE_H8 = 
		(UINT64)1 << 17 | (UINT64)1 << 16 |
		(UINT64)1 << 9  | (UINT64)1 << 8 |
		(UINT64)1 << 1;


	extern std::vector<UINT64> subpieces_A;
	extern std::vector<UINT64> subpieces_B;
	extern std::vector<UINT64> subpieces_C;
	extern std::vector<UINT64> subpieces_D;
	extern std::vector<UINT64> subpieces_E;
	extern std::vector<UINT64> subpieces_F;
	extern std::vector<UINT64> subpieces_G;
	extern std::vector<UINT64> subpieces_H;
	extern std::array<std::vector<UINT64>, 8> pieces;
	extern std::array<char, 8> codes;
}
#endif
