#include"Game_ai.h"
#include<iostream>
#include<windows.h>
#include<ctime>

#include"GameLoc_Game.h"

using namespace std;

//!!! JEZELI BOT NIE MA KART TO PRZY TURZE AI PROGRAM SIE SYPIE!!!!!

void Ai_turn()
{
	//symulacja plynnosci ai
	game_render(1);
	Sleep(200);

	if (licznik_kart_ai() != 0)
	{
		Ai_turn(0);
	}
	else
	{
		Play_pass(3);
	}
}

void Ai_turn(int n)
{
			if (n == 12)
			{
				Play_pass(3);
			}

	int losowa = rand() % 12;

	if (Ai_pseudo_intelligence() == false)
	{
			{ 

				bool card_played = Play_card(losowa, 3);
				if (card_played == false)
				{
					Ai_turn(n+1);
				}
			}
	}
}

bool Ai_pseudo_intelligence()
{
	int ai_power = suma_sil_ALL(3);
	int player_power = suma_sil_ALL(0);

			if(INFO_ai_lifes()>1)
			{ 
				//bot pasuje jezeli ma przewage 5 pkt
				if (ai_power > player_power+5)
				{
					Play_pass(3);
					return true;
				}

				//bot oddaje ture jak gracz ma przewage ponad 7 pkt
				if (ai_power+7 < player_power )
				{
					Play_pass(3);
					return true;
				}
			}//INFO_ai_lifes


		//gdy gracz spasuje bot wygrywa ture jak ma wiecej sily
		if (INFO_player_pass() == true)
		{
			if (ai_power > player_power)
			{
				Play_pass(3);
			}
		}

		


	return false;
}