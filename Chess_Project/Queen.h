/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/
#pragma once

#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(Side color);
	~Queen();
	virtual bool is_valid_move(Location src, Location dst, Piece* board_arr[][8]);
};

