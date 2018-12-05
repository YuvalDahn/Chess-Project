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
