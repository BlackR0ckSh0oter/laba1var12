#include <iostream>
#include <locale>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include "Header3.h"

using namespace std;

//12� - ������� ����� ���������, ������� ������� (�������� ����� ������������ � ����������� ����������)

template <class T>
void chosen_class(T* q, int n_q)
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
		cout << "1 - �������� ������� � �������" << endl;
		cout << "2 - ���������� �������� �������" << endl;
		cout << "3 - ����� ������� �� �����" << endl;
		cout << "4 - ������� ����� ���������, ������� �������" << endl;
		cout << "5 - �������� ����� �������" << endl;
		cout << "6 - ������� ���� ��������" << endl;
		cout << "7 - ����� ������ �������" << endl;
		cout << "8 - ������ �������, � ������� �� ��������" << endl;
		cout << "0 - ����� ������-����������" << endl;
		cout << "--|>";
		cin >> c;

		switch (c)
		{
		case 1: //���������� �������� �������
			system("cls");
			cout << "������� ��������: ";
			cin >> value;
			q[pointer].push(value);
			cout << "�������� ��������� � �������.\n " << endl;
			break;
		case 2: //���������� �������� �������
			if (q[pointer].pustota())
			{
				cout << "������� ��� �����, ���������� ����������.\n " << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				value = q[pointer].pop();
				cout << "����������� �������: " << value << endl;
				cout << "\n";
			}
			break;
		case 3: //����� ������� �� �����
			if (q[pointer].pustota())
			{
				cout << "������� �����, �������� ������.\n" << endl;
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
		case 4: //�������
			if (q[pointer].pustota())
			{
				cout << "������. ������� �����.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				total = q[pointer].v12();
				cout << "����� ���������, ������� �������: " << total << endl;
				cout << "\n";
			}
			break;
		case 5: //����������� �������

			if (q[pointer].pustota())
			{
				cout << "������� �����, ���������� ������.\n" << endl;
				system("pause");
				break;
			}

			else
			{
				cout << "������� ����� �������, ���� �� ������ �������� �������������� �������: " << endl;
				cin >> versus;
				if (1 == n_q || versus == pointer)
				{

					cout << "���������� ������� ����� �������, ��� ��� ���������� �������� ����� 1.\n" << endl;
					system("pause");
					break;
				}

				system("cls");
				q[versus].copy(q[pointer]);
				cout << "������� ������� �����������. ������ ���������� ��� ������ �������.\n" << endl;

			}
			break;
		case 6: //������� ���� ��������
			if (n_q == 1)
			{
				cout << "���������� ������ ���� �������.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "� ����� �������� ���������� �������?" << endl;
				cin >> number;

				if ((number < 0) || (number >= n_q) || (number == pointer))
				{
					cout << "������������ ��������!\n" << endl;
					system("pause");
					break;
				}

				if (q[number].pustota())
				{
					cout << "���������� ���������� �������, ��� ��� ������ ������� �����.\n" << endl;
					system("pause");
					break;
				}
				system("cls");
				q[pointer].fusion(q[number]);
				cout << "\n";
			}
			break;
		case 7: //����� ���� �������
			system("cls");
			cout << "� ������ ������ �� �������� � �������� �" << pointer << endl;
			cout << "������� ����� ������� (�� 0 �� " << n_q - 1 << ") , �� ������� ������ �������������: ";
			cin >> number;

			if ((number < 0) || (number >= n_q) || (number == pointer))
			{
				cout << "������������ �������� ��� ���������� �������� ���������!\n" << endl;
				system("pause");
			}
			else
			{
				pointer = number;

				system("cls");
				cout << "�� ������������� �� ������� �" << pointer << endl;
				cout << "\n";
			}
			break;
		case 8:
			system("cls");
			cout << "�� ������ ��������� � �������� �" << pointer << endl;
			cout << "\n";
			break;
		case 0:
			cout << "\n";
			flag = 0;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int amount_queue = 0; //���������� ��������
	int c;
	int flag = 1;

	private_queue* q1 = NULL;
	protected_queue* q2 = NULL;
	public_queue* q3 = NULL;

	cout << "������� ���������� ��������: ";
	do 
	{
		cin >> amount_queue;
	} while (amount_queue < 0 && cout << "������� �������� ���������� ��������, ������� �����.\n" && cout << "������� ���������� ��������: ");
			
	system("cls");
	cout << "����� ������-����������: " << endl;

	while (flag == 1)
	{
		cout << "1 - ���������" << endl;
		cout << "2 - ����������" << endl;
		cout << "3 - ���������" << endl;
		cout << "0 - ����� �� ���������" << endl;
		cout << "--|> ";
		cin >> c;

		switch (c)
		{
		case 1:
			q1 = new private_queue[amount_queue];
			system("cls");
			chosen_class(q1, amount_queue);
			delete[] q1;
			break;
		case 2:
			q2 = new protected_queue[amount_queue];
			system("cls");
			chosen_class(q2, amount_queue);
			delete[] q2;
			break;
		case 3:
			q3 = new public_queue[amount_queue];
			system("cls");
			chosen_class(q3, amount_queue);
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