#pragma once
#include "Header.h"

class private_queue : private clqueue
{
public:
	int v12();
	int pop();
	void push(int el);
	void print();
	void fusion(private_queue& Q1);
	void copy(private_queue& Q);
	bool pustota();
};
