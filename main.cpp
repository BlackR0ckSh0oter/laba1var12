#include <iostream>
#include <locale>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include "Header3.h"

using namespace std;

//12в - Подсчет числа элементов, больших размаха (разности между максимальным и минимальным элементами)

template <class T>
void siclass(T* q, int n_q)
{
	setlocale(LC_ALL, "Rus");
	int c;
	int flag = 1;
	int value;
	int pointer = 0;
	int total = 0;
	int number;
	int versus = 0;

	while (flag == 1)
	{
		cout << "1 - Добавить элемент в очередь" << endl;
		cout << "2 - Извлечение элемента очереди" << endl;
		cout << "3 - Вывод очереди на экран" << endl;
		cout << "4 - Подсчет числа элементов, больших размаха" << endl;
		cout << "5 - Создание копии очереди" << endl;
		cout << "6 - Слияние двух очередей" << endl;
		cout << "7 - Выбор другой очереди" << endl;
		cout << "8 - Узнать очередь, с которой мы работаем" << endl;
		cout << "9 - Выбор класса-наследника" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "--|>";
		cin >> c;

		switch (c)
		{
		case 1: //добавление элемента очереди
			system("cls");
			cout << "Введите значение: ";
			cin >> value;
			q[pointer].push(value);
			cout << "Значение добавлено в очередь.\n " << endl;
			break;
		case 2: //извлечение элемента очереди
			if (q[pointer].pustota())
			{
				cout << "Очередь уже пуста, извлечение невозможно.\n " << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				value = q[pointer].pop();
				cout << "Извлеченный элемент: " << value << endl;
				cout << "\n";
			}
			break;
		case 3: //вывод очереди на экран
			if (q[pointer].pustota())
			{
				cout << "Очередь пуста, выводить нечего.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				q[pointer].print();
				cout << "\n";
			}
			break;
		case 4: //задание
			if (q[pointer].pustota())
			{
				cout << "Ошибка. Очередь пуста.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				total = q[pointer].v12();
				cout << "Число элементов, больших размаха: " << total << endl;
				cout << "\n";
			}
			break;
		case 5: //копирование очереди

			if (q[pointer].pustota())
			{
				cout << "Очередь пуста, копировать нечего.\n" << endl;
				system("pause");
				break;
			}

			else
			{
				cout << "Введите номер очереди, куда вы хотите вставить скопировыанную очередь: " << endl;
				cin >> versus;
				if (1 == n_q || versus == pointer)
				{

					cout << "Невозможно создать копию очереди, так как количество очередей равно 1.\n" << endl;
					system("pause");
					break;
				}

				system("cls");
				q[versus].copy(q[pointer]);
				cout << "Очередь успешно скопирована. Теперь существует две равных очереди.\n" << endl;

			}
			break;
		case 6: //слияние двух очередей
			if (n_q == 1)
			{
				cout << "Существует только одна очередь.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "С какой очередью произвести слияние?" << endl;
				cin >> number;

				if ((number < 0) || (number >= n_q) || (number == pointer))
				{
					cout << "Некорректное значение!\n" << endl;
					system("pause");
					break;
				}

				if (q[number].pustota())
				{
					cout << "Невозможно произвести слияние, так как вторая очередь пуста.\n" << endl;
					system("pause");
					break;
				}
				system("cls");
				q[pointer].fusion(q[number]);
				cout << "\n";
			}
			break;
		case 7: //выбор иной очереди
			system("cls");
			cout << "В данный момент мы работает с очередью №" << pointer << endl;
			cout << "Введите номер очереди (от 0 до " << n_q - 1 << ") , на которую хотите переключиться: ";
			cin >> number;

			if ((number < 0) || (number >= n_q) || (number == pointer))
			{
				cout << "Некорректное значение или количество очередей превышено!\n" << endl;
				system("pause");
			}
			else
			{
				pointer = number;

				system("cls");
				cout << "Вы переключились на очередь №" << pointer << endl;
				cout << "\n";
			}
			break;
		case 8:
			system("cls");
			cout << "Вы сейчас работаете с очередью №" << pointer << endl;
			cout << "\n";
			break;
		case 9:
			cout << "\n";
			flag = 0;
			break;
		case 0:
			exit(1);
			break;
		default:
			system("cls");
			cout << "Error" << endl;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int amount_queue = 0; //количество очередей
	int c;
	int flag = 1;

	private_queue* q1 = NULL;
	protected_queue* q2 = NULL;
	public_queue* q3 = NULL;

	cout << "Введите количество очередей: ";
	do 
	{
		cin >> amount_queue;
	} while (amount_queue <= 0 && cout << "Введено неверное количество очередей, введите снова.\n" && cout << "Введите количество очередей: ");
			
	system("cls");
	cout << "Выбор класса-наследника: " << endl;

	while (flag == 1)
	{
		cout << "1 - Приватный" << endl;
		cout << "2 - Защищенный" << endl;
		cout << "3 - Публичный" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "--|> ";
		cin >> c;

		switch (c)
		{
		case 1:
			q1 = new private_queue[amount_queue];
			system("cls");
			siclass(q1, amount_queue);
			delete[] q1;
			break;
		case 2:
			q2 = new protected_queue[amount_queue];
			system("cls");
			siclass(q2, amount_queue);
			delete[] q2;
			break;
		case 3:
			q3 = new public_queue[amount_queue];
			system("cls");
			siclass(q3, amount_queue);
			delete[] q3;
			break;
		case 0:
			flag = 0;
			break;
		default:
			system("cls");
			cout << "Error" << endl;
			break;
		}
	}
	return 0;
}