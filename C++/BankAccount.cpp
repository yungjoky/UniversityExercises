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
	cout<< string(5,' ') << "������� ������" << setw(5) << setfill(' ') <<'\n';
	cout<<setw(25)<<setfill('-')<<'\n';
	cout << "1. ��������� �� ������� ����� �� �������" << endl;
	cout << "2. �������/������� �� ����" << endl;
	cout << "3. �������� �� ������" << endl;
	cout<<	"4. �����" << endl;
}
void VavejdaneNaKlient(bankAccount& client)
{
	cout << "�������� ���: ";
	cin >> client.egn;
	while (client.egn.length() != 10 )
	{
		if (client.egn.length() != 10)
		{
			cout << "��������� ���! ���� �������� ������: ";
			cin >> client.egn;
		}
	}
	cin.ignore();
	cout << "�������� ���: ";
	cin >> client.name;
	cin.ignore();
	cout << "�������� �����: ";
	getline(cin,client.address);
}
void VnasqneITegleneNaPari(bankAccount& client)
{
	float suma;
	cout << "�������� ���� �� �������: ";
	cin >> suma;
	if (suma > 0)
	{
		cout << "�������� " << suma << " ����." << endl;
		client.vneseniPari += suma;
		client.saldo += suma;
		_getche();
	}
	else
	{
		float iztegleniPari = -suma;
		if (iztegleniPari > client.vneseniPari)
		{
			cout << "������ ���������� ���� �� ��������!" << endl;
			_getche();
		}
		else
		{
			cout << "���������� " << iztegleniPari << " ����." << endl;
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
	cout << string(4, ' ') << "�������� �� ������" << string(4, ' ') << '\n';
	cout << setw(25) << setfill('-') << '\n';
	cout << "������ � ���: " << client.name <<'\n'
	<< "� ���: " << client.egn << '\n' 
	<< "� ������: " << client.vneseniPari << " ���� "<< '\n' 
	<< "� � ��������: " << client.obshtoIztegleniPari << " ����." << '\n' 
	<< "� ��� ����� ��: " << client.saldo << " ����." << endl;
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
			cout << "��������� �� ������� ����� �� �������" << endl;
			VavejdaneNaKlient(client);
			break;
		case 2:
			cout << "������� � ������� �� ����" << endl;
			VnasqneITegleneNaPari(client);
			break;
		case 3:
			ProverkaNaBalans(client);
			break;
		case 4:
			cout << "���������!" << endl;
			break;
		default:
			cout << "��������� �����!" << endl;
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

