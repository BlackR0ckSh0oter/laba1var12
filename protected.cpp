#include <iostream>
#include "Header2.h"

using namespace std;

int protected_queue::v12()
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
int protected_queue::pop() { return clqueue::pop(); }
void protected_queue::push(int el) { return clqueue::push(el); }
void protected_queue::print() { return clqueue::print(); }
void protected_queue::fusion(protected_queue& Q1) { return clqueue::fusion(Q1); }
void protected_queue::copy(protected_queue& Q1) { return clqueue::copy(Q1); }
bool protected_queue::pustota() { return clqueue::pustota(); }