/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/
#include "Piece.h"

Piece::Piece(Side color)
{
	this->_color = color;
}

Piece::~Piece() {}

Side Piece::get_color()
{
	return this->_color;
}

bool Piece::moveStraight(Location src, Location dst, Piece* board_arr[][8])
{
	if(src.get_col() == dst.get_col() || src.get_row() == dst.get_row())	//check if src and dst are in straight line
	{
		for(size_t i = src.get_row(); i < dst.get_row(); i++)				//check if there's something in the way
		{
			for(size_t j = src.get_col(); j < dst.get_col(); j++)
			{
				if(board_arr[i][j] != nullptr)								//if there is something on the way, it is not a valid move
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

bool Piece::moveDiagonal(Location src, Location dst, Piece* board_arr[][8])
{
	int verctical_diff = dst.get_row() - src.get_row();					//row desired move
	int horizontal_diff = dst.get_col() - src.get_col();				//col desired move
	if(abs(horizontal_diff) == abs(verctical_diff));					//check if src and dst are in diagonal line
	{
		(horizontal_diff > 0) ? horizontal_diff-- : horizontal_diff++;	//increases/decreases according to positivity
		(verctical_diff > 0) ? verctical_diff-- : verctical_diff++;
		while(horizontal_diff != 0 && verctical_diff != 0)				//goes over all the cells in the way between src and dst
		{
			//if there is something on the way, it is not a valid move
			if(board_arr[dst.get_row() + horizontal_diff][dst.get_col() + verctical_diff] != nullptr)
			{
				return false;
			}
			(horizontal_diff > 0) ? horizontal_diff-- : horizontal_diff++;	//increases/decreases according to positivity
			(verctical_diff > 0) ? verctical_diff-- : verctical_diff++;
		}
		return true;
	}
	return false;
}
