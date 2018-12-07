/*
Authors:	Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com, yuvaldahn@gmail.com  
*/
#pragma once
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

enum MoveResult
{
	GOOD_MOV,
	CHESS_MOVE,
	NO_PLAYER_TOOL_IN_SRC,
	PLAYER_TOOL_IN_TRGT,
	SELF_CHESS_MOVE,
	ILLEGAL_INDEX,
	ILLEGAL_TOOL_MOVE,
	SRC_AND_TRGT_SAME,
	MATE_MOVE
};

class Board
{

protected:

	Piece* _board_arr[8][8];
	Side _turn;

public:

	Board(string );
	void move(Location src, Location dst);
	bool is_check(bool _side);
	Piece* get_piece(char p);
	Piece* operator[](string loc);
	Piece* operator[](Location loc);

};
