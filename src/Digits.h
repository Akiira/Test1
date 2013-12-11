/*
 * Digits.h
 *
 *  Created on: Nov 5, 2013
 *      Author: Randall Hudson
 */

#ifndef DIGITS_H_
#define DIGITS_H_

#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

class Digits
{
private:
	int size;
	char digits[7];
public:
	Digits();
	Digits(const Digits& d);
	Digits(int);
	Digits(int, std::string &);


	//reset the digit to the one passed in
	void resInitDigit(const Digits& d){
		size = d.getSize();

		std::strcpy(digits, d.getDigits());
		digits[size] = '\0';
	}

	int getCountOfChildren();
	void setDigits(std::string &);

	inline void increment(int);//increment the digit at an index
	inline void decrement(int);//decrement the digit at an index
	inline void getAllPossibleChildren(std::vector<Digits>& children) const;
	inline const int getDigitsAsInt() const;
	inline const char* getDigits() const;
	inline int getSize() const;
	inline void setSize(int size);

};

inline void Digits::getAllPossibleChildren(std::vector<Digits>& children) const
{
	for (int i = 0; i < size; i++)
	{
		Digits d(*this);
		d.increment(i + 1);
		children[2 * i] = d;

		Digits d2(*this);
		d2.decrement(i + 1);
		children[2 * i + 1] = d2;
	}
}

inline const int Digits::getDigitsAsInt() const
{
	return std::atoi(digits);
}
inline const char* Digits::getDigits() const
{
	return digits;
}

inline int Digits::getSize() const
{
	return size;
}

inline void Digits::setSize(int size)
{
	this->size = size;
}

//This function increments the digit on the safe for the spinner at the given index
inline void Digits::increment(int index)
{
	index--;
	if (digits[index] == '9')
		digits[index] = '0';
	else
		digits[index]++;

}

//This function decrements the digit on the safe for the spinner at the given index
inline void Digits::decrement(int index)
{
	index--;
	if (digits[index] == '0')
		digits[index] = '9';
	else
		digits[index]--;
}
#endif /* DIGITS_H_ */
