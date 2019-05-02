/************************************************************************************
** Source file for the Board class                                                  *
**                                                                                  *
************************************************************************************/

#include <iostream>
#include "Board.hpp"

using std::cout;
using std::endl;

/************************************************************************************
*Board::Board(char** boardIn, int rowsIn, int columnsIn)
*
* Entry: When a board object is created from main
*
* Exit:  When the constructor assigns all the variables
*
* Purpose: Constructor to initalize the variables when an board object is created
*************************************************************************************/
Board::Board(char** boardIn, int rowsIn, int columnsIn)
{
	board = boardIn;
	rows = rowsIn;
	columns = columnsIn;

}

/************************************************************************************
* Accessor and mutator methods for the Board class
*************************************************************************************/
int Board::getRows()
{
	return rows;
}

int Board::getColumns()
{
	return columns;

}
char Board::getColor(int xCoord, int yCoord)
{
	return board[xCoord][yCoord];
}

/************************************************************************************
* void Board::changeTile(int xCoord, int yCoord)
*
* Entry: Called from void Ant::manipulateAnt();
*
* Exit:  After the if/else statement executes
*
* Purpose: Checks to see if the tile is white ('_'). If so, it changes to it to black
           ('#')
*************************************************************************************/
void Board::changeTile(int xCoord, int yCoord)
{

	char currentTile = getColor(xCoord, yCoord);

	if (currentTile == ' ')
		board[xCoord][yCoord] = '#';

	else
		board[xCoord][yCoord] = ' ';
}

Board::~Board()
{

}

