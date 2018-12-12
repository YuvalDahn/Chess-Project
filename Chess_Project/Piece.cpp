/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/
#include "Piece.h"

//ctor
Piece::Piece(Side color)
{
	this->_color = color;
}

//dtor
Piece::~Piece() {}

//getter
Side Piece::get_color()
{
	return this->_color;
}

/*
this function is moving the piece straight and checks if there is something in her way
Input:  the src, dst of the piece anf the board
Output: if it can be moved straight
*/
bool Piece::moveStraight(Location src, Location dst, Piece* board_arr[][8])
{
		int i = src.get_row(), j = src.get_col();
		if(src.get_col() == dst.get_col())
		{
			int move_by = 1;
			if(src.get_row() > dst.get_row())
			{
				move_by = -1;
			}
			for(i = src.get_row() + move_by; i != dst.get_row(); i += move_by)
			{
				if(board_arr[i][j] != nullptr)						//if there is something on the way, it is not a valid move
				{
					return false;
				}
			}
			return true;
		}
		else if(src.get_row() == dst.get_row())
		{
			int move_by = 1;
			if(src.get_col() > dst.get_col())
			{
				move_by = -1;
			}
			for(j = src.get_col() + move_by; j != dst.get_col(); j += move_by)
			{
				if(board_arr[i][j] != nullptr)								//if there is something on the way, it is not a valid move
				{
					return false;
				}
			}
			return true;
		}
	return false;
}


/*
this function is moving the piece diagonaly and checks if there is something in her way
Input:  the src, dst of the piece anf the board
Output: if it can be moved straight
*/
bool Piece::moveDiagonal(Location src, Location dst, Piece* board_arr[][8])
{
	int vertical_diff = dst.get_row() - src.get_row();					//row desired move
	int horizontal_diff = dst.get_col() - src.get_col();				//col desired move
	if(abs(horizontal_diff) == abs(vertical_diff))						//check if src and dst are in diagonal line
	{
		int vert_direction = 0, horiz_direction = 0;
		if(vertical_diff > 0)
		{
			vert_direction = 1;
		}
		else
		{
			vert_direction = -1;
		}
		if(horizontal_diff > 0)
		{
			horiz_direction = 1;
		}
		else
		{
			horiz_direction = -1;
		}
		for(int i = src.get_row() + vert_direction, j = src.get_col() + horiz_direction; i != dst.get_row() && j != dst.get_col(); i += vert_direction, j += horiz_direction)
		{
			if(board_arr[i][j] != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
