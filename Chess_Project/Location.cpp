#include "Location.h"

Location::Location(char col, char row)
{
	this->set_col(col);
	this->set_row(row);
}

Location::Location(int col, int row)
{
	this->set_col(col);
	this->set_row(row);
}

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
	this->set_row(row + this->MIN_ROW);
}

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

void Location::set_col(int col)
{
	this->set_row(col + this->MIN_COL);
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
