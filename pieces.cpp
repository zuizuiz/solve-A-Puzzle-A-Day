#include "pieces.h"

using namespace pieces;

std::vector<UINT64> pieces::subpieces_A { PIECE_A1, PIECE_A2, PIECE_A3, PIECE_A4};
std::vector<UINT64> pieces::subpieces_B { PIECE_B1, PIECE_B2};
std::vector<UINT64> pieces::subpieces_C { PIECE_C1, PIECE_C2, PIECE_C3, PIECE_C4, PIECE_C5, PIECE_C6, PIECE_C7, PIECE_C8};
std::vector<UINT64> pieces::subpieces_D { PIECE_D1, PIECE_D2, PIECE_D3, PIECE_D4, PIECE_D5, PIECE_D6, PIECE_D7, PIECE_D8};
std::vector<UINT64> pieces::subpieces_E { PIECE_E1, PIECE_E2, PIECE_E3, PIECE_E4, PIECE_E5, PIECE_E6, PIECE_E7, PIECE_E8};
std::vector<UINT64> pieces::subpieces_F { PIECE_F1, PIECE_F2, PIECE_F3, PIECE_F4};
std::vector<UINT64> pieces::subpieces_G { PIECE_G1, PIECE_G2, PIECE_G3, PIECE_G4};
std::vector<UINT64> pieces::subpieces_H { PIECE_H1, PIECE_H2, PIECE_H3, PIECE_H4, PIECE_H5, PIECE_H6, PIECE_H7, PIECE_H8};
std::array<std::vector<UINT64>, 8> pieces::pieces = { subpieces_A, subpieces_B, subpieces_C, subpieces_D, subpieces_E, subpieces_F, subpieces_G, subpieces_H};
std::array<char, 8> pieces::codes = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
