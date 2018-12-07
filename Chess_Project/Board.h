/*
Authors:	Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com, yuvaldahn@gmail.com  
*/
#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "Piece.h"
#include "Location.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"

using std::string;
using std::int;

enum MoveResult
{
	GOOD_MOVE,
	CHESS_MOVE,
	NO_PLAYER_TOOL_IN_SRC,
	PLAYER_TOOL_IN_DST,
	SELF_CHESS_MOVE,
	ILLEGAL_INDEX,
	ILLEGAL_TOOL_MOVE,
	SRC_AND_DST_SAME,
	MATE_MOVE
};

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
