/*
Authors:	Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com, yuvaldahn@gmail.com
*/
#include "Board.h"

Board::Board(string init_board)
{
	int pos = 0;
	for (int i = 0; i < 8; ++i, ++pos)
	{
		for (int j = 0; j < 8; ++j, ++pos)
		{
			this->_board_arr[i][j] = get_piece(init_board[pos]);
		}
	}
	this->_turn = (init_board[pos]) ? BLACK : WHITE;
}

void Board::move(Location src, Location dst)
{
	Piece* piece = _board_arr[src.get_row()][src.get_col()];
	if (piece == nullptr)
	{
		throw NO_PLAYER_TOOL_IN_SRC;
	}
	piece->is_valid_move(src, dst, this->_board_arr);
	//the movment delet src,
}

bool Board::is_check(bool _side)
{
	return false;
}

Piece * Board::get_piece(char p)
{
	Side side = WHITE;
	if (p > 'Z')
	{
		side = BLACK;
		p = p - 'a' + 'A';
	}
	switch (p)
	{
	case 'K':
		return King(side);
		break;
	case 'Q':
		return Queen(side);
		break;
	case 'R':
		return Rook(side);
		break;
	case 'N':
		return Knight(side);
		break;
	case 'B':
		return Bishop(side);
		break;
	case 'P':
		return Pawn(side);
		break;
	case '#':
		return nullptr;
	}
}
