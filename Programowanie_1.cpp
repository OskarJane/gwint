#include <iostream>
#include <windows.h>
#include <ctime>


#include"GameLoc_Menu.h"





using namespace std;


int main()
{

	srand(time(NULL));
	
	if(GameLoc_MENU()==-1)
	{
		system("cls");
		return 0;
	}

	


	system("pause");
	return 0;
}



