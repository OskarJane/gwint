#include<iostream>
#include <iomanip>
#include <windows.h>
#include<conio.h>

#include"GameLoc_Options.h"

using namespace std;

options_options Option_menu[4] =
{
	//1
	{"       Karty AI","Licznik","Wizualizacja",0,"\tLicznik redukuje miganie!"},
	//2
	{"Dobieranie Kart","Tryb Challenge","Losowanie z talii",0,"\tLosowanie nie jest zbalansowane!"},
	//3
	{"Efekty pogodowe","Nie","Tak",0,"\tDaje graczowi karty pogodowe!"},
	//4
	{"     Sortowanie","Nie","Do Lewej",0,"\tKarty gracza ukladaja sie obok siebie!"}
};


void GameLoc_Options()
{
	
	int options_pointer = 0;
	for (;;)
	{
		options_render(options_pointer);
		options_pointer = options_location(options_pointer);
		if (options_pointer == -1)
		{
			break;
		}
	}
}

void options_render(int pointer)
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);


	cout << "\t\t\tOPCJE" << endl;
	for (int i = 0;i < 4;i++)
	{
		SetConsoleTextAttribute(hConsole, 7);
	
		setw(20);
		cout <<"\t"<< Option_menu[i].option_name<<": \t";

		if (pointer == i)
		{
			SetConsoleTextAttribute(hConsole, 11);
		}
		if (Option_menu[i].option_id == 0)
		{
			
			cout<<Option_menu[i].option_one;
		}
		else
		{
			cout << Option_menu[i].option_two;
		}
		cout << endl;
	}

	SetConsoleTextAttribute(hConsole, 8);
	cout << endl << Option_menu[pointer].info << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl << "\t\tNacisnij X aby wyjsc" << endl;
}

int options_location(int pointer)//sterowanie po menu
{
	int key_pressed{};
	key_pressed = _getch();

	switch (key_pressed)
	{
	case 75:
	case 77:
	case 13:
		if (Option_menu[pointer].option_id == 0)
		{
			Option_menu[pointer].option_id = 1;
		}
		else
		{
			Option_menu[pointer].option_id = 0;
		}
		return pointer;//zwraca pointer na sama gore menu lub wychodzi z programu
	case 72://72 to cyfra okreslajaca strzalek w gore
		if (pointer > 0)
		{
			return pointer - 1;
		}
		return pointer;
	case 80://strzalek w dol
		if (pointer < 3)
		{
			return pointer + 1;
		}
		return pointer;
	case 'x':
		return -1;
	default:
		return pointer;
	}

}

bool check_option(int n)
{
	if (Option_menu[n].option_id == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}