#include"Game_ai.h"
#include<iostream>
#include<windows.h>
#include<ctime>

#include"GameLoc_Game.h"

using namespace std;



void Ai_turn()
{
	//symulacja plynnosci ai
	game_render(1);
	Sleep(150);

	
	int random_card = rand()%12;

	bool card_played = Play_card(random_card, 3);
	if (card_played == false)
	{
		Ai_turn(0);
	}
}

void Ai_turn(int n)
{
	if (n == 12)
	{
		Play_card(12, 3);
	}
	else
	{ 

		bool card_played = Play_card(n, 3);
		if (card_played == false)
		{
			Ai_turn(n+1);
		}
	}
}
