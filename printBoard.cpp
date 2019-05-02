/************************************************************************************
** Source file for the printBoard.hpp                                               *
**                                                                                  *
** Prints the board to user                                                         *
************************************************************************************/

#include <iostream>
#include "printBoard.hpp"

using std::cout;
using std::endl;


/*************************************************************************************
* void printBoard(Board *b, int boardRows, int boardColumns, Ant a)
*
* Entry: Called from main();
*
* Exit:  After the board is succesfullly printed to the screen
*
* Purpose: Print the board to the screen and print the location of the ant
*************************************************************************************/
void printBoard(Board *b, int boardRows, int boardColumns, Ant a)
{
	int antXCoord = a.getRow();
	int antYCoord = a.getColumn();

	//Cited from Pizazza Post: Board design ideas Date: 04/08/2019, Author: Annonymous

	//Print top board of the board
	for (int topBorder = 0; topBorder < boardColumns + 2; topBorder++)
		cout << "-";

	cout << endl;

	//Print left edges of the board
	for (int i = 0; i < boardRows; i++)
	{
		cout << "|";

		for (int j = 0; j < boardColumns; j++)
		{
			//Print the white space
			char space = ' ';

			//Print the location of the ant
			if (i == antXCoord && j == antYCoord)
			{ 
				space = '*';
			}
			
			//If tile isn't white, it is black, so print this to the screen
			else if (b->board[i][j] == '#')
			{ 
				space = '#';
			}
			cout << space;
		}
			
		//Print right border
		cout << "|";
		cout << endl;
	}

	//Print bottom border
	for (int bottomBorder = 0; bottomBorder < boardColumns + 2; bottomBorder++)
		cout << "-";
	cout << endl;

}