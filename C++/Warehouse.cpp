#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;

struct Warehouse {
    int index = 0;
    string ime = "";
    int dostavnoKolichestvo = 0;
    int prodadenoKolichestvo = 0;
    float dostavnaCena = 0;
    float prodajnaCena = 0;
};
void dostavkaNaStoka(Warehouse warehouse[], int size) {
    int nomer;
    cout << "Доставка на стока" << endl;
    cout << "Въведете номер на стоката: ";
    cin >> nomer;
    if (nomer > 0 && nomer <= size && warehouse[nomer - 1].index == nomer) {
        cout << "Въведете доставено количество: ";
        cin >> warehouse[nomer - 1].dostavnoKolichestvo;
        cout << "Въведете доставна цена: ";
        cin >> warehouse[nomer - 1].dostavnaCena;
    }
    else {
        cout << "Няма стока с такъв номер!" << endl;
    }
    _getch();
    system("cls");
}
void prodajbaNaStoka(Warehouse warehouse[], int size) {
    int nomer;
    cout << "Продажба на стока" << endl;
    cout << "Въведете номер на стоката: ";
    cin >> nomer;
    if (nomer > 0 && nomer <= size && warehouse[nomer - 1].index == nomer) {
        cout << "Въведете продадено количество: ";
        cin >> warehouse[nomer - 1].prodadenoKolichestvo;
        cout << "Въведете цена на продажба: ";
        cin >> warehouse[nomer - 1].prodajnaCena;
    }
    else {
        cout << "Няма стока с такъв номер!" << endl;
    }
    _getch();
    system("cls");
}
void VuvejdaneNaOsnDanni(Warehouse warehouse[], int size) {
    system("cls");
    int nomer;
    cout << "Въведете номер на стоката: ";
    cin >> nomer;
    if (nomer > 0 && nomer <= size) {
        warehouse[nomer - 1].index = nomer;
        cout << "Въведете име на стоката: ";
        cin >> warehouse[nomer - 1].ime;
    }
    else if (nomer <= 0)
    {
        cout << "Номерът на стоката трябва да бъде по-голям от 0!" << endl;
        _getch();
    }
    else {
        cout << "Склада е пълен" << endl;
        _getch();
    }
   
}
void oborotnaVedomost(Warehouse warehouse[], int size) {
    system("cls");
    cout << string(92, '–') << endl;
    cout << "Номер" << '|' << setw(7) << "Име" << string(3, ' ') << '|' << setw(15) << "Доставки" << string(4, ' ') << '|' << setw(15) << "Продажби" << string(4, ' ') << '|' << setw(25) << "Крайно салдо" << string(9, ' ') << "|" << endl;
    cout << string(5, ' ') << '|' << string(10, ' ') << '|' << "количество" << '|' << "Стойност" << "|" << "количество" << '|' << "Стойност" << "|" << "количество" << '|' << "Стойност" << ' ' << "|" << "единична цена" << '|' << endl;
    cout << string(92, '–') << endl;
    for (int i = 0; i < size; i++) {
        int krainoKolichestvo = warehouse[i].dostavnoKolichestvo - warehouse[i].prodadenoKolichestvo;
        float krainaStoinost = (warehouse[i].dostavnoKolichestvo * warehouse[i].dostavnaCena - warehouse[i].prodadenoKolichestvo * warehouse[i].prodajnaCena);
        float edinichnaCena;
        if (krainoKolichestvo > 0) {
            edinichnaCena = krainaStoinost / krainoKolichestvo;
        }
        else {
            edinichnaCena = 0;
        }
        cout << setw(5) << warehouse[i].index << '|' << setw(7) << warehouse[i].ime << string(3, ' ') << '|' << setw(15) << "Доставки" << string(4, ' ') << '|' << setw(15) << "Продажби" << string(4, ' ') << '|' << setw(25) << "Крайно салдо" << string(9, ' ') << "|" << endl;
        cout << setw(5) << string(5, ' ') << '|' << string(10, ' ') << '|' << setw(4) << warehouse[i].dostavnoKolichestvo << string(5, ' ') << '|' << setw(4) << warehouse[i].dostavnaCena << string(5, ' ') << "|" << setw(4) << warehouse[i].prodadenoKolichestvo << string(5, ' ') << '|' << setw(4) << warehouse[i].prodajnaCena << string(5, ' ') << "|" << setw(6) << krainoKolichestvo << string(4, ' ') << '|' << setw(7) << krainaStoinost << string(4, ' ') << ' ' << "|" << setw(6) << edinichnaCena << string(4, ' ') << '|' << endl;
        cout << string(92, '–') << endl;
    }
    cout << "Натиснете някой клавиш, за да се върнете към главното меню!" << endl;
    _getche();
}
void subMenu(Warehouse warehouse[], int size) {
    system("cls");
    cout << "Складова дейност" << endl;
    int choice;
    do {
        cout << "1. Доставка на стока" << endl;
        cout << "2. Продажба на стока " << endl;
        cout << "3. Оборотна ведомост" << endl;
        cout << "4. Към главното меню" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            dostavkaNaStoka(warehouse, size);
            break;
        case 2:
            prodajbaNaStoka(warehouse, size);
            break;
        case 3:
            oborotnaVedomost(warehouse, size);
            system("cls");
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 4);
}
void Menu() {
    system("chcp 1251");
    system("cls");
    Warehouse warehouse[3];
    int size = 3;
    int choice;
    do {
        system("cls");
        cout << "1. Въвеждане на основни данни на стоките" << endl;
        cout << "2. Складова дейност " << endl;
        cout << "3.Exit" << endl;

        cin >> choice;
        switch (choice) {
        case 1:
            VuvejdaneNaOsnDanni(warehouse, size);
            break;
        case 2:
            subMenu(warehouse, size);
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 3);
}
int main() {
    Menu();
    return 0;
}
