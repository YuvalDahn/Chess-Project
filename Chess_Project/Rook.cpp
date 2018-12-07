#include "Rook.h"

Rook::Rook(Side color): Piece(color) {}

Rook::~Rook() {}

bool Rook::is_valid_move(Location src, Location dst, Piece* board_arr[][8])
{
	return Piece::moveStraight(src, dst, board_arr);
}
