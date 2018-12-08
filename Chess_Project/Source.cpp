/*
Authors:    Harel Katz,			Yuval Dahan
Emails:		harelka2@gmail.com,	yuvaldahn@gmail.com
*/
#include "Pipe.h"
#include "stdafx.h"
#include <thread>
#include "Board.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	srand(time_t(NULL));

	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return 0;
		}
	}
	

	char msgToGraphics[1024];
	const string START_MASSAGE = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1";
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, START_MASSAGE.c_str()); // just example...
	Board board(START_MASSAGE);
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		for(char i = Location::MIN_COL; i < Location::MIN_COL + 8; i++)
		{
			for(char j = Location::MIN_ROW; j < Location::MIN_ROW + 8; j++)
			{
				if(board[Location(i, j)] != nullptr)
				{
					cout << board[Location(i, j)]->get_type();
					if((board[Location(i, j)]->get_color() == WHITE))
						cout << "W ";
					else
						cout << "B ";
				}
				else
				{
					cout << "## ";
				}
			}
			cout << std::endl;
		}
		MoveResult result = board.move(Location(msgFromGraphics[0], msgFromGraphics[1]), Location(msgFromGraphics[2], msgFromGraphics[3]));
		

		strcpy_s(msgToGraphics, std::to_string(result).c_str()); // msgToGraphics should contain the result of the operation




		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}