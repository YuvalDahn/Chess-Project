/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/
#include "King.h"

//ctor
King::King(Side color): Piece(color) {}

//dtro
King::~King() {}

/*
this function is checking if the move of the king is valid
Input:  its src, dst, and the board
Output: if the move is valid
*/
bool King::is_valid_move(Location src, Location dst, Piece * board_arr[][8])
{
	int verctical_diff = dst.get_row() - src.get_row();				  //row desired move
	int horizontal_diff = dst.get_col() - src.get_col();			 //col desired move
	return abs(verctical_diff) <= 1 && abs(horizontal_diff) <= 1;	//check if src and dst are a legal Knight move
}

//getter
char King::get_type()
{
	return 'k';
}
