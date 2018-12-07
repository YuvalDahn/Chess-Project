#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:
	Pawn(Side color);
	~Pawn();
	virtual bool is_valid_move(Location src, Location dst, Piece* board_arr[][8]);
};

