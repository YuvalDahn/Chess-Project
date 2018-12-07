/*
Authors:	Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com, yuvaldahn@gmail.com  
*/
#pragma once
#include "stdafx.h"
#include "Piece.h"
#include "Location.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"

class Board
{

protected:

	Piece* _board_arr[8][8];
	Side _turn;

public:

	Board(string );
	MoveResult move(Location src, Location dst);
	bool is_check(Location src, Location dst, Side side);
	Piece* get_piece(char p);
	Piece*& operator[](Location loc);
	const Piece*& operator[](Location loc) const;
	Location get_king(Side side);	//TODO
};
