#include "Location.h"

Location::Location(char col, char row)
{
	if(col >= 'a' && col <= 'z' && row >= '0' && row <= '9')
	{
		this->_col = col - 'a';
		this->_row = row - '0';
	}
	else
	{
		throw ILLEGAL_INDEX;
	}
}

Location::Location(string loc): Location(loc[0], loc[1]) {}

Location::~Location() {}

int Location::get_row()
{
	return this->_col;
}

int Location::get_col()
{
	return this->_row;
}

void Location::set_row(int row)
{
	if(row >= 0 && row <= 9)
	{
		this->_row = row - '0';
	}
	else
	{
		throw ILLEGAL_INDEX;
	}
}

void Location::set_row(char row)
{
	if(row >= '0' && row <= '9')
	{
		this->_row = row - '0';
	}
	else
	{
		throw ILLEGAL_INDEX;
	}
}

void Location::set_col(int col)
{
	if(col >= 0 && col <= 'z' - 'a')
	{
		this->_col = col - 'a';
	}
	else
	{
		throw ILLEGAL_INDEX;
	}
}

void Location::set_col(char col)
{
	if(col >= 'a' && col <= 'z')
	{
		this->_col = col - 'a';
	}
	else
	{
		throw ILLEGAL_INDEX;
	}
}
