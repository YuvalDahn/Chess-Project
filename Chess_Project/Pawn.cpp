#include "Pawn.h"

Pawn::Pawn(Side color): Piece(color)
{
	this->has_moved = false;
}

Pawn::~Pawn() {}

bool Pawn::is_valid_move(Location src, Location dst, Piece * board_arr[][8])
{
	int verctical_diff = dst.get_row() - src.get_row();
	if (!this->has_moved)
	{
		has_moved = true;
		return (1 <= verctical_diff && verctical_diff <= 2);
	}
	return verctical_diff == 1;
}

char Pawn::get_type()
{
	return 'p';
}


