/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/
#include "Location.h"

//ctpr
Location::Location(char col, char row)
{
	this->set_col(col);
	this->set_row(row);
}

//dtor
Location::~Location() {}

//getters
int Location::get_row()
{
	return this->_col;
}

int Location::get_col()
{
	return this->_row;
}

//setters
void Location::set_row(char row)
{
	if(row >= this->MIN_ROW && row <= this->MAX_ROW)
	{
		this->_row = row - this->MIN_ROW;
	}
	else
	{
		throw ILLEGAL_INDEX;
	}
}

void Location::set_col(char col)
{
	if(col >= this->MIN_COL && col <= this->MAX_COL)
	{
		this->_col = col - this->MIN_COL;
	}
	else
	{
		throw ILLEGAL_INDEX;
	}
}
