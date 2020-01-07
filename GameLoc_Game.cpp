#include<iostream>
#include <windows.h>
#include<conio.h>

#include"GameLoc_Game.h"

using namespace std;

char lg = 201;//╔
char pg = 187;//╗
char ld = 200;//╚
char pd = 188;//╝

char jednaLinia = 196;//-
char dwieLinia = 205;//=
char VjednaLinia = 124;//|
char VdwieLinia = 186;//|

cards Hand[12] =
{
	{1,1,1,1},
	{2,1,3,2},
	{3,1,5,3},
	{4,1,7,1},

	{5,1,5,2},
	{6,1,4,1},
	{7,1,3,2},
	{8,1,2,3},

	{9,1,8,2},
	{10,1,5,3},
	{11,1,3,1},
	{12,1,1,3}
};
cards row[20] =
{
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},

	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},

	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},

	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},

	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
};

row_board szereg[3]=
{
	row[20],
	row[20],
	row[20]
};


void GameLoc_Game()
{
	game_Resolution();

	int game_pointer = 1;
	
	

	for (;;)
	{
		game_render(game_pointer);
		game_pointer = game_location(game_pointer);
	}

}

void game_Resolution()//Ten kod odpowiedzialny jest tylko i wylacznie za ustawienie wysokosci i szerokosci terminala
{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD a;
	a.X = 0;
	a.Y = 0;

	SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = 51;
	rect.Right = 119;// 119 jest maks. wartoscia jaka tu dziala (wth?)


	SetConsoleScreenBufferSize(handle, a);

	SetConsoleWindowInfo(handle, 1, &rect);


}

void game_render(int pointer)
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);


	for (int i = 0;i < 25;i++)
	{
		cout <<endl;
	}
	
	for (int i = 0;i < 120;i++)
	{
		cout <<dwieLinia;
	}
	cout << endl;//Polowa stolu
	for (int i = 0;i < 3;i++)
	{
		rysuj_szereg(i);
	}

	
	for (int i = 0;i < 120;i++)
	{
		cout <<jednaLinia;
	}
	cout << endl;
	rysuj_karty(pointer);






	
}

void rysuj_karty(int pointer)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int pointed_color_card = 11;
	int default_color_card = 14;

	//rysuj karty
	int card_amount = 12;//placeholder- to ma byc pobierane ze struktury

	cout << "\t";
	for (int i = 0;i < card_amount;i++)//top
	{
		
		if (pointer == i + 1)
		{
			SetConsoleTextAttribute(hConsole, pointed_color_card);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, default_color_card);
		}

		if (Hand[i].card_id == 0)
		{
			cout << "        ";
		}
		else
		{
			cout << " " << lg << "-----" << pg;
		}
	}
	cout << endl<<"\t";
	/*middle*/
	for (int i = 0;i < card_amount;i++)
	{
		if (pointer == i + 1)
		{
			SetConsoleTextAttribute(hConsole, pointed_color_card);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, default_color_card);
		}

		if (Hand[i].card_id == 0)
		{
			cout << "        ";
		}
		else
		{
			cout << " |     |";
		}
	}
	cout << endl << "\t";
	for (int i = 0;i < card_amount;i++)
	{
		if (pointer == i + 1)
		{
			SetConsoleTextAttribute(hConsole, pointed_color_card);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, default_color_card);
		}

		if (Hand[i].card_id == 0)
		{
			cout << "        ";
		}
		else
		{
			cout << " |  " << Hand[i].card_power << "  |";
		}
	}
	cout << endl << "\t";
	for (int i = 0;i < card_amount;i++)
	{
		if (pointer == i + 1)
		{
			SetConsoleTextAttribute(hConsole, pointed_color_card);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, default_color_card);
		}

		if (Hand[i].card_id == 0)
		{
			cout << "        ";
		}
		else
		{
			cout << " |     |";
		}
	}
	cout << endl << "\t";
	for (int i = 0;i < card_amount;i++)
	{
		if (pointer == i + 1)
		{
			SetConsoleTextAttribute(hConsole, pointed_color_card);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, default_color_card);
		}

		if (Hand[i].card_id == 0)
		{
			cout << "        ";
		}
		else
		{
			cout << " |";
			if (Hand[i].card_type == 1)
			{
				cout << "Stwur";
			}
			else
			{
				cout << "     ";
			}
			cout << "|";
		}
	}
	cout << endl << "\t";
	for (int i = 0;i < card_amount;i++)
	{
		if (pointer == i + 1)
		{
			SetConsoleTextAttribute(hConsole, pointed_color_card);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, default_color_card);
		}

		if (Hand[i].card_id == 0)
		{
			cout << "        ";
		}
		else
		{
			cout << " |";
			switch (Hand[i].card_row)
			{
			case 1:
				cout << "Meele";
				break;
			case 2:
				cout << "Range";
				break;
			case 3:
				cout << "Siege";
				break;
			default:
				cout << "     ";
				break;
			}
			cout << "|";
		}
	}
	cout << endl << "\t";
	/*middle end*/
	

	for (int i = 0;i < card_amount;i++)//id karty
	{
		if (pointer == i + 1)
		{
			SetConsoleTextAttribute(hConsole, pointed_color_card);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, default_color_card);
		}

		if (Hand[i].card_id == 0)
		{
			cout << "        ";
		}
		else
		{
			cout << " " << ld << "-----" << pd;
		}
	}
	cout << endl << "\t";
	for (int i = 0;i < card_amount;i++)//bottom
	{
		if (pointer == i + 1)
		{
			SetConsoleTextAttribute(hConsole, pointed_color_card);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, default_color_card);
		}

		if (Hand[i].card_id == 0)
		{
			cout << "        ";
		}
		else
		{
			cout << "  " << "  " << i + 1 << "   ";
		}
	}
	cout << endl;
}

