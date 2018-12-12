/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/
#include "Pawn.h"

//ctoe
Pawn::Pawn(Side color): Piece(color)
{
	this->has_moved = false;
}

//dtor
Pawn::~Pawn() {}

/*
this function is checking if the move of the rook is valid
Input:  its src, dst, and the board
Output: if the move is valid
*/
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
		if (abs(horizontal_diff) == 1 && verctical_diff == 1)
		{
			this->has_moved = true;
			return true;
		}
		return false;
	}


	if (board_arr[dst.get_row()][dst.get_col()] == nullptr)	//if you have nothing in the destination of the movement
	{
		if (!this->has_moved)	//if the pawn didn't moved
		{
			this->has_moved = true;
			return -1 >= verctical_diff && verctical_diff >= -2 && horizontal_diff == 0; //checks if it moved 1 or 2 places in the first move

		}
		return verctical_diff == -1 && horizontal_diff == 0;
	}
	if (abs(horizontal_diff) == 1 && verctical_diff == -1)
	{
		this->has_moved = true;
		return true;
	}
	return false;
}
	
//getter
char Pawn::get_type()
{
	return 'p';
}