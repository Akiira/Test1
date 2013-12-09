/*
 * Digits.cpp
 *
 *  Created on: Nov 5, 2013
 *      Author: Randall Hudson
 */

#include "Digits.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstddef>

Digits::Digits()
{
	size = 0;

	std::strcpy(digits, "0000000");
}

Digits::Digits(const Digits& d)
{
	size = d.getSize();

	std::strcpy(digits, d.getDigits());
	digits[size] = '\0';
}

Digits::Digits(int size, std::string &digitValues)
{
	this->size = size;
	setDigits(digitValues);
}

void Digits::setDigits(std::string& digitValues)
{
	char *foo;
	foo = new char[size];

	std::strcpy(foo, digitValues.c_str());


	for(int i = 0; i < size; i++)
		digits[i] = foo[i];

	delete foo;

	digits[size] = '\0';
}

Digits::~Digits()
{

}

//This function increments the digit on the safe for the spinner at the given index
void Digits::increment(int index)
{
	int i = digits[index - 1] - 48;// subtract 48 to convert from ascii to int

	if(i == 9)
		i = 0;
	else
		i++;

	digits[index - 1] = i + 48;
}

//This function decrements the digit on the safe for the spinner at the given index
void Digits::decrement(int index)
{
	int i = digits[index - 1] - 48;// subtract 48 to convert from ascii to int

	if(i == 0)
		i = 9;
	else
		i--;

	digits[index - 1] = i + 48;
}

int Digits::getCountOfChildren()
{
	return 2 * size;
}








