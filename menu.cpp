/************************************************************************************
** Source file for the main.hpp                                                     *
**                                                                                  *                                           *
************************************************************************************/

#include <iostream>
#include <cstdlib>
#include "inputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;

/************************************************************************************
* void menu()
*
* Entry: Called from main()
*
* Exit:  After asking the user for all their input and validating it
*
* Purpose: Ask the user if they want to continue with the program, or simply quit. 
*************************************************************************************/

int menu()
{
	int userInput;
	int menuMax = 2;

	cout << "\nWelcome to Langton's Ant!" << endl;
	cout << "Version: Seeking That Extra Credit. Now With Random Ant Placement! " << endl;
	cout << "\nPlease select one of the following options:" << endl;
	cout << "\t1. Start Langton's Ant Program " << endl;
	cout << "\t2. Quit the program" << endl;

	//Call the inpuValidation(menuMax) to check if this is a valid input
	userInput = inputValidation(menuMax);
	
	return userInput;

}

/*************************************************************************************
* void menu(int &rows, int &columns, int &steps, int &startingRow, int &startingColumn)
*
* Entry: Called from main()
*
* Exit:  After asking the user for all their input and validating it
*
* Purpose: Ask the user for number of rows they want to board to have.  The number of 
*          steps the ant will take. As well as the starting location of the ant, it
           either rbeing using selected or randomly generated
		   
		   Note: the variables are passed by reference, because they need the values
		   need to be given back to main() for use
*************************************************************************************/

void menu(int &rows, int &columns, int &steps, int &startingRow, int &startingColumn)
{

	int userInput;
	int menuMax = 2;

	//Ask user to enter the number of rows, columns and steps the ant to take and validate the input

	cout << "\nPlease enter the number of rows you wish the board to have." << endl;
	rows = inputValidation();

	cout << "\nPlease enter the number of columns you wish the board to have." << endl;
	columns = inputValidation();

	cout << "\nPlease enter the number of steps you want the ant to take." << endl;
	steps = inputValidation();

	//Ask the user if they want to select their own starting location of the ant, or have it be randomly selected
	cout << "\nWould you like to pick the starting location of the ant or have it randomly generated? " << endl;
	cout << "\t1. Select my own starting location " << endl;
	cout << "\t2. Let the ant's starting location be random" << endl;
	userInput = inputValidation(menuMax);
	
	//User selects their own starting location
	if (userInput == 1)
	{
		cout << "\nWhat row you wish the ant to to start on. " << endl;
		startingRow = inputValidation(rows);

		cout << "\nWhat column you wish the ant to to start on. " << endl;
		startingColumn = inputValidation(columns);
	}

	//Ant's starting location is random
	else
	{
		//Code cited from: https://bytefreaks.net/programming-2/cc-get-a-random-number-that-is-in-a-specific-range
		int randomMin = 1;
		int randomMaxRow = rows;
		int randomMaxColumn = columns;
		
		startingRow = (rand() % (randomMaxRow + 1 - randomMin)) + randomMin;
		startingColumn = (rand() % (randomMaxColumn + 1 - randomMin)) + randomMin;
	}
	
}
