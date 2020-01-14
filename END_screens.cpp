#include"END_screens.h"
#include<iostream>
#include<windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void victory_screen()
{
	SetConsoleTextAttribute(hConsole, 7);
	system("cls");
	cout << "You have WON" << endl;
	system("pause");
}

void tie_screen() 
{
	SetConsoleTextAttribute(hConsole, 7);
	system("cls");
	cout << "It's a TIE"<< endl;
	system("pause");
}

void defeat_screen()
{
	SetConsoleTextAttribute(hConsole, 7);
	system("cls");
	cout << "You have LOST" << endl;
	system("pause");
}