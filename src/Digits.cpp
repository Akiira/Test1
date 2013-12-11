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


int Digits::getCountOfChildren()
{
	return 2 * size;
}








