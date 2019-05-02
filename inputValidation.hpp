/************************************************************************************
** Header file for the inputValidation.cpp                                          *
**                                                                                  *
** Functions to used to test the input if it is valid or not                        *
************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

#ifndef INPUTVALIDATION
#define INPUTVALIDATION_HPP

//Tests if input is greater than 0
int inputValidation();

//First test for input validation.  Test to see if number is an int and in range 
int inputValidation(int max);

bool scanForSymbolOrSpace(string str);

#endif
