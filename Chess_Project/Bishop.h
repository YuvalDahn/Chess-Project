#pragma once
/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/

#include "Piece.h"

class Bishop :
	public Piece
{
public:
	Bishop(Side color);
	~Bishop();
	virtual bool is_valid_move(Location src, Location dst, Piece* board_arr[][8]);
};

