#include <iostream>
#include "Header.h"

using namespace std;

clqueue::clqueue()
{
	size = 0;
	last = nullptr;
}

clqueue::~clqueue()
{
	while (size > 0)
	{
		turn* temp = last;
		last = temp->previous;
		delete temp;
		size--;
	}
}

turn* clqueue::get_finish()
{
	return last;
}

int clqueue::pop()
{
	setlocale(LC_ALL, "Rus");
	turn* tmp = last;
	int delelement = 0;

	if (tmp->previous == nullptr)
	{
		delelement = tmp->element;
		delete last;
		last = nullptr;
		size--;
	}
	else
	{
		while (tmp->previous->previous != nullptr)
		{
			tmp = tmp->previous;
		}
		delelement = tmp->previous->element;
		delete tmp->previous;
		tmp->previous = nullptr;
		size--;
	}
	return delelement;
}

void clqueue::push(int el)
{
	turn* new_turn = new turn;
	new_turn->previous = last;
	last = new_turn;
	last->element = el;
	size++;
}

void clqueue::print()
{
	turn* tmp = last;
	while (tmp->previous != nullptr)
	{
		cout << tmp->element << " -- ";
		tmp = tmp->previous;
	}
	cout << tmp->element << endl;
}

void clqueue::copy(clqueue& Q)
{
	int* buff = new int[Q.size];
	turn* el_queue = Q.last;
	for (int i = Q.size - 1; i >= 0; i--)
	{
		buff[i] = el_queue->element;
		el_queue = el_queue->previous;
	}
	for (int i = 0; i < Q.size; i++)
	{
		this->push(buff[i]);
	}
	delete[] buff;
}

void clqueue::fusion(clqueue& Q1)
{
	int* buff1 = new int[Q1.size];
	turn* el_queue1 = Q1.last;
	for (int i = Q1.size - 1; i >= 0; i--)
	{
		buff1[i] = el_queue1->element;
		el_queue1 = el_queue1->previous;
	}
	for (int i = 0; i < Q1.size; i++)
	{
		this->push(buff1[i]);
	}
	delete[] buff1;
	cout << "Слияние произведено!" << endl;
}

bool clqueue::pustota()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}