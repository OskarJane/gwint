#include<iostream>
#include <windows.h>
#include<conio.h>
#include <iomanip>

#include"GameLoc_Game.h"
#include"Game_ai.h"
#include"END_screens.h"

using namespace std;

#pragma region znaki_zmienne.
char lg = 201;//╔
char pg = 187;//╗
char ld = 200;//╚
char pd = 188;//╝

char jednaLinia = 196;//-
char dwieLinia = 205;//=
char VjednaLinia = 124;//|
char VdwieLinia = 186;//|
#pragma endregion

#pragma region kolory.
int pointed_color_card = 11;
int default_color_card = 14;
#pragma endregion

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
cards Hand_ai[12] =
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
cards row[12] =
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
	{0,0,0,0}

};

row_board szereg[6]=
{
	{row[12],0},
	{row[12],0},
	{row[12],0},
	{row[12],0},
	{row[12],0},
	{row[12],0}
};
int lives[2] = { 2,2 };

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


	for (int i = 0;i < 7;i++)
	{
		cout <<endl;
	}

	
	cout << endl;

	cout <<endl;
	for (int i = 6;i >= 4;i--)
	{
		rysuj_szereg(i);
	}

	//lifes/ai
	cout <<"\t"<<"Zycia: ";
	for (int i = 0;i < lives[1];i++)
	{
		cout << "(X) ";

	}
	cout << "\t\t" << "Suma AI_POWER: " << suma_sil_ALL(3);
	cout << endl;

	SetConsoleTextAttribute(hConsole, 120);
	for (int i = 0;i < 120;i++)
	{
		cout <<dwieLinia;
	}
	cout << endl;//Polowa stolu
	SetConsoleTextAttribute(hConsole, 7);

	//lifes/player
	cout << "\t" << "Zycia: ";
	for (int i = 0;i < lives[0];i++)
	{
		cout <<"(X) ";
		
	}
	cout << "\t\t" << "Suma Pl_POWER: " << suma_sil_ALL(0);
	cout << endl;

	for (int i = 1;i <= 3;i++)
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

	//rysuj karty
	int card_amount = 12;//placeholder- to ma byc pobierane ze struktury

	cout << "\t";
	for (int i = 0;i < card_amount;i++)//top
	{
		draw_card(1, pointer, i);
	}
	//pass
	draw_pass(1, pointer);	
	cout << endl<<"\t";
	/*middle*/
	for (int i = 0;i < card_amount;i++)
	{
		draw_card(2, pointer, i);
	}
	//pass
	draw_pass(2, pointer);

	cout << endl << "\t";
	for (int i = 0;i < card_amount;i++)
	{
		draw_card(3, pointer, i);
	}
	draw_pass(3, pointer);

	cout << endl << "\t";

	for (int i = 0;i < card_amount;i++)
	{
		draw_card(4, pointer,i);
	}
	//pass
	draw_pass(4, pointer);

	cout << endl << "\t";
	for (int i = 0;i < card_amount;i++)
	{
		draw_card(5, pointer, i);
	}
	//pass
	draw_pass(5, pointer);

	cout << endl << "\t";
	for (int i = 0;i < card_amount;i++)
	{
		draw_card(6, pointer, i);
	}
	draw_pass(6, pointer);
	cout << endl << "\t";
	/*middle end*/
	

	for (int i = 0;i < card_amount;i++)//id karty
	{
		draw_card(7, pointer, i);
	}
	draw_pass(7, pointer);
	cout << endl << "\t";


	for (int i = 0;i < card_amount;i++)//bottom
	{
		draw_card(8, pointer, i);	
	}
	draw_pass(8, pointer);
	cout << endl;
}
#pragma region under_rysujkarty.
void draw_pass(int linia,int pointer)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (pointer == 13)
	{
		SetConsoleTextAttribute(hConsole, pointed_color_card);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, default_color_card);
	}

	switch (linia)
	{
	case 1:
		cout << " " << lg << "----" << pg;
		break;
	case 2:
		cout << " " << "|    |";
		break;
	case 3:
		cout << " " << "|    |";
		break;
	case 4:
		cout << " " << "|PASS|";
		break;
	case 5:
		cout << " " << "|    |";
		break;
	case 6:
		cout << " " << "|    |";
		break;
	case 7:
		cout << " " << ld << "----" << pd;
		break;
	case 8:
		cout << "  " << "PASS";
		break;
	}
}
void draw_card(int linia, int pointer,int i)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (pointer == i + 1)
	{
		SetConsoleTextAttribute(hConsole, pointed_color_card);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, default_color_card);
	}

	if (Hand[i].card_id == 0 && linia!=8)
	{
		cout << "        ";
	}
	else
	{
	switch (linia)
	{
	case 1:
			cout << " " << lg << "-----" << pg;
		break;
	case 2:
			cout << " |     |";
		break;
	case 3:
			cout << " |  " << Hand[i].card_power << "  |";
		break;
	case 4:
			cout << " |     |";
		break;
	case 5:
			cout << " |";
			if (Hand[i].card_type == 1)
			{
				cout << "Stwor";
			}
			else
			{
				cout << "     ";
			}
			cout << "|";		
		break;
	case 6:
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
		break;
	case 7:
			cout << " " << ld << "-----" << pd;
		break;
	case 8:
		cout << " " << "  " << setw(2) << i + 1 << "   ";
		break;
	}
	}//else
}
#pragma endregion

