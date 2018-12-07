#include "Pawn.h"

Pawn::Pawn(Side color): Piece(color)
{
	this->has_moved = false;
}

Pawn::~Pawn() {}

bool Pawn::is_valid_move(Location src, Location dst, Piece * board_arr[][8])
{
	int verctical_diff = dst.get_row() - src.get_row();
	int horizontal_diff = dst.get_col() - src.get_col();
	if (board_arr[dst.get_row()][dst.get_col()] == nullptr)
	{
		if (!this->has_moved)
		{
			has_moved = true;
			return (1 <= verctical_diff && verctical_diff <= 2);

		}
		return verctical_diff == 1;
	}
	return abs(horizontal_diff) == 1 && abs(verctical_diff) == 1;
}
	

char Pawn::get_type()
{
	return 'p';
}


