/************************************************************************************
** Header file for the Ant class                                                    *
**                                                                                  *
** The ant object will be created from the main program and will interact with the  *
** board object that will be created from the board class                           *
************************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Board.hpp"

class Ant
{
	//Create an enum to help with the ant's orientation
	enum DIRECTION { north, east, south, west };

private:

	DIRECTION antDirection;
	int antXCoord,
		antYCoord;

public:
	Board* board;
	Ant(Board* boardIn, int startingRow, int startingColumn);
	int getRow() const;
	int getColumn() const;
	int getDirection() const;
	void setDirection(DIRECTION currentDirection);
	void manipulateAnt();
	void turnAnt();
	void moveAnt();
	void outOfBoundsCheck();
	~Ant();
};

#endif

