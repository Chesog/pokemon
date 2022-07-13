#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>

#include "cursor.h"

using namespace std;


struct Pokemon
{
	string name;
	int position{};
	char tag{};
	int lifes{};
	int level{};
	int Deff{};
	string attk1Name{};
	int attk1Damage{};
	string attk2Name{};
	int attk2Damage{};
	string attk3Name{};
	int attk3Damage{};

	int pokemonlvl1DeffDefault = 500;
	int pokemonlvl2DeffDefault = 1000;
	int pokemonlvl3DeffDefault = 1500;
};
struct Player
{
	string name{};
	int pokemonCount{};
	Pokemon pokemonTeam[6]{};
	bool playerAtakerSelection = false;
	bool playerDefenderSelection = false;
	bool playerAttkSelection = false;
};

struct PointerCursorBoard
{
	int posX{};
	int posY{};
	bool selected;
};

enum class ModeSelection { SinglePlayer = 1, MultiPlayer, exitToMenu };

int modeSelection(int& pointerCursor);
void singlePLayer(int& pointerCursor);
void multiPlayer(int& pointerCursor);
void showBoard(Player actualPlayer1, Player actualPlayer2, char boardArrayPlayer1[2][6], char boardArrayPlayer2[2][6], int maxRows, int maxColumns);
void battle(Player& actualPlayer1, Player& actualPlayer2, char boardArrayPlayer1[2][6], char boardArrayPlayer2[2][6], int pokemonAttaker, int pokemonDefender, int attkUsed, int turn, int deffLevel);
void boardReset(char boardArrayPlayer1[2][6], char boardArrayPlayer2[2][6]);
Pokemon pokemonMaker(Player actualPlayer, char pokemonTag, int PokemonLifes, int PokemonLevel, int PokemonDeff, int& PokemonsToPlace, int Pokemonposition);
Player cpuMaker();