/*
 * Node.h
 *
 *  Created on: Dec 5, 2013
 *      Author: Randall Hudson
 */

#ifndef NODE_H_
#define NODE_H_

#include "Digits.h"

class Node
{
private:

public:
	Digits data;
	char operation;
	int index;
	Node* parent;
	Node* next;

	Node(): data(),operation('!'), index(-1), parent(nullptr), next(nullptr) {}
	Node(Digits &d, Node* p) : data(d), operation('!'), index(-1), parent(p), next(nullptr){}
	Node(Digits &d, Node* p, char op, int in) : data(d), operation(op), index(in), parent(p), next(nullptr){}


	void setAll(Digits &d, Node* p, char op, int in)
	{
		data.resInitDigit(d);
		parent = p;
		operation = op;
		index = in;
	}
};

#endif /* NODE_H_ */
