#pragma once
/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/

#include "Location.h"

enum Side : bool
{
	WHITE = true,
	BLACK = false
};

class Piece
{
protected:
	Side _color;

	static bool moveStraight(Location src, Location dst, Piece* board_arr[][8]);
	static bool moveDiagonal(Location src, Location dst, Piece* board_arr[][8]);
public:
	Piece(Side color);
	virtual ~Piece();
	virtual bool is_valid_move(Location src, Location dst, Piece* board_arr[][8]) = 0;
	virtual Side get_color();
};
