#pragma once
#include <iostream>
#include "Piece.h"
#include "Board.h"

using std::string;

class Location
{
private:
	int _col;
	int _row;
public:
	Location(char col, char row);
	Location(string loc);
	~Location();
	int get_row();
	int get_col();
	void set_row(int row);
	void set_row(char row);
	void set_col(int col);
	void set_col(char col);
};
