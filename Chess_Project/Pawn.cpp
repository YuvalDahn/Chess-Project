#include "Pawn.h"



Pawn::Pawn(Side color): Piece(color) {}


Pawn::~Pawn() {}

bool Pawn::is_valid_move(Location src, Location dst, Piece * board_arr[][8])
{
	return false;
}
