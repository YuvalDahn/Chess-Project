#pragma once
/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/

#include "Location.h"

enum Side
{
	WHITE,
	BLACK
};

class Piece
{
private:
	Side _color;
public:
	//Piece(Side color) = 0;
	virtual ~Piece();
	virtual bool is_valid_move(Location src, Location dst, Piece*(*)[8]) = 0;
	static bool moveStraight(Location src, Location dst);
	static bool moveDiagonal(Location src, Location dst);
};