void rysuj_szereg(int szereg_output)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	string szereg_nazwa = "";
	int card_amount = 12;
	//line_1
	cout << "\t\t\t";
	cout<< lg;
	for (int i = 0;i < card_amount*4;i++)
	{
		cout << dwieLinia;
	}
	cout << pg;
	//right banner_1
	cout << "  " << lg << dwieLinia << dwieLinia << dwieLinia<< dwieLinia<< dwieLinia << pg << endl;
	//line_2
	cout << "\t\t\t";
	cout << VdwieLinia;
	for (int i = 0;i < card_amount;i++)
	{
		if (szereg[szereg_output].row_cards[i].card_id == 0)
		{
			cout << "    ";
		}
		else
		{
			cout << " " << lg << jednaLinia << pg;
		}
	}
	cout << VdwieLinia;
	//right banner_2
	switch (szereg_output)
	{
	case 1:
		szereg_nazwa = "MEELE";
		break;
	case 2:
		szereg_nazwa = "RANGE";
		break;
	case 3:
		szereg_nazwa = "SIEGE";
		break;
	case 4:
		szereg_nazwa = "MEELE";
		break;
	case 5:
		szereg_nazwa = "RANGE";
		break;
	case 6:
		szereg_nazwa = "SIEGE";
		break;
	default:
		szereg_nazwa = "     ";
		break;
	}
	cout << "  " << VdwieLinia << szereg_nazwa << VdwieLinia << endl;
	//line_3
	cout << "\t\t\t";
	cout << VdwieLinia;
	for (int i = 0;i < card_amount;i++)
	{
		if (szereg[szereg_output].row_cards[i].card_id == 0)
		{
			cout << "    ";
		}
		else
		{
			cout << " " << VjednaLinia << szereg[szereg_output].row_cards[i].card_power<< VjednaLinia;
		}
	}
	cout << VdwieLinia;
	//right banner_3
	cout << "  " << VdwieLinia << " ";
	SetConsoleTextAttribute(hConsole, 13);
		cout << setw(3) << suma_sil(szereg_output, card_amount);
	SetConsoleTextAttribute(hConsole, 7);
	cout<< " " << VdwieLinia << endl;
	//line_4
	cout << "\t\t\t";
	cout << VdwieLinia;
	for (int i = 0;i < card_amount;i++)
	{
		if (szereg[szereg_output].row_cards[i].card_id == 0)
		{
			cout << "    ";
		}
		else
		{
			cout << " " << ld << jednaLinia << pd;
		}
	}
	cout << VdwieLinia;
	//right banner_4
	cout << "  " << VdwieLinia << " Suma" << VdwieLinia << endl;
	//line_5
	cout << "\t\t\t";
	cout << ld;
	for (int i = 0;i < card_amount*4;i++)
	{
		cout << dwieLinia;
	}
	cout << pd;
	//right banner_5
	cout <<"  "<< ld << dwieLinia << dwieLinia << dwieLinia << dwieLinia << dwieLinia<< pd<< endl;
}

