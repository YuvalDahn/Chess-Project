#include "Pawn.h"

Pawn::Pawn(Side color): Piece(color)
{
	this->has_moved = false;
}

Pawn::~Pawn() {}

bool Pawn::is_valid_move(Location src, Location dst, Piece * board_arr[][8])
{
	int verctical_diff = dst.get_row() - src.get_row();		 //row desired move
	int horizontal_diff = dst.get_col() - src.get_col();	//col desired move
	if (this->get_color())
	{
		if (board_arr[dst.get_row()][dst.get_col()] == nullptr)//if you have nothing in the destination of the movement
		{
			if (!this->has_moved)//if the pawn moved already
			{
				has_moved = true;
				return 1 <= verctical_diff && verctical_diff <= 2 && horizontal_diff == 0; //checks if it moved 1 or 2 places in the first move

			}
			return verctical_diff == 1 && horizontal_diff == 0;
		}
		return abs(horizontal_diff) == 1 && verctical_diff == 1;
	}


	if (board_arr[dst.get_row()][dst.get_col()] == nullptr)//if you have nothing in the destination of the movement
	{
		if (!this->has_moved)//if the pawn moved already
		{
			has_moved = true;
			return -1 <= verctical_diff && verctical_diff <= -2 && horizontal_diff == 0; //checks if it moved 1 or 2 places in the first move

		}
		return verctical_diff == -1 && horizontal_diff == 0;
	}
	return abs(horizontal_diff) == 1 && verctical_diff == -1;
}
	

char Pawn::get_type()
{
	return 'p';
}


