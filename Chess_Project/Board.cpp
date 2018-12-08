/*
Authors:	Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com, yuvaldahn@gmail.com
*/
#include "Board.h"

Board::Board(const string init_board)
{
	int pos = 0;
	for(char i = Location::MAX_COL; i >= Location::MIN_COL; --i)
	{
		for(char j = Location::MAX_ROW; j >= Location::MIN_ROW; --j, ++pos)
		{
			(*this)[Location(i, j)] = get_piece(init_board[pos]);
		}
	}
	this->_turn = (init_board[pos]) ? BLACK : WHITE;
}

MoveResult Board::move(Location src, Location dst)
{
	Piece* p_src = (*this)[src];
	Piece* p_dst = (*this)[dst];
	if (p_src == nullptr)
	{
		return NO_PLAYER_TOOL_IN_SRC;
	}
	Side src_side = p_src->get_color();
	Side dst_side = (src_side == WHITE)? BLACK: WHITE;
	if(p_dst != nullptr)
	{
		dst_side = p_dst->get_color();
	}
	else if (dst_side == src_side)
	{
		return PLAYER_TOOL_IN_DST;
	}
	else if (p_src == p_dst)
	{
		return SRC_AND_DST_SAME;
	}

	if (!p_src->is_valid_move(src, dst, this->_board_arr))
	{
		return ILLEGAL_TOOL_MOVE;
	}

	Piece* temp = (*this)[dst];
	(*this)[dst] = (*this)[src];
	(*this)[src] = nullptr;

	if (is_check(src, dst, src_side))
	{
		(*this)[src] = (*this)[dst];
		(*this)[dst] = temp;
		return SELF_CHESS_MOVE;
	}
	else if (is_check(src, dst, dst_side))
	{
		return CHESS_MOVE;
	}

	return GOOD_MOVE;
}

bool Board::is_check(Location src, Location dst, Side side)
{
	Location king = this->get_king(side);
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (side != this->_board_arr[i][j]->get_color())
			{
				try
				{
					this->_board_arr[i][j]->is_valid_move(Location(i, j), king, this->_board_arr);
					return true;
				}
				catch (...) {}
			}
		}
	}
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
		return new King(side);
		break;
	case 'Q':
		return new Queen(side);
		break;
	case 'R':
		return new Rook(side);
		break;
	case 'N':
		return new Knight(side);
		break;
	case 'B':
		return new Bishop(side);
		break;
	case 'P':
		return new Pawn(side);
		break;
	case '#':
		return nullptr;
	}
	return nullptr;
}

Piece *& Board::operator[](Location loc)
{
	return this->_board_arr[loc.get_row()][loc.get_col()];
}

const Piece *& Board::operator[](Location loc) const
{
	return (const Piece *&) this->_board_arr[loc.get_row()][loc.get_col()];
}

Location Board::get_king(Side side)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (this->_board_arr[i][j] != nullptr && side == this->_board_arr[i][j]->get_color() && this->_board_arr[i][j]->get_type() == 'k')
			{
				return Location(i, j);
			}
		}
	}
}

