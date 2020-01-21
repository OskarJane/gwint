#include"END_screens.h"
#include<iostream>
#include<windows.h>


#pragma comment(lib, "winmm.lib") //systemowe biblioteki/ SHORTCUT- to ma byc ¿eby muzyka grala

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void END_Resolution()//Ten kod odpowiedzialny jest tylko i wylacznie za ustawienie wysokosci i szerokosci terminala
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD a;
	a.X = 0;
	a.Y = 0;

	SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = 10;
	rect.Right = 75;


	SetConsoleScreenBufferSize(handle, a);

	SetConsoleWindowInfo(handle, 1, &rect);


}

void defeat_screen()
{

	SetConsoleTextAttribute(hConsole, 4);
	system("cls");

	END_Resolution();
	
	cout << " (    (        )               (                 )          " << endl;
	cout<<	" )\\ ) )\\ )  ( /(       (       )\\ )    (      ( /(   (      " << endl;
	cout << "(()/((()/(  )\\()) (    )\\ )   (()/(    )\\     )\\())  )\\      " << endl;
	cout << " /(_))/(_))((_)\\  )\\  (()/(    /(_))((((_)(  ((_)\\((((_)(    " << endl;
	cout << "(_)) (_))   _((_)((_)  /(_))_ (_))   )\\ _ )\\  _((_))\\ _ )\\  " << endl;
	cout << "| _ \\| _ \\ |_  / | __|(_)) __|| _ \\  (_)_\\(_)| \\| |(_)_\\(_) " << endl;
	cout << "|  _/|   /  / /  | _|   | (_ ||   /   / _ \\  | .` | / _ \\   " << endl;
	cout << "|_|  |_|_\\ /___| |___|   \\___||_|_\\  /_/ \\_\\ |_|\\_|/_/ \\_\\  " << endl;

	SetConsoleTextAttribute(hConsole, 7);
	
	cout << endl << "Nacisnij ENTER aby wyjsc z programu" << endl;
	cin.get();
	exit(1);
}

void tie_screen() 
{
	
	SetConsoleTextAttribute(hConsole, 9);
	system("cls");
	
	END_Resolution();

	cout << " (           *     (    (     " << endl;
	cout << " )\\ )      (  `    )\\ ) )\\ )  " << endl;
	cout << "(()/( (    )\\))(  (()/((()/(  " << endl;
	cout << " /(_)))\\  ((_)()\\  /(_))/(_)) " << endl;
	cout << "(_)) ((_) (_()((_)(_)) (_))   " << endl;
	cout << "| _ \\| __||  \\/  ||_ _|/ __|  " << endl;
	cout << "|   /| _| | |\\/| | | | \\__ \\  " << endl;
	cout << "|_|_\\|___||_|  |_||___||___/ " << endl;

	SetConsoleTextAttribute(hConsole, 7);

	cout << endl << "Nacisnij ENTER aby wyjsc z programu" << endl;
	cin.get();
	exit(1);
}

void victory_screen()
{
	Play_Music_victory();


	SetConsoleTextAttribute(hConsole, 10);
	system("cls");

	END_Resolution();

	cout << "               )          (                 )          " << endl;
	cout << " (  (       ( /(  (       )\\ )    (      ( /(   (      " << endl;
	cout << " )\\))(   '  )\\()) )\\ )   (()/(    )\\     )\\())  )\\     " << endl;
	cout << "((_)()\\ )  ((_)\\ (()/(    /(_))((((_)(  ((_)\\((((_)(   " << endl;
	cout << "_(())\\_)()__ ((_) /(_))_ (_))   )\\ _ )\\  _((_))\\ _ )\\  " << endl;
	cout << "\\ \\((_)/ /\\ \\ / /(_)) __|| _ \\  (_)_\\(_)| \\| |(_)_\\(_) " << endl;
	cout << " \\ \\/\\/ /  \\ V /   | (_ ||   /   / _ \\  | .` | / _ \\   " << endl;
	cout << "  \\_/\\_/    |_|     \\___||_|_\\  /_/ \\_\\ |_|\\_|/_/ \\_\\ " << endl;

	SetConsoleTextAttribute(hConsole, 7);

	cout << endl << "Nacisnij ENTER aby wyjsc z programu" << endl;
	cin.get();
	exit(1);
}

void Play_Music_victory()
{
	PlaySound(TEXT("Gwent_Toss_a_coin.wav"), NULL, SND_ASYNC | SND_LOOP);
}