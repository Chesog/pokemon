#include "gameplay.h"

int modeSelection(int& pointerCursor)
{
	bool modeSelected = false;
	do
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD consolecursorposition = { 0,0 };

		int answ;
		system("cls");
		SetConsoleTextAttribute(h, 160);
		cout << R"(
			 __    __     ______     _____     ______        _____     ______          __     __  __     ______     ______     ______    
			/\ "-./  \   /\  __ \   /\  __-.  /\  __ \      /\  __-.  /\  ___\        /\ \   /\ \/\ \   /\  ___\   /\  ___\   /\  __ \   
			\ \ \-./\ \  \ \ \/\ \  \ \ \/\ \ \ \ \/\ \     \ \ \/\ \ \ \  __\       _\_\ \  \ \ \_\ \  \ \  __\   \ \ \__ \  \ \ \/\ \  
			 \ \_\ \ \_\  \ \_____\  \ \____-  \ \_____\     \ \____-  \ \_____\    /\_____\  \ \_____\  \ \_____\  \ \_____\  \ \_____\ 
			  \/_/  \/_/   \/_____/   \/____/   \/_____/      \/____/   \/_____/    \/_____/   \/_____/   \/_____/   \/_____/   \/_____/ 
			                                                                                                                             )" << endl;
		cout << endl;
		SetConsoleTextAttribute(h, 11);
		if (pointerCursor == (int)ModeSelection::SinglePlayer)
		{
			SetConsoleTextAttribute(h, 144);
		}
		consolecursorposition = { 80,18 };
		SetConsoleCursorPosition(h, consolecursorposition);
		cout << ".---------------." << endl;
		consolecursorposition = { 80,19 };
		SetConsoleCursorPosition(h, consolecursorposition);
		cout << "| Single Player |" << endl;
		consolecursorposition = { 80,20 };
		SetConsoleCursorPosition(h, consolecursorposition);
		cout << "'---------------'" << endl;
		cout << endl;
		SetConsoleTextAttribute(h, 11);
		if (pointerCursor == (int)ModeSelection::MultiPlayer)
		{
			SetConsoleTextAttribute(h, 144);
		}
		consolecursorposition = { 80,22 };
		SetConsoleCursorPosition(h, consolecursorposition);
		cout << ".--------------." << endl;
		consolecursorposition = { 80,23 };
		SetConsoleCursorPosition(h, consolecursorposition);
		cout << "| Multi Player |" << endl;
		consolecursorposition = { 80,24 };
		SetConsoleCursorPosition(h, consolecursorposition);
		cout << "'--------------'" << endl;
		cout << endl;
		SetConsoleTextAttribute(h, 9);
		SetConsoleTextAttribute(h, 11);
		if (pointerCursor == (int)ModeSelection::exitToMenu)
		{
			SetConsoleTextAttribute(h, 144);
		}
		consolecursorposition = { 80,26 };
		SetConsoleCursorPosition(h, consolecursorposition);
		cout << ".----------------." << endl;
		consolecursorposition = { 80,27 };
		SetConsoleCursorPosition(h, consolecursorposition);
		cout << "| Volver al Menu |" << endl;
		consolecursorposition = { 80,28 };
		SetConsoleCursorPosition(h, consolecursorposition);
		cout << "'----------------'" << endl;
		cout << endl;
		SetConsoleTextAttribute(h, 9);
		cout << "\t""Usar W para subir" << endl;
		cout << "\t""Usar S para bajar" << endl;
		cout << "\t""Usar E para selecionar" << endl;

		answ = pointer((int)ModeSelection::exitToMenu, (int)ModeSelection::SinglePlayer, pointerCursor);
		if (answ == (int)ModeSelection::SinglePlayer)
		{
			singlePLayer(pointerCursor);
		}
		else if (answ == (int)ModeSelection::MultiPlayer)
		{
			multiPlayer(pointerCursor);
		}
		else if (answ == (int)ModeSelection::exitToMenu)
		{
			modeSelected = true;
		}
	} while (!modeSelected);

	return 0;
}
void singlePLayer(int& pointerCursor)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD consolecursorposition = { 0,0 };

	Player player1;
	Player CPU;

	int playerAnsw;
	int pokemonlvl1Lifes = 1;
	int pokemonlvl2Lifes = 3;
	int pokemonlvl3Lifes = 5;
	int pokemonlvl1Deff = 500;
	int pokemonlvl2Deff = 1000;
	int pokemonlvl3Deff = 1500;

	string player1Name;
	system("cls");
	cout << "\t""\t""Antes que nada como te llamas ?" << endl;
	cout << endl;
	cout << "\t""\t""User ---> ";
	cin >> player1Name;
	player1.name = player1Name;
	cout << endl;
	cout << "Bienvenido " << player1.name;
	Pokemon pokemon1Player = pokemonMaker(pointerCursor, player1,'a',pokemonlvl1Lifes,1, pokemonlvl1Deff);
	player1.pokemonTeam[0] = pokemon1Player;
	Pokemon pokemon2Player = pokemonMaker(pointerCursor, player1,'b',pokemonlvl1Lifes,1, pokemonlvl1Deff);
	player1.pokemonTeam[1] = pokemon2Player;
	Pokemon pokemon3Player = pokemonMaker(pointerCursor, player1,'c',pokemonlvl1Lifes,1, pokemonlvl1Deff);
	player1.pokemonTeam[2] = pokemon3Player;
	Pokemon pokemon4Player = pokemonMaker(pointerCursor, player1,'d',pokemonlvl2Lifes,2, pokemonlvl2Deff);
	player1.pokemonTeam[3] = pokemon4Player;
	Pokemon pokemon5Player = pokemonMaker(pointerCursor, player1,'e',pokemonlvl2Lifes,2, pokemonlvl2Deff);
	player1.pokemonTeam[4] = pokemon5Player;
	Pokemon pokemon6Player = pokemonMaker(pointerCursor, player1,'f',pokemonlvl3Lifes,3, pokemonlvl3Deff);
	player1.pokemonTeam[5] = pokemon6Player;

	cout << "pepe" << endl;

	system("pause");


}
void multiPlayer(int& pointerCursor)
{
	system("cls");
	cout << "MultiPlayer" << endl;
	system("pause");
}
Pokemon pokemonMaker(int& pointerCursor, Player actualPlayer,char pokemonTag,int PokemonLifes,int PokemonLevel,int PokemonDeff)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD consolecursorposition = { 0,0 };

	Pokemon aux;
	string pokeName;
	bool attkSelected = false;

	system("cls");
	SetConsoleTextAttribute(h, 96);
	cout << R"(
						 _____                     _           _         _____       _                         
						|  _  | ___  _____  ___  _| | ___    _| | ___   |  _  | ___ | |_  ___  _____  ___  ___ 
						|     ||  _||     || .'|| . || . |  | . || -_|  |   __|| . || '_|| -_||     || . ||   |
						|__|__||_|  |_|_|_||__,||___||___|  |___||___|  |__|   |___||_,_||___||_|_|_||___||_|_|
						                                                                                       )" << endl;
	cout << endl;
	cout << "\t""\t""Como se va a llamar tu pokemon ?" << endl;
	cout << actualPlayer.name << " ---> ";
	cin >> pokeName;
	aux.name;
	do
	{

		SetConsoleTextAttribute(h, 14);
		if (pointerCursor == (int)ModeSelection::exitToMenu)
		{
			SetConsoleTextAttribute(h, 144);
		}
		consolecursorposition = { 80,26 };
		SetConsoleCursorPosition(h, consolecursorposition);
		cout << ".----------------." << endl;
		consolecursorposition = { 80,27 };
		SetConsoleCursorPosition(h, consolecursorposition);
		cout << "| Volver al Menu |" << endl;
		consolecursorposition = { 80,28 };
		SetConsoleCursorPosition(h, consolecursorposition);
		cout << "'----------------'" << endl;
		cout << endl;

	} while (!attkSelected);
	return aux;
}