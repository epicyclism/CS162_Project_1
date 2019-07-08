/************************************************************************************
** Name: Kurt Kuhn                                                                  *
**                                                                                  *
** Date: April 14, 2019                                                             *
**                                                                                  *
** Purpose: This program recreates Langton's Ant, which is essentially a 2D         *
** universal turing machine.  It follows a simple logical process. The ant is       *
** placed on the board, if the tile it is on is white, rotates itself 90 degrees    *
** to right and moves forward.  If the tile is black, it rotates itself 90 degres   *
** to the left and moves forward.  In this simulation, a blank space (' ') is noted *
** as white and # is noted as black                                                 *
**                                                                                  *
** This is the driver file for Project 1 - Langton's Ant                            *
************************************************************************************/

#include <iostream>
#include "menu.hpp"
#include "inputValidation.hpp"
#include "Board.hpp"
#include "Ant.hpp"
#include "printBoard.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::cin;

int main()
{
	//Variables used for accquired from the user
	int rows,
		columns,
		steps,
		startingRow,
		startingColumn;

	int userChoice = menu();

	while (userChoice == 1)
	{
		menu(rows, columns, steps, startingRow, startingColumn);

		//Create the board and ant objects

		//Create new board object
		Board board(rows, columns);

		//Create new ant object
		Ant ant(&board, startingRow, startingColumn);

		//Make the ant move!
		for (int step = 0; step < steps; ++step)
		{
			ant.manipulateAnt();

			printBoard(board, ant);

			cout << "This is step: " << step << endl;
		}

		userChoice = menu();
	}

	//Ask the uesr if they wish to play again
	if (userChoice == 2)
		cout << "Farewell! Thanks for playing. " << endl;
}