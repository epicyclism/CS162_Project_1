/************************************************************************************
** Source file for the inputValidation.hpp                                          *
**                                                                                  *
** Functions to used to test the input if it is valid or not                        *
************************************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"


/*************************************************************************************
* int inputValidation()
*
* Entry: Called from menu()
*
* Exit:  After asking the user for all their input and validating it
*
* Purpose: Asks the user to enter a input.  Then checks if the input is positive, 
*          not a float, and doens't contain any special characters. If any of these 
*           return true, the user is asked again to enter a valid input
*
*		   Return an int to menu()
*************************************************************************************/
int inputValidation()
{
	//Cited from http://www.cplusplus.com/reference/cstdlib/atoi/, 
	//http://www.cplusplus.com/reference/cctype/isspace/ and http://www.cplusplus.com/reference/cctype/ispunct/

	string str;  //Users input convereted to a string
	int userInput; //The users input
	getline(cin, str);

	userInput = atoi(str.c_str());

	while (!atoi(str.c_str()) || scanForSymbolOrSpace(str) || userInput < 1)
	{
		cout << "\nPlease enter an integer that is greater than 0. " << endl;
		cout << "As well, ensure that there are no characters or special characters. " << endl;
		getline(cin, str);
		userInput = atoi(str.c_str());

	}

	return userInput;

}
/*************************************************************************************
* int inputValidation(int max)
*
* Entry: Called from menu()
*
* Exit:  After asking the user for all their input and validating it
*
* Purpose: Asks the user to enter a input.  Then checks if the input is positive, less
*          than the max not a float, and doens't contain any special characters.
*          If any of these return true, the user is asked again to enter a valid input
*
*************************************************************************************/

int inputValidation(int max)
{
	//Cited from http://www.cplusplus.com/reference/cstdlib/atoi/, 
	//http://www.cplusplus.com/reference/cctype/isspace/ and http://www.cplusplus.com/reference/cctype/ispunct/

	string str;
	int userInput;
	getline(cin, str);

	userInput = atoi(str.c_str());

	while (!atoi(str.c_str()) || scanForSymbolOrSpace(str) || userInput < 1 || userInput > max)
	{
		cout << "\nPlease enter a positive integer between 0 and " << max << "." << endl;
		cout << "As well, ensure that there are no characters or special characters. " << endl;
		getline(cin, str);
		userInput = atoi(str.c_str());
	}

	return userInput;
}

/*************************************************************************************
* int bool scanForSymbolOrSpace(string inStr)
*
* Entry: Called from int inputValidation(int max) or  int inputValidation()
*
* Exit:  Returns a bool 
*
* Purpose: Checks to see if the string contains any special characters or spaces
*
*************************************************************************************/
bool scanForSymbolOrSpace(string inStr)
{
	//Cited from http://www.cplusplus.com/reference/cctype/isspace/ and http://www.cplusplus.com/reference/cctype/ispunct/
	int strLen = inStr.length();

	//Checks to see if there is a negative number
	if (inStr.c_str()[0] == '-')
	{
		for (int i = 1; i < strLen; i++)
		{
			//Check to see if there is a special characters
			if (ispunct(inStr.c_str()[i]))
				return true;
		}
	}

	else //If no hyphen, check for special character
	{	
		for (int i = 0; i < strLen; i++)
		{
			if (ispunct(inStr.c_str()[i]))
				return true;
		}
	}
	
	//Check for a space in the string
	for (int i = 0; i < strLen; i++)
		{
			if (isspace(inStr.c_str()[i]))
				return true;
		}

	return false;
}
