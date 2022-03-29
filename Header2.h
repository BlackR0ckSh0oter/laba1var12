#pragma once
#include "Header.h"

class protected_queue : protected clqueue
{
public:
	int v12();
	int pop();
	void push(int el);
	void print();
	void fusion(protected_queue& Q1);
	void copy(protected_queue& Q);
	bool pustota();
};