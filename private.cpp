#include <iostream>
#include "Header1.h"

using namespace std;

int private_queue::v12()
{
	turn* last = get_finish();
	int max = get_finish()->element;
	int min = get_finish()->element;
	int result = 0;
	int razmah = 0;

	if (size == 0)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (last != nullptr)
		{
			if (last->element > max)
				max = last->element;
			if (last->element < min)
				min = last->element;
			last = last->previous;
		}

		razmah = max - min;
		last = get_finish();

		while (last != nullptr)
		{
			if (last->element > razmah)
			{
				result++;
			}
			last = last->previous;
		}
	}
	return result;
}
int private_queue::pop() { return clqueue::pop(); }
void private_queue::push(int el) { return clqueue::push(el); }
void private_queue::print() { return clqueue::print(); }
void private_queue::fusion(private_queue& Q1) { return clqueue::fusion(Q1); }
void private_queue::copy(private_queue& Q1) { return clqueue::copy(Q1); }
bool private_queue::pustota() { return clqueue::pustota(); }