#pragma once
/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/

#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(Side color);
	~Rook();
	virtual bool is_valid_move(Location src, Location dst, Piece* board_arr[][8]);
};

