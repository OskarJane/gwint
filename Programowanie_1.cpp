﻿#include <iostream>
#include <windows.h>
#include <ctime>


#include"GameLoc_Menu.h"

#pragma comment(lib, "winmm.lib") //systemowe biblioteki/ SHORTCUT- to ma byc żeby muzyka grala



using namespace std;

void Play_Music();

int main()
{

	srand(time(NULL));
	Play_Music();
	if(GameLoc_MENU()==-1)
	{
		system("cls");
		return 0;
	}

	


	system("pause");
	return 0;
}

void Play_Music()
{
	PlaySound(TEXT("Gwent_soundtrack_1.wav"),NULL,  SND_ASYNC | SND_LOOP);
}

