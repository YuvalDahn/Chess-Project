#pragma once
/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/

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
	virtual bool is_valid_move(Location src, Location dst, Piece* **) = 0;
};
