#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(Side color);
	~King();
	virtual bool is_valid_move(Location src, Location dst, Piece* board_arr[][8]);
};

