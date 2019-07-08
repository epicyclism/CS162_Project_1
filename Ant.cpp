/************************************************************************************
** Source file for the Ant class                                                    *
**                                                                                  *
************************************************************************************/

#include <iostream>
#include "Ant.hpp"



Ant::Ant(Board* boardIn, int startingRow, int startingColumn)
{
	board = boardIn;
	antXCoord = startingRow;
	antYCoord = startingColumn;
	antDirection = north;

}

/************************************************************************************
* Accessor and mutator methods for the Ant class
*************************************************************************************/

int Ant::getRow() const
{
	return antXCoord;
}

int Ant::getColumn() const
{
	return antYCoord;
}

int Ant::getDirection() const
{
	return antDirection;
}

void Ant::setDirection(DIRECTION currentDir)
{
	antDirection = currentDir;
}
/************************************************************************************
* void Ant::manipulateAnt()
*
* Entry: Called from main() when the ant is ready to be moved around the board
*
* Exit:  After the turnAnt(), board->changeTile(antXCoord, antYCoord), moveAnt()
* and outOfBoundsCheck() are called
*
* Purpose: Controls four function calls the manipulate the ant's movement, turns and
* checks to see if the ant is out of bounds
*************************************************************************************/

void Ant::manipulateAnt()
{
	turnAnt();

	board->changeTile(antXCoord, antYCoord);

	moveAnt();

	outOfBoundsCheck();
}
/************************************************************************************
* void Ant::turnAnt()
*
* Entry: From void Ant::manipulateAnt()
*
* Exit:  After the ant's orientation is changed.  It will turn right if is on a white
* tile or turn left if it on a black tile.
*
* Purpose: Checks the tile color and rotates the ant accordingly to the conditions
*************************************************************************************/

void Ant::turnAnt()
{
	//Checks to see if the tile is white
	if (board->getColor(antXCoord, antYCoord) == ' ')
	{
		if (antDirection == north)
			antDirection = east;

		else if (antDirection == east)
			antDirection = south;

		else if (antDirection == south)
			antDirection = west;

		else if (antDirection == west)
			antDirection = north;
	}

	//The tile is black
	else
	{
		if (antDirection == north)
			antDirection = west;

		else if (antDirection == east)
			antDirection = north;

		else if (antDirection == south)
			antDirection = east;

		else if (antDirection == west)
			antDirection = south;
	}

}

/************************************************************************************
* void Ant::moveAnt()
*
* Entry: From void Ant::manipulateAnt()
*
* Exit:  After the ant moves forward, which is dictated by its orientation
*
* Purpose: Checks the orientation of the ant and moves it forward.
*************************************************************************************/
void Ant::moveAnt()
{
	if (antDirection == north)
		antYCoord--;

	else if (antDirection == east)
		antXCoord++;

	else if (antDirection == south)
		antYCoord++;

	else if (antDirection == west)
		antXCoord--;

}

/************************************************************************************
* void Ant::outOfBoundsCheck()
*
* Entry: From void Ant::manipulateAnt()
*
* Exit:  After it checks the ant's is outside the board
*
* Purpose: Checks to see if the ant is outside the board.  If it is, it is shifted
		   180 degrees and moved back into the board
*************************************************************************************/
void Ant::outOfBoundsCheck()
{

	int maxRow = board->getRows();
	int maxColumn = board->getColumns();

	if (antXCoord >= maxRow)
	{
		antDirection = west;
		antXCoord -= 2;
	}

	else if (antXCoord < 0)
	{
		antDirection = east;
		antXCoord += 2;
	}

	else if (antYCoord > maxColumn)
	{
		antDirection = north;
		antYCoord -= 2;
	}

	else if (antYCoord < 0)
	{
		antDirection = south;
		antYCoord += 2;
	}

}

Ant::~Ant()
{

}
