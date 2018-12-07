#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(Side color);
	~Rook();
	virtual bool is_valid_move(Location src, Location dst, Piece* board_arr[][8]);
};

