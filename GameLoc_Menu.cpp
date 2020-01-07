#include <iostream>
#include <windows.h>
#include<conio.h>

#include"GameLoc_Menu.h"
#include"GameLoc_Options.h"
#include"GameLoc_DeckEdit.h"
#include"GameLoc_Game.h"


menu_options Main_menu[4] =
{
	//1
	{"Graj"},
	//2
	{"Edytuj Talie"},
	//3
	{"Opcje"},
	//4
	{"Wyjscie"}
};

int GameLoc_MENU()
{
	menu_Resolution();

	int menu_pointer = 1;

	for (;;)
	{
		menu_render(menu_pointer);
		menu_pointer = menu_location(menu_pointer);
		if (menu_pointer == -1)
		{
			return -1;
		}
	}
}

void menu_render(int pointer)//rysowanie menu
{
	system("cls");

	//kolor
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	/*for (int i = 0;i < 1000;i++)
	{
		SetConsoleTextAttribute(hConsole, i);
		cout << i << endl;
	}*/	//show all colors (DONT USE)


	SetConsoleTextAttribute(hConsole, 14);
	cout << endl;
	cout << "  ____  __    __  ____  ____   ______" << endl;
	cout << " /    ||  |__|  ||    ||    \\ |      |" << endl;
	cout << "|   __||  |  |  | |  | |  _  ||      |" << endl;
	cout << "|  |  ||  |  |  | |  | |  |  ||_|  |_|" << endl;
	cout << "|  |_ ||  \\  /  | |  | |  |  |  |  |  " << endl;
	cout << "|     |\\        / |  | |  |  |  |  |" << endl;
	cout << "|___,_| \\_/  \\_/ |____||__|__|  |__|" << endl;
	cout << endl;

	SetConsoleTextAttribute(hConsole, 7);

	//menu options
	for (int i = 0;i < 4;i++)
	{
		if (pointer == i + 1)
		{
			SetConsoleTextAttribute(hConsole, 11);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 7);
		}
		cout << "\t" << i + 1 << "." << Main_menu[i].option_name << endl;
	}
	SetConsoleTextAttribute(hConsole, 7);//reset

}

void menu_Resolution()//Ten kod odpowiedzialny jest tylko i wylacznie za ustawienie wysokosci i szerokosci terminala
{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD a;
	a.X = 0;
	a.Y = 0;

	SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = 15;
	rect.Right = 50;


	SetConsoleScreenBufferSize(handle, a);

	SetConsoleWindowInfo(handle, 1, &rect);


}

int menu_location(int pointer)//sterowanie po menu
{
	int key_pressed{};
	key_pressed = _getch();

	switch (key_pressed)
	{

	case '1'://musi byæ jako char poniewaz key_pressed tez jest char'em
	case '2':
	case '3':
	case '4':
		return key_pressed - '0';//wyluskuje liczbe zamiast chara
	case 13:
		return Porusz_menu(pointer);//zwraca pointer na sama gore menu lub wychodzi z programu
	case 72://72 to cyfra okreslajaca strzalek w gore
		if (pointer > 1)
		{
			return pointer - 1;
		}
	case 80://strzalek w dol
		if (pointer < 4)
		{
			return pointer + 1;
		}

	default:
		return pointer;
	}

}

int Porusz_menu(int opcja)
{
	switch (opcja)
	{
	case 1:
		GameLoc_Game();
		return 1;
	case 2:
		GameLoc_DeckEdit();
		return 1;
	case 3:
		GameLoc_Options();
		return 1;
	case 4:
		return -1;
		break;
	}
	return 1;
}


