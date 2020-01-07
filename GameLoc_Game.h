#pragma once


using namespace std;

struct cards 
{
	int card_id;// gdy card id==0 wtedy ta karta nie istnieje lepiej to nazwac card_exist - do zrobienia
	
	int card_type;
	/* Okresla czym jest dana karta- kazda wartosc liczbowa to inny typ i jest inaczej interpretowana przez funkcje
		1-stwor (card_power = sila karty)
		2-efekt pogodowy (card_power = nieistotny)

	*/
	int card_power;//moc karty

	int card_row;
	/*okresla szereg na ktory bedzie miala wplyw karta(inaczej mowiac na ktorym mozna ja postawic) 
	1-meele
	2-archer
	3-catapult

	!!!w przypadku efektow pogodowych jest to szereg na ktory ma wplyw pogoda
	*/

};

struct row_board
{
	cards row_cards[20];
};

void GameLoc_Game();
void game_Resolution();
void game_render(int);
int game_location(int);

//game_render
void rysuj_karty(int);
void rysuj_szereg(int);

//game_mechanics
void Play_card(int);