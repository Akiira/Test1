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
	std::strcpy(digits, digitValues.c_str());

	digits[size] = '\0';
}

Digits::~Digits()
{

}

//This function increments the digit on the safe for the spinner at the given index
void Digits::increment(int index)
{
	index--;
	if(digits[index] == '9')
		digits[index] = '0';
	else
		digits[index]++;

}

//This function decrements the digit on the safe for the spinner at the given index
void Digits::decrement(int index)
{
	index--;
	if(digits[index] == '0')
		digits[index] = '9';
	else
		digits[index]--;
}

int Digits::getCountOfChildren()
{
	return 2 * size;
}








