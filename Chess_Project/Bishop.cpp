#include "Bishop.h"

Bishop::Bishop(Side color): Piece(color) {}

Bishop::~Bishop() {}

bool Bishop::is_valid_move(Location src, Location dst, Piece * board_arr[][8])
{
	return Piece::moveDiagonal(src, dst, board_arr);
}
