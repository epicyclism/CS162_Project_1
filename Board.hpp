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
public:
	char **board;
	Board(char** boardIn, int rowsIn, int columnsIn);
	int getRows();
	int getColumns();
	char getColor(int xCoord, int yCoord);
	void changeTile(int antXCoord, int antYCoord);
	~Board();
};

#endif
