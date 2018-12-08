#pragma once
#include <iostream>
#include "Piece.h"

class Pawn : public Piece
{
private:

	bool has_moved;

public:

	Pawn(Side color);
	~Pawn();
	virtual bool is_valid_move(Location src, Location dst, Piece* board_arr[][8]);
	virtual char get_type();
};

