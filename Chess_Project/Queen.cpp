#include "Queen.h"

Queen::Queen(Side color): Piece(color) {}

Queen::~Queen() {}

bool Queen::is_valid_move(Location src, Location dst, Piece * board_arr[][8])
{
	return Piece::moveStraight(src, dst, board_arr) || Piece::moveDiagonal(src, dst, board_arr);
}
