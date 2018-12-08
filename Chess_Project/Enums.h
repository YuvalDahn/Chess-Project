/*
Authors:	Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com, yuvaldahn@gmail.com
*/
#pragma once

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

enum Side : bool
{
	WHITE = true,
	BLACK = false
};
