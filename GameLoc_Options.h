#pragma once

#include <string>

using namespace std;

struct options_options //wszystkie wybory menu
{
	string option_name;
	string option_one;
	string option_two;
	int option_id;//to oznacza czy opcja 1 czy opcja 2 jest wybrana
	string info;
};

void GameLoc_Options();

void options_render(int);
int options_location(int);
bool check_option(int);