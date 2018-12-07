#include "King.h"

King::King(Side color): Piece(color) {}

King::~King() {}

bool King::is_valid_move(Location src, Location dst, Piece * board_arr[][8])
{
	int verctical_diff = dst.get_row() - src.get_row();				  //row desired move
	int horizontal_diff = dst.get_col() - src.get_col();			 //col desired move
	return abs(verctical_diff) <= 1 && abs(horizontal_diff) <= 1;	//check if src and dst are a legal Knight move
}

char King::get_type()
{
	return 'k';
}
