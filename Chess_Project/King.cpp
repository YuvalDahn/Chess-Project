#include "King.h"



King::King(Side color): Piece(color) {}


King::~King() {}

bool King::is_valid_move(Location src, Location dst, Piece * board_arr[][8])
{
	return false;
}
