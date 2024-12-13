//#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;
struct bankAccount
{
	string egn;
	string name;
	string address;
	float vneseniPari = 0;
	float iztegleniPari = 0; 
	float saldo = 0;
	float obshtoIztegleniPari = 0;
};
void Menu()
{
	cout << setw(25) << setfill('-') << '\n';
	cout<< string(5,' ') << "Банкова сметка" << setw(5) << setfill(' ') <<'\n';
	cout<<setw(25)<<setfill('-')<<'\n';
	cout << "1. Въвеждане на основни данни на клиента" << endl;
	cout << "2. Внасяне/теглене на пари" << endl;
	cout << "3. Проверка на баланс" << endl;
	cout<<	"4. Изход" << endl;
}
void VavejdaneNaKlient(bankAccount& client)
{
	cout << "Въведете ЕГН: ";
	cin >> client.egn;
	while (client.egn.length() != 10 )
	{
		if (client.egn.length() != 10)
		{
			cout << "Невалидно ЕГН! Моля въведете отново: ";
			cin >> client.egn;
		}
	}
	cin.ignore();
	cout << "Въведете име: ";
	cin >> client.name;
	cin.ignore();
	cout << "Въведете адрес: ";
	getline(cin,client.address);
}
void VnasqneITegleneNaPari(bankAccount& client)
{
	float suma;
	cout << "Въведете сума за внасяне: ";
	cin >> suma;
	if (suma > 0)
	{
		cout << "Внесохте " << suma << " лева." << endl;
		client.vneseniPari += suma;
		client.saldo += suma;
		_getche();
	}
	else
	{
		float iztegleniPari = -suma;
		if (iztegleniPari > client.vneseniPari)
		{
			cout << "Нямате достатъчно пари на сметката!" << endl;
			_getche();
		}
		else
		{
			cout << "Изтеглихте " << iztegleniPari << " лева." << endl;
			client.iztegleniPari = iztegleniPari;
			client.obshtoIztegleniPari += iztegleniPari;
			client.saldo -= iztegleniPari;
			_getche();
		}
	}
}
void ProverkaNaBalans(bankAccount& client)
{
	cout << fixed << setprecision(2);
	cout << setw(25) << setfill('-') << '\n';
	cout << string(4, ' ') << "Проверка на баланс" << string(4, ' ') << '\n';
	cout << setw(25) << setfill('-') << '\n';
	cout << "Клиент с име: " << client.name <<'\n'
	<< "и ЕГН: " << client.egn << '\n' 
	<< "е внесъл: " << client.vneseniPari << " лева "<< '\n' 
	<< "и е изтеглил: " << client.obshtoIztegleniPari << " лева." << '\n' 
	<< "И има салдо от: " << client.saldo << " лева." << endl;
	_getche();

}
int IzborOtMenu()
{
	system("chcp 1251");
	system("cls");
	bankAccount client;
	int choice;
	do {
		Menu();
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "Въвеждане на основни данни на клиента" << endl;
			VavejdaneNaKlient(client);
			break;
		case 2:
			cout << "Внасяне и теглене на пари" << endl;
			VnasqneITegleneNaPari(client);
			break;
		case 3:
			ProverkaNaBalans(client);
			break;
		case 4:
			cout << "Довиждане!" << endl;
			break;
		default:
			cout << "Невалиден избор!" << endl;
			_getche();
			break;
		}
	} while (choice != 4);
	return 0;
}
int main()
{
	IzborOtMenu();
	return 0;
}

