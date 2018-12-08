/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/
#include "Queen.h"

//ctor
Queen::Queen(Side color): Piece(color) {}

//dtor
Queen::~Queen() {}

/*
this function is checking if the move of the queen is valid
Input:  its src, dst, and the board
Output: if the move is valid
*/
bool Queen::is_valid_move(Location src, Location dst, Piece * board_arr[][8])
{
	return Piece::moveStraight(src, dst, board_arr) || Piece::moveDiagonal(src, dst, board_arr);
}

//getter
char Queen::get_type()
{
	return 'q';
}
