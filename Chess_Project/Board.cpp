/*
Authors:	Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com, yuvaldahn@gmail.com
*/
#include "Board.h"

//ctor
Board::Board(const string init_board)
{
	int pos = 0;
	for(char i = Location::MAX_ROW; i >= Location::MIN_ROW; --i)		//reversed for because it starts in top row
	{
		for(char j = Location::MIN_COL; j <= Location::MAX_COL; ++j, ++pos)
		{
			(*this)[Location(j, i)] = get_piece(init_board[pos]);
			std::cout << "created Piece " << init_board[pos] << " in " << j << i << std::endl;
		}
	}
	this->_turn = (init_board[pos]) ? BLACK : WHITE;
}

/*
this function is checking all the senarios of a move
Input:  the src and the dst of the piece
Output: the result of the movement
*/
MoveResult Board::move(Location src, Location dst)
{
	Piece* p_src = (*this)[src];
	Piece* p_dst = (*this)[dst];
	if (p_src == nullptr)
	{
		return NO_PLAYER_TOOL_IN_SRC;
	}
	Side src_side = p_src->get_color();
	if(src_side != this->_turn)
	{
		return NO_PLAYER_TOOL_IN_SRC;
	}

	if(p_dst != nullptr && p_dst->get_color() == src_side)
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

	delete temp;
	this->_turn = (Side)!this->_turn;
	if (is_check(src, dst, (Side)!src_side))
	{
		return CHESS_MOVE;
	}

	return GOOD_MOVE;
}

/*
this function is checking if a check was made
Input:  the dst and the src of the move ,and which side if the piece in
Output: if there is a check or not
*/
bool Board::is_check(Location src, Location dst, Side side)
{
	Location king = this->get_king(side);
	for (char i = Location::MIN_ROW; i <= Location::MAX_ROW; ++i)
	{
		for (char j = Location::MIN_COL; j <= Location::MAX_COL; ++j)
		{
			Location loc(j, i);
			if ((*this)[loc] != nullptr && side != (*this)[loc]->get_color())
			{
				if((*this)[loc]->is_valid_move(loc, king, this->_board_arr))
				{
					return true;
				}
			}
		}
	}
	return false;
}

/*
this function is creating a piece for the board
Input:  which piece is it 
Output: the location of the piece in the memory
*/
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

//operators
Piece *& Board::operator[](Location loc)
{
	return this->_board_arr[loc.get_row()][loc.get_col()];
}

const Piece *& Board::operator[](Location loc) const
{
	return (const Piece *&) this->_board_arr[loc.get_row()][loc.get_col()];
}

/*
this function is getting the location of the black king or the white king
Input:  which color of a king we are searching for
Output: his location
*/
Location Board::get_king(Side side)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (this->_board_arr[i][j] != nullptr && side == this->_board_arr[i][j]->get_color() && this->_board_arr[i][j]->get_type() == 'k')
			{
				return Location(j + Location::MIN_COL, i + Location::MIN_ROW);
			}
		}
	}
	return Location('a','1');
}

