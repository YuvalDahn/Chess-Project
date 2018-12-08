/*
Authors:	Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com, yuvaldahn@gmail.com
*/
#pragma once
#include <iostream>
#include "Piece.h"

class King : public Piece
{
public:

	King(Side color);
	~King();
	virtual bool is_valid_move(Location src, Location dst, Piece* board_arr[][8]);
	virtual char get_type();
};

