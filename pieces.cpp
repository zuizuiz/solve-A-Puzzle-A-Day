#include "pieces.h"

std::vector<UINT64> SUBPIECES_A { PIECE_A1, PIECE_A2, PIECE_A3, PIECE_A4};
std::vector<UINT64> SUBPIECES_B { PIECE_B1, PIECE_B2};
std::vector<UINT64> SUBPIECES_C { PIECE_C1, PIECE_C2, PIECE_C3, PIECE_C4, PIECE_C5, PIECE_C6, PIECE_C7, PIECE_C8};
std::vector<UINT64> SUBPIECES_D { PIECE_D1, PIECE_D2, PIECE_D3, PIECE_D4, PIECE_D5, PIECE_D6, PIECE_D7, PIECE_D8};
std::vector<UINT64> SUBPIECES_E { PIECE_E1, PIECE_E2, PIECE_E3, PIECE_E4, PIECE_E5, PIECE_E6, PIECE_E7, PIECE_E8};
std::vector<UINT64> SUBPIECES_F { PIECE_F1, PIECE_F2, PIECE_F3, PIECE_F4};
std::vector<UINT64> SUBPIECES_G { PIECE_G1, PIECE_G2, PIECE_G3, PIECE_G4};
std::vector<UINT64> SUBPIECES_H { PIECE_H1, PIECE_H2, PIECE_H3, PIECE_H4, PIECE_H5, PIECE_H6, PIECE_H7, PIECE_H8};
std::array<std::vector<UINT64>, 8> PIECES = { SUBPIECES_A, SUBPIECES_B, SUBPIECES_C, SUBPIECES_D, SUBPIECES_E, SUBPIECES_F, SUBPIECES_G, SUBPIECES_H};
std::array<char, 8> codes = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
