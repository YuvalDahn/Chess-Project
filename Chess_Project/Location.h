#pragma once
#include <iostream>
#include "Piece.h"

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
};