void rysuj_szereg(int szereg)
{
	//line_1
	cout << "\t\t";
	cout<< lg;
	for (int i = 0;i < 80;i++)
	{
		cout << dwieLinia;
	}
	cout << pg << endl;
	//line_2
	cout << "\t\t";
	cout << VdwieLinia;
	for (int i = 0;i < 20;i++)
	{
		if (row[i].card_id == 0)
		{
			cout << "    ";
		}
		else
		{
			cout << " " << lg << jednaLinia << pg;
		}
	}
	cout << VdwieLinia<<endl;
	//line_3
	cout << "\t\t";
	cout << VdwieLinia;
	for (int i = 0;i < 20;i++)
	{
		if (row[i].card_id == 0)
		{
			cout << "    ";
		}
		else
		{
			cout << " " << VjednaLinia << row[i].card_power << VjednaLinia;
		}
	}
	cout << VdwieLinia << endl;
	//line_4
	cout << "\t\t";
	cout << VdwieLinia;
	for (int i = 0;i < 20;i++)
	{
		if (row[i].card_id == 0)
		{
			cout << "    ";
		}
		else
		{
			cout << " " << ld << jednaLinia << pd;
		}
	}
	cout << VdwieLinia << endl;
	//line_5
	cout << "\t\t";
	cout << ld;
	for (int i = 0;i < 80;i++)
	{
		cout << dwieLinia;
	}
	cout << pd << endl;
}

int game_location(int pointer)
{
	int key_pressed{};
	key_pressed = _getch();

	switch (key_pressed)
	{
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return key_pressed - '0';//wyluskuje liczbe zamiast chara
	case '0'://karta nr 10
		return 10;//inaczej nie dziala
	case 13:
		Play_card(pointer-1);
		return pointer;
	case 45://karta nr 11
		return 11;
	case 61://karta nr 12
		return 12;

	case 75://72 to cyfra okreslajaca strzalek w gore
		if (pointer > 1)
		{
			return pointer - 1;
		}
	case 77://strzalek w dol
		if (pointer < 12)
		{
			return pointer + 1;
		}

	default:

		/*test klawiszy
		cout<<key_pressed;
		system("pause");
		*/
		return pointer;
		
	}
}

void Play_card(int n)
{
	Hand[n].card_id = 0;

	//szereg[0].row_cards[n].card_id = 1;
	row[n].card_id = 1;
	row[n].card_power = Hand[n].card_power;
}