int game_location(int pointer)
{
	int key_pressed{};
	key_pressed = _getch();

	bool card_played = false;

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
		card_played=Play_card(pointer-1,0);
		if (card_played == true)
		{
			Ai_turn();
		}
		return pointer;
	case 45://karta nr 11
		return 11;
	case 61://karta nr 12
		return 12;
	case 'p'://karta nr PASS
		return 13;
	case 75://72 to cyfra okreslajaca strzalek w gore
		if (pointer > 1)
		{
			return pointer - 1;
		}
	case 77://strzalek w dol
		if (pointer < 13)
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

bool Play_card(int n, int player_id)
{
	if (n == 12)
	{
		if (player_id == 3)
		{
			cout << "AI has passed" << endl;
			system("pause");
		}
		Play_pass();
	}
	else
	{ 
		cards *whos_hand = Hand;
		if (player_id == 3)
		{		
			whos_hand = Hand_ai;
		}

		//check exist
		if (whos_hand[n].card_id == 0)
		{
			return false;
		}

		
		whos_hand[n].card_id = 0;
	int liczba = szereg[whos_hand[n].card_row+player_id].actual_id;
	//wstawienie karty
	szereg[whos_hand[n].card_row + player_id].row_cards[liczba].card_id = 1;
	szereg[whos_hand[n].card_row + player_id].row_cards[liczba].card_power = Hand[n].card_power;
	szereg[whos_hand[n].card_row + player_id].actual_id++;
	}
	return true;
}

void Play_pass()
{
	check_round_results();
}



int suma_sil(int szereg_output,int card_amount)
{
	int suma = 0;
	for (int i = 0;i < card_amount;i++)
	{
		if (szereg[szereg_output].row_cards[i].card_id != 0)
		{
			suma = suma + szereg[szereg_output].row_cards[i].card_power;
		}
	}
	return suma;
}

int suma_sil_ALL(int player_id)
{
	int suma{};
	for (int i = 1;i <= 3;i++)
	{
		suma=suma+suma_sil(i + player_id, 12);
	}
	return suma;
}

void check_round_results()
{
	int player_POWER = 0;
	int ai_POWER = 0;

	for (int i = 1;i <= 3;i++)
	{
		player_POWER += suma_sil(i, 12);
	}

	for (int i = 1;i <= 3;i++)
	{
		ai_POWER += suma_sil(i+3, 12);
	}
	

	if (player_POWER > ai_POWER)
	{
		lives[1]--;
	}
	else
	if (player_POWER == ai_POWER)
	{
		lives[1]--;
		lives[0]--;
	}
	else
	if (player_POWER < ai_POWER)
	{
		lives[0]--;
	}

	if (lives[0] == 0 && lives[1] == 0)
		{
			tie_screen();
		}
	else
		if(lives[1]==0)
		{
			victory_screen();
		}
	else
		if (lives[0] == 0)
		{
			defeat_screen();
		}

	clear_board();
}

void clear_board()
{
	for(int j=0;j<=6;j++)
	{ 
		for (int i = 0;i < 12;i++)
		{
			szereg[j].row_cards[i].card_id = 0;
			szereg[j].row_cards[i].card_power = 0;
		}
		szereg[j].actual_id = 0;	
	}

}