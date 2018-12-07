#include "Piece.h"

Piece::~Piece() {}

Side Piece::get_color()
{
	return this->_color;
}

bool Piece::moveStraight(Location src, Location dst)
{
	return src.get_col() == dst.get_col() || src.get_row() == dst.get_row();
}

bool Piece::moveDiagonal(Location src, Location dst)
{
	return src.get_col() - dst.get_col() == src.get_row() - dst.get_row() ||
		-1 * (src.get_col() - dst.get_col()) == src.get_row() - dst.get_row();
}
