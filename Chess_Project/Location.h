/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/
#pragma once
#include <iostream>
#include "Board.h"

using std::string;

class Location
{
private:

	int _col;
	int _row;
	
	static const char MIN_ROW = '1';
	static const char MAX_ROW = '8';
	static const char MIN_COL = 'a';
	static const char MAX_COL = 'h';

public:

	Location(char col, char row);
	Location(int col, int row);
	~Location();
	int get_row();
	int get_col();
	void set_row(int row);
	void set_row(char row);
	void set_col(int col);
	void set_col(char col);
	//TODO: operator=

};
