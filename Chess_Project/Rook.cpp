/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/
#include "Rook.h"

//ctor
Rook::Rook(Side color): Piece(color) {}

//dtor
Rook::~Rook() {}

/*
this function is checking if the move of the rook is valid
Input:  its src, dst, and the board
Output: if the move is valid
*/
bool Rook::is_valid_move(Location src, Location dst, Piece* board_arr[][8])
{
	return Piece::moveStraight(src, dst, board_arr);
}

//getter
char Rook::get_type()
{
	return 'r';
}
