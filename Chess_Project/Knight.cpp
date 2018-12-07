/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/
#include "Knight.h"

Knight::Knight(Side color): Piece(color) {}


Knight::~Knight() {}

bool Knight::is_valid_move(Location src, Location dst, Piece * board_arr[][8])
{
	int verctical_diff = dst.get_row() - src.get_row();					//row desired move
	int horizontal_diff = dst.get_col() - src.get_col();				//col desired move
	return abs(horizontal_diff) == 2 && abs(verctical_diff) == 1 ||		//check if src and dst are a legal Knight move
		   abs(horizontal_diff) == 1 && abs(verctical_diff) == 2;
}
