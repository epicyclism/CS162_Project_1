/************************************************************************************
** Header file for the Board class                                                  *
**                                                                                  *
** The board object will be created from the main program and will interact with the*
** ant object that will be created from the board class                             *
************************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
private:

	int rows,
		columns;
	char** board;
public:
	Board(int rowsIn, int columnsIn);
	int getRows() const;
	int getColumns() const;
	char getColor(int xCoord, int yCoord) const;
	void changeTile(int antXCoord, int antYCoord);
	~Board();
};

#endif
