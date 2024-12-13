//#include stdafx.h;
#include <iostream>

using namespace std;
const int MENU_ITEM_INDEX = 6;

void menu()
{
	cout << "Въведи стойности (а б): ";
	float sum = 0;
	float a, b;
	cin >> a >> b;
	int choice = 0;
	cout << "---------" << endl;
	cout << "   Меню  " << endl;
	cout << "---------" << endl;
	cout << "1. Събиране" << endl;
	cout << "2. Изваждане" << endl;
	cout << "3. Умножение" << endl;
	cout << "4. Деление" << endl;
	cout << "5. Въвеждане на нови стойности" << endl;
	cout << "6. Изход" << endl;
	do {
		cout << "Избери опция: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			sum = a + b;
			cout << "Сумата на числата е: " << sum << endl;
			
			break;
		case 2:
			cout << "Разликата на числата е: " << a - b << endl;
			break;
		case 3:
			cout << "Произведението на числата е: " << a * b << endl;
			break;
		case 4:
			if (b != 0)

			{

				cout << "Частното на числата е: " << (double)a / b << endl;
				break;
			}
				

			else {

				cout << "Деление на 0 не е възможно!" << endl;

				break;
			}
		case 5:
			cout << "Въведи стойности (а б): ";
			cin >> a >> b;
			break;
		case MENU_ITEM_INDEX:
			cout << "Успешно излязохте!" << endl;
			break;
		default:
			cout << "Грешен избор! Моля въведи своят избор отново." << endl;
			break;
		}
		cout << " " << endl;
	} while (choice != MENU_ITEM_INDEX);
}


void main()
{
	system("chcp 1251");
	system("cls");
	menu();
}