#pragma once
#include <iostream>
#include <Windows.h>

#include "cursor.h"

using namespace std;

struct Pokemon 
{
	string name;
	char tag;
	int lifes;
	int level;
	int Deff;
	string attk1Name;
	int attk1Damage;
	string attk2Name;
	int attk2Damage;
	string attk3Name;
	int attk3Damage;
};
struct Player
{
	string name;
	int pokemonCount;
	Pokemon pokemonTeam[6];
};

enum class ModeSelection {SinglePlayer = 1,MultiPlayer,exitToMenu};

int modeSelection(int& pointerCursor);
void singlePLayer(int& pointerCursor);
void multiPlayer(int& pointerCursor);
Pokemon pokemonMaker(int& pointerCursor, Player actualPlayer, char pokemonTag, int PokemonLifes, int PokemonLevel, int PokemonDeff);