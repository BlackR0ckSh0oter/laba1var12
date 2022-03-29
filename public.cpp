#include <iostream>
#include "Header3.h"

using namespace std;

int public_queue::v12()
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