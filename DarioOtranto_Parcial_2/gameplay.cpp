#include "gameplay.h"

int modeSelection(int& pointerCursor)
{
	bool modeSelected = false;
	pointerCursor == (int)ModeSelection::SinglePlayer;
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
	srand(time(NULL));

	Player player1;
	Player CPU;

	const int maxRows = 2;
	const int maxColumns = 6;

	int playerAnsw;
	int pokemonlvl1Lifes = 1;
	int pokemonlvl2Lifes = 3;
	int pokemonlvl3Lifes = 5;
	int pokemonlvl1Deff = 500;
	int pokemonlvl2Deff = 1000;
	int pokemonlvl3Deff = 1500;
	int pokemonsToPlace = 6;

	char boardArrayPlayer1[maxRows][maxColumns]{};
	char boardArrayPlayer2[maxRows][maxColumns]{};

	boardReset(boardArrayPlayer1, boardArrayPlayer2);

	string player1Name;
	system("cls");
	cout << "\t""\t""Antes que nada como te llamas ?" << endl;
	cout << endl;
	cout << "\t""\t""User ---> ";
	cin >> player1Name;
	player1.name = player1Name;
	cout << endl;
	cout << "\t""\t""Bienvenido " << player1.name << endl;
	cout << "\t""\t""Ahora vamos a pasar a nombrar tus 6 pokemones" << endl;
	cout << "\t""\t""Y vamos a ponerle nombre a sus ataques" << endl;
	cout << endl;
	system("pause");
	Pokemon pokemon1Player = pokemonMaker(player1, 'a', pokemonlvl1Lifes, 1, pokemonlvl1Deff, pokemonsToPlace, 1);
	player1.pokemonTeam[0] = pokemon1Player;
	player1.pokemonCount++;
	Pokemon pokemon2Player = pokemonMaker(player1, 'b', pokemonlvl1Lifes, 1, pokemonlvl1Deff, pokemonsToPlace, 2);
	player1.pokemonTeam[1] = pokemon2Player;
	player1.pokemonCount++;
	Pokemon pokemon3Player = pokemonMaker(player1, 'c', pokemonlvl1Lifes, 1, pokemonlvl1Deff, pokemonsToPlace, 3);
	player1.pokemonTeam[2] = pokemon3Player;
	player1.pokemonCount++;
	Pokemon pokemon4Player = pokemonMaker(player1, 'd', pokemonlvl2Lifes, 2, pokemonlvl2Deff, pokemonsToPlace, 4);
	player1.pokemonTeam[3] = pokemon4Player;
	player1.pokemonCount++;
	Pokemon pokemon5Player = pokemonMaker(player1, 'e', pokemonlvl2Lifes, 2, pokemonlvl2Deff, pokemonsToPlace, 5);
	player1.pokemonTeam[4] = pokemon5Player;
	player1.pokemonCount++;
	Pokemon pokemon6Player = pokemonMaker(player1, 'f', pokemonlvl3Lifes, 3, pokemonlvl3Deff, pokemonsToPlace, 6);
	player1.pokemonTeam[5] = pokemon6Player;
	player1.pokemonCount++;

	CPU = cpuMaker();
	system("cls");

	PointerCursorBoard cursorBoard;
	int PokemonToPlace = 6;
	bool positionModeSelected = false;
	int manual = 1;
	int automatic = 2;
	int backToMenu = 14;
	playerAnsw = 0;
	pointerCursor = 1;
	do
	{
		system("cls");
		SetConsoleTextAttribute(h, 14);
		cout << "\t""\t""\t""\t""\t""\t""\t"".------------------------------------------." << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""| Como quiere que se ordenen los pokemones |" << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""'------------------------------------------'" << endl;
		cout << endl;
		if (pointerCursor == manual)
		{
			SetConsoleTextAttribute(h, 224);
		}
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t"".-------------." << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t""| Modo Manual |" << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t""'-------------'" << endl;
		SetConsoleTextAttribute(h, 14);
		if (pointerCursor == automatic)
		{
			SetConsoleTextAttribute(h, 224);
		}
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t"".-----------------." << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t""| Modo Automatico |" << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t""'-----------------'" << endl;
		SetConsoleTextAttribute(h, 14);
		cout << endl;
		SetConsoleTextAttribute(h, 11);
		cout << "\t""Usar W para subir" << endl;
		cout << "\t""Usar S para bajar" << endl;
		cout << "\t""Usar E para selecionar" << endl;
		cout << "\t""Usar P para Volver al menu" << endl;
		playerAnsw = pointer(2, 1, pointerCursor);
		if (playerAnsw != 0)
		{
			if (playerAnsw == backToMenu)
			{
				return;
			}
			else
			{
				positionModeSelected = true;
			}
		}
	} while (!positionModeSelected);

	if (playerAnsw == 1)
	{
		for (int i = 0; i < player1.pokemonCount; i++)
		{
			system("cls");
			SetConsoleTextAttribute(h, 14);
			cout << "\t""\t""Pokemones por Colocar " << PokemonToPlace << endl;
			showBoard(player1, CPU, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
			SetConsoleTextAttribute(h, 13);
			cout << "\t""\t""Selecione la posicion donde va a ir el pokemon" << endl;
			cout << "\t""\t""Del 1 al 2" << endl;
			cout << "\t""\t""Fila ---> ";
			cin >> cursorBoard.posY;
			cout << "\t""\t""Del 1 al 6" << endl;
			cout << "\t""\t""Columna ---> ";
			cin >> cursorBoard.posX;
			if (boardArrayPlayer1[cursorBoard.posY - 1][cursorBoard.posX - 1] == 0)
			{
				boardArrayPlayer1[cursorBoard.posY - 1][cursorBoard.posX - 1] = player1.pokemonTeam[i].tag;
				PokemonToPlace--;
			}
			else if (cursorBoard.posY - 1 > maxRows || cursorBoard.posX - 1 > maxColumns)
			{
				cout << "\t""\t""Fuera De Rango" << endl;
				system("pause");
				i--;
			}
			else
			{
				cout << "\t""\t""Ya hay un pokemon en este espacio" << endl;
				system("pause");
				i--;
			}
		}
	}
	else if (playerAnsw == 2)
	{
		for (int i = 0; i < player1.pokemonCount; i++)
		{
			cursorBoard.posY = rand() % 2;
			cursorBoard.posX = rand() % 6;
			if (boardArrayPlayer1[cursorBoard.posY][cursorBoard.posX] == 0)
			{
				boardArrayPlayer1[cursorBoard.posY][cursorBoard.posX] = player1.pokemonTeam[i].tag;
				PokemonToPlace--;
			}
			else
			{
				i--;
			}
		}
	}
	else
	{
		return;
	}

	for (int i = 0; i < CPU.pokemonCount; i++)
	{
		cursorBoard.posY = rand() % 2;
		cursorBoard.posX = rand() % 6;
		if (boardArrayPlayer2[cursorBoard.posY][cursorBoard.posX] == 0)
		{
			boardArrayPlayer2[cursorBoard.posY][cursorBoard.posX] = CPU.pokemonTeam[i].tag;
			PokemonToPlace--;
		}
		else
		{
			i--;
		}

	}
	system("cls");

	int turn = 0;
	int exitToMenu = 14;
	int pokemonAttaker = 0;
	int pokemonDefender = 0;
	int attkUsed = 0;
	bool endCondition = false;
	pointerCursor = 1;
	do
	{
		srand(time(NULL));
		if (turn == 0)
		{
			player1.playerAtakerSelection = false;
			player1.playerDefenderSelection = false;
			player1.playerAttkSelection = false;
			do
			{
				system("cls");
				showBoard(player1, CPU, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
				SetConsoleTextAttribute(h, 11);
				cout << "\t""\t""Seleccione el pokemon con el que va a atacar" << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 14);
				if (player1.pokemonTeam[0].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[0].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[0].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[0].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[0].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[0].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[0].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[0].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[1].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[1].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[1].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[1].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[1].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[1].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[1].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[1].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[2].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[2].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[2].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[2].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[2].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[2].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[2].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[2].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[3].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[3].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[3].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[3].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[3].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[3].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[3].tag << endl;

					}
					cout << "\t""\t" << player1.pokemonTeam[3].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[4].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[4].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[4].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[4].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[4].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[4].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[4].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[4].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[5].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[5].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[5].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[5].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[5].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[5].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[5].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[5].name << endl;
				}
				else
				{
					pointerCursor++;
				}
				SetConsoleTextAttribute(h, 14);
				cout << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""Usar W para subir" << endl;
				cout << "\t""Usar S para bajar" << endl;
				cout << "\t""Usar E para selecionar" << endl;
				cout << "\t""Usar P para Volver al menu" << endl;
				pokemonAttaker = pointer(6, 1, pointerCursor);
				if (pokemonAttaker != 0)
				{
					if (pokemonAttaker == exitToMenu)
					{
						pokemonAttaker;
						return;
					}
					else
					{
						player1.playerAtakerSelection = true;
					}
				}
			} while (!player1.playerAtakerSelection);
			do
			{
				system("cls");
				showBoard(player1, CPU, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
				SetConsoleTextAttribute(h, 11);
				cout << "\t""\t""Seleccione el pokemon al que va a atacar" << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 14);
				if (CPU.pokemonTeam[0].lifes > 0)
				{
					if (pointerCursor == CPU.pokemonTeam[0].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << CPU.pokemonTeam[0].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << CPU.pokemonTeam[0].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << CPU.pokemonTeam[0].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << CPU.pokemonTeam[0].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << CPU.pokemonTeam[0].tag << endl;
					}
					cout << "\t""\t" << CPU.pokemonTeam[0].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (CPU.pokemonTeam[1].lifes > 0)
				{
					if (pointerCursor == CPU.pokemonTeam[1].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << CPU.pokemonTeam[1].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << CPU.pokemonTeam[1].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << CPU.pokemonTeam[1].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << CPU.pokemonTeam[1].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << CPU.pokemonTeam[1].tag << endl;
					}
					cout << "\t""\t" << CPU.pokemonTeam[1].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (CPU.pokemonTeam[2].lifes > 0)
				{
					if (pointerCursor == CPU.pokemonTeam[2].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << CPU.pokemonTeam[2].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << CPU.pokemonTeam[2].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << CPU.pokemonTeam[2].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << CPU.pokemonTeam[2].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << CPU.pokemonTeam[2].tag << endl;
					}
					cout << "\t""\t" << CPU.pokemonTeam[2].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (CPU.pokemonTeam[3].lifes > 0)
				{
					if (pointerCursor == CPU.pokemonTeam[3].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << CPU.pokemonTeam[3].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << CPU.pokemonTeam[3].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << CPU.pokemonTeam[3].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << CPU.pokemonTeam[3].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << CPU.pokemonTeam[3].tag << endl;

					}
					cout << "\t""\t" << CPU.pokemonTeam[3].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (CPU.pokemonTeam[4].lifes > 0)
				{
					if (pointerCursor == CPU.pokemonTeam[4].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << CPU.pokemonTeam[4].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << CPU.pokemonTeam[4].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << CPU.pokemonTeam[4].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << CPU.pokemonTeam[4].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << CPU.pokemonTeam[4].tag << endl;
					}
					cout << "\t""\t" << CPU.pokemonTeam[4].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (CPU.pokemonTeam[5].lifes > 0)
				{
					if (pointerCursor == CPU.pokemonTeam[5].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << CPU.pokemonTeam[5].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << CPU.pokemonTeam[5].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << CPU.pokemonTeam[5].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << CPU.pokemonTeam[5].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << CPU.pokemonTeam[5].tag << endl;
					}
					cout << "\t""\t" << CPU.pokemonTeam[5].name << endl;
				}
				else
				{
					pointerCursor++;
				}
				SetConsoleTextAttribute(h, 14);
				cout << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""Usar W para subir" << endl;
				cout << "\t""Usar S para bajar" << endl;
				cout << "\t""Usar E para selecionar" << endl;
				cout << "\t""Usar P para Volver al menu" << endl;
				pokemonDefender = pointer(6, 1, pointerCursor);
				if (pokemonDefender != 0)
				{
					if (pokemonDefender == exitToMenu)
					{
						pokemonDefender;
						return;
					}
					else
					{
						player1.playerDefenderSelection = true;
					}
				}
			} while (!player1.playerDefenderSelection);
			do
			{
				system("cls");
				showBoard(player1, CPU, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
				SetConsoleTextAttribute(h, 14);
				cout << "\t""\t""Que ataque vas a usar" << endl;
				cout << endl;
				if (pointerCursor == 1)
				{
					SetConsoleTextAttribute(h, 224);
					consolecursorposition = { 80,13 };
					SetConsoleCursorPosition(h, consolecursorposition);
					cout << "\t""\t" << "Damage " << CPU.pokemonTeam[pokemonAttaker - 1].attk1Damage << endl;
				}
				cout << "\t""\t" << player1.pokemonTeam[pokemonAttaker - 1].attk1Name << endl;
				SetConsoleTextAttribute(h, 14);
				if (pointerCursor == 2)
				{
					SetConsoleTextAttribute(h, 224);
					consolecursorposition = { 80,13 };
					SetConsoleCursorPosition(h, consolecursorposition);
					cout << "\t""\t" << "Damage " << CPU.pokemonTeam[pokemonAttaker - 1].attk2Damage << endl;
				}
				cout << "\t""\t" << player1.pokemonTeam[pokemonAttaker - 1].attk2Name << endl;
				SetConsoleTextAttribute(h, 14);
				if (pointerCursor == 3)
				{
					SetConsoleTextAttribute(h, 224);
					consolecursorposition = { 80,13 };
					SetConsoleCursorPosition(h, consolecursorposition);
					cout << "\t""\t" << "Damage " << CPU.pokemonTeam[pokemonAttaker - 1].attk3Damage << endl;
				}
				cout << "\t""\t" << player1.pokemonTeam[pokemonAttaker - 1].attk3Name << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""Usar W para subir" << endl;
				cout << "\t""Usar S para bajar" << endl;
				cout << "\t""Usar E para selecionar" << endl;
				cout << "\t""Usar P para Volver al menu" << endl;
				attkUsed = pointer(3, 1, pointerCursor);
				if (attkUsed != 0)
				{
					player1.playerAttkSelection = true;
				}
			} while (!player1.playerAttkSelection);
			system("cls");
			cout << "\t""\t" << "\t""\t""Accion Jugador 1 " << endl;
			cout << endl;
			battle(player1, CPU, boardArrayPlayer1, boardArrayPlayer2, (pokemonAttaker - 1), (pokemonDefender - 1), attkUsed, turn, CPU.pokemonTeam[(pokemonDefender - 1)].level);
			cout << "\t""\t" << "\t""\t""Pokemon a atacado " << endl;
			cout << endl;
			cout << "\t""\t" << "nombre: " << CPU.pokemonTeam[(pokemonDefender - 1)].name << endl;
			cout << "\t""\t" << "Vida: " << CPU.pokemonTeam[(pokemonDefender - 1)].lifes << endl;
			cout << "\t""\t" << "Nivel: " << CPU.pokemonTeam[(pokemonDefender - 1)].level << endl;
			cout << "\t""\t" << "Defensa: " << CPU.pokemonTeam[(pokemonDefender - 1)].Deff << endl;
			turn = 1;
			system("pause");
			cout << endl;
		}
		else
		{
			pokemonAttaker = rand() % 5;
			pokemonDefender = rand() % 5;
			attkUsed = rand() % 3 + 1;
			cout << "\t""\t" << "\t""\t""Accion CPU" << endl;
			cout << endl;
			battle(player1, CPU, boardArrayPlayer1, boardArrayPlayer2, (pokemonAttaker - 1), (pokemonDefender - 1), attkUsed, turn, player1.pokemonTeam[(pokemonDefender - 1)].level);
			cout << "\t""\t" << "Pokemon a atacado " << endl;
			cout << endl;
			cout << "\t""\t" << "nombre: " << player1.pokemonTeam[(pokemonDefender - 1)].name << endl;
			cout << "\t""\t" << "Vida: " << player1.pokemonTeam[(pokemonDefender - 1)].lifes << endl;
			cout << "\t""\t" << "Nivel: " << player1.pokemonTeam[(pokemonDefender - 1)].level << endl;
			cout << "\t""\t" << "Defensa: " << player1.pokemonTeam[(pokemonDefender - 1)].Deff << endl;
			turn = 0;
			system("pause");
		}
		if (player1.pokemonCount == 0)
		{
			endCondition = true;
		}
		else if (CPU.pokemonCount == 0)
		{
			endCondition = true;
		}

	} while (!endCondition);
	if (player1.pokemonCount == 0)
	{
		SetConsoleTextAttribute(h, 10);
		system("cls");
		cout << "\t""\t""Felicidades " << player1.name << "Ganaste" << endl;
		system("pause");
	}
	else
	{
		SetConsoleTextAttribute(h, 12);
		system("cls");
		cout << "\t""\t""Felicidades " << CPU.name << "Ganaste" << endl;
		system("pause");
	}
}
void multiPlayer(int& pointerCursor)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD consolecursorposition = { 0,0 };
	srand(time(NULL));

	Player player1;
	Player player2;

	const int maxRows = 2;
	const int maxColumns = 6;

	int playerAnsw;
	int pokemonlvl1Lifes = 1;
	int pokemonlvl2Lifes = 3;
	int pokemonlvl3Lifes = 5;
	int pokemonlvl1Deff = 500;
	int pokemonlvl2Deff = 1000;
	int pokemonlvl3Deff = 1500;
	int pokemonsToPlace = 6;

	char boardArrayPlayer1[maxRows][maxColumns]{};
	char boardArrayPlayer2[maxRows][maxColumns]{};

	boardReset(boardArrayPlayer1, boardArrayPlayer2);

	string player1Name;
	system("cls");
	cout << "\t""\t""Antes que nada como te llamas Jugador 1 ?" << endl;
	cout << endl;
	cout << "\t""\t""User ---> ";
	cin >> player1Name;
	player1.name = player1Name;
	cout << endl;
	cout << "\t""\t""Bienvenido " << player1.name << endl;
	cout << "\t""\t""Ahora vamos a pasar a nombrar tus 6 pokemones" << endl;
	cout << "\t""\t""Y vamos a ponerle nombre a sus ataques" << endl;
	cout << endl;
	system("pause");
	Pokemon pokemon1Player = pokemonMaker(player1, 'a', pokemonlvl1Lifes, 1, pokemonlvl1Deff, pokemonsToPlace, 1);
	player1.pokemonTeam[0] = pokemon1Player;
	player1.pokemonCount++;
	Pokemon pokemon2Player = pokemonMaker(player1, 'b', pokemonlvl1Lifes, 1, pokemonlvl1Deff, pokemonsToPlace, 2);
	player1.pokemonTeam[1] = pokemon2Player;
	player1.pokemonCount++;
	Pokemon pokemon3Player = pokemonMaker(player1, 'c', pokemonlvl1Lifes, 1, pokemonlvl1Deff, pokemonsToPlace, 3);
	player1.pokemonTeam[2] = pokemon3Player;
	player1.pokemonCount++;
	Pokemon pokemon4Player = pokemonMaker(player1, 'd', pokemonlvl2Lifes, 2, pokemonlvl2Deff, pokemonsToPlace, 4);
	player1.pokemonTeam[3] = pokemon4Player;
	player1.pokemonCount++;
	Pokemon pokemon5Player = pokemonMaker(player1, 'e', pokemonlvl2Lifes, 2, pokemonlvl2Deff, pokemonsToPlace, 5);
	player1.pokemonTeam[4] = pokemon5Player;
	player1.pokemonCount++;
	Pokemon pokemon6Player = pokemonMaker(player1, 'f', pokemonlvl3Lifes, 3, pokemonlvl3Deff, pokemonsToPlace, 6);
	player1.pokemonTeam[5] = pokemon6Player;
	player1.pokemonCount++;

	pokemonsToPlace = 6;

	string player2Name;
	system("cls");
	cout << "\t""\t""Antes que nada como te llamas Jugador 2 ?" << endl;
	cout << endl;
	cout << "\t""\t""User ---> ";
	cin >> player2Name;
	player2.name = player2Name;
	cout << endl;
	cout << "\t""\t""Bienvenido " << player2.name << endl;
	cout << "\t""\t""Ahora vamos a pasar a nombrar tus 6 pokemones" << endl;
	cout << "\t""\t""Y vamos a ponerle nombre a sus ataques" << endl;
	cout << endl;
	system("pause");
	Pokemon pokemon1Player2 = pokemonMaker(player2, 'a', pokemonlvl1Lifes, 1, pokemonlvl1Deff, pokemonsToPlace, 1);
	player2.pokemonTeam[0] = pokemon1Player2;
	player2.pokemonCount++;
	Pokemon pokemon2Player2 = pokemonMaker(player2, 'b', pokemonlvl1Lifes, 1, pokemonlvl1Deff, pokemonsToPlace, 2);
	player2.pokemonTeam[1] = pokemon2Player2;
	player2.pokemonCount++;
	Pokemon pokemon3Player2 = pokemonMaker(player2, 'c', pokemonlvl1Lifes, 1, pokemonlvl1Deff, pokemonsToPlace, 3);
	player2.pokemonTeam[2] = pokemon3Player2;
	player2.pokemonCount++;
	Pokemon pokemon4Player2 = pokemonMaker(player2, 'd', pokemonlvl2Lifes, 2, pokemonlvl2Deff, pokemonsToPlace, 4);
	player2.pokemonTeam[3] = pokemon4Player2;
	player2.pokemonCount++;
	Pokemon pokemon5Player2 = pokemonMaker(player2, 'e', pokemonlvl2Lifes, 2, pokemonlvl2Deff, pokemonsToPlace, 5);
	player2.pokemonTeam[4] = pokemon5Player2;
	player2.pokemonCount++;
	Pokemon pokemon6Player2 = pokemonMaker(player2, 'f', pokemonlvl3Lifes, 3, pokemonlvl3Deff, pokemonsToPlace, 6);
	player2.pokemonTeam[5] = pokemon6Player2;
	player2.pokemonCount++;
	system("cls");

	// --------------------------------------- Jugador 1 Colocacion de Pokemones -------------------------------

	PointerCursorBoard cursorBoard;
	int PokemonToPlace = 6;
	bool positionModeSelected = false;
	int manual = 1;
	int automatic = 2;
	int backToMenu = 14;
	playerAnsw = 0;
	pointerCursor = 1;
	do
	{
		system("cls");
		SetConsoleTextAttribute(h, 10);
		cout << "\t""\t""\t""\t""\t""\t""\t"".----------------------------------------------------." << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""| Como quiere que se ordenen los pokemones Jugador 1 |" << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""'----------------------------------------------------'" << endl;
		cout << endl;
		if (pointerCursor == manual)
		{
			SetConsoleTextAttribute(h, 224);
		}
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t"".-------------." << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t""| Modo Manual |" << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t""'-------------'" << endl;
		SetConsoleTextAttribute(h, 14);
		if (pointerCursor == automatic)
		{
			SetConsoleTextAttribute(h, 224);
		}
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t"".-----------------." << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t""| Modo Automatico |" << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t""'-----------------'" << endl;
		SetConsoleTextAttribute(h, 14);
		cout << endl;
		SetConsoleTextAttribute(h, 11);
		cout << "\t""Usar W para subir" << endl;
		cout << "\t""Usar S para bajar" << endl;
		cout << "\t""Usar E para selecionar" << endl;
		cout << "\t""Usar P para Volver al menu" << endl;
		playerAnsw = pointer(2, 1, pointerCursor);
		if (playerAnsw != 0)
		{
			if (playerAnsw == backToMenu)
			{
				return;
			}
			else
			{
				positionModeSelected = true;
			}
		}
	} while (!positionModeSelected);

	if (playerAnsw == 1)
	{
		for (int i = 0; i < player1.pokemonCount; i++)
		{
			system("cls");
			SetConsoleTextAttribute(h, 14);
			cout << "\t""\t""Pokemones por Colocar " << PokemonToPlace << endl;
			showBoard(player1, player2, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
			SetConsoleTextAttribute(h, 13);
			cout << "\t""\t""Selecione la posicion donde va a ir el pokemon" << endl;
			cout << "\t""\t""Del 1 al 2" << endl;
			cout << "\t""\t""Fila ---> ";
			cin >> cursorBoard.posY;
			cout << "\t""\t""Del 1 al 6" << endl;
			cout << "\t""\t""Columna ---> ";
			cin >> cursorBoard.posX;
			if (boardArrayPlayer1[cursorBoard.posY - 1][cursorBoard.posX - 1] == 0)
			{
				boardArrayPlayer1[cursorBoard.posY - 1][cursorBoard.posX - 1] = player1.pokemonTeam[i].tag;
				PokemonToPlace--;
			}
			else if (cursorBoard.posY - 1 > maxRows || cursorBoard.posX - 1 > maxColumns)
			{
				cout << "\t""\t""Fuera De Rango" << endl;
				system("pause");
				i--;
			}
			else
			{
				cout << "\t""\t""Ya hay un pokemon en este espacio" << endl;
				system("pause");
				i--;
			}
		}
	}
	else if (playerAnsw == 2)
	{
		for (int i = 0; i < player1.pokemonCount; i++)
		{
			cursorBoard.posY = rand() % 2;
			cursorBoard.posX = rand() % 6;
			if (boardArrayPlayer1[cursorBoard.posY][cursorBoard.posX] == 0)
			{
				boardArrayPlayer1[cursorBoard.posY][cursorBoard.posX] = player1.pokemonTeam[i].tag;
				PokemonToPlace--;
			}
			else
			{
				i--;
			}
		}
	}
	else
	{
		return;
	}
	// --------------------------------------- Fin Jugador 1 Colocacion de Pokemones -------------------------------

	// --------------------------------------- Jugador 2 Colocacion de Pokemones -------------------------------

	PokemonToPlace = 6;
	positionModeSelected = false;
	playerAnsw = 0;
	pointerCursor = 1;
	do
	{
		system("cls");
		SetConsoleTextAttribute(h, 11);
		cout << "\t""\t""\t""\t""\t""\t""\t"".----------------------------------------------------." << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""| Como quiere que se ordenen los pokemones Jugador 2 |" << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""'----------------------------------------------------'" << endl;
		cout << endl;
		if (pointerCursor == manual)
		{
			SetConsoleTextAttribute(h, 224);
		}
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t"".-------------." << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t""| Modo Manual |" << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t""'-------------'" << endl;
		SetConsoleTextAttribute(h, 14);
		if (pointerCursor == automatic)
		{
			SetConsoleTextAttribute(h, 224);
		}
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t"".-----------------." << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t""| Modo Automatico |" << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t""\t""'-----------------'" << endl;
		SetConsoleTextAttribute(h, 14);
		cout << endl;
		SetConsoleTextAttribute(h, 11);
		cout << "\t""Usar W para subir" << endl;
		cout << "\t""Usar S para bajar" << endl;
		cout << "\t""Usar E para selecionar" << endl;
		cout << "\t""Usar P para Volver al menu" << endl;
		playerAnsw = pointer(2, 1, pointerCursor);
		if (playerAnsw != 0)
		{
			if (playerAnsw == backToMenu)
			{
				return;
			}
			else
			{
				positionModeSelected = true;
			}
		}
	} while (!positionModeSelected);

	if (playerAnsw == 1)
	{
		for (int i = 0; i < player2.pokemonCount; i++)
		{
			system("cls");
			SetConsoleTextAttribute(h, 14);
			cout << "\t""\t""Pokemones por Colocar " << PokemonToPlace << endl;
			showBoard(player1, player2, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
			SetConsoleTextAttribute(h, 13);
			cout << "\t""\t""Selecione la posicion donde va a ir el pokemon" << endl;
			cout << "\t""\t""Del 1 al 2" << endl;
			cout << "\t""\t""Fila ---> ";
			cin >> cursorBoard.posY;
			cout << "\t""\t""Del 1 al 6" << endl;
			cout << "\t""\t""Columna ---> ";
			cin >> cursorBoard.posX;
			if (boardArrayPlayer2[cursorBoard.posY - 1][cursorBoard.posX - 1] == 0)
			{
				boardArrayPlayer2[cursorBoard.posY - 1][cursorBoard.posX - 1] = player2.pokemonTeam[i].tag;
				PokemonToPlace--;
			}
			else if (cursorBoard.posY - 1 > maxRows || cursorBoard.posX - 1 > maxColumns)
			{
				cout << "\t""\t""Fuera De Rango" << endl;
				system("pause");
				i--;
			}
			else
			{
				cout << "\t""\t""Ya hay un pokemon en este espacio" << endl;
				system("pause");
				i--;
			}
		}
	}
	else if (playerAnsw == 2)
	{
		for (int i = 0; i < player2.pokemonCount; i++)
		{
			cursorBoard.posY = rand() % 2;
			cursorBoard.posX = rand() % 6;
			if (boardArrayPlayer2[cursorBoard.posY][cursorBoard.posX] == 0)
			{
				boardArrayPlayer2[cursorBoard.posY][cursorBoard.posX] = player2.pokemonTeam[i].tag;
				PokemonToPlace--;
			}
			else
			{
				i--;
			}
		}
	}
	else
	{
		return;
	}
	// ---------------------------------------  Fin Jugador 2 Colocacion de Pokemones -------------------------------

	int turn = 0;
	int exitToMenu = 14;
	int pokemonAttaker = 0;
	int pokemonDefender = 0;
	int attkUsed = 0;
	bool endCondition = false;
	pointerCursor = 1;
	do
	{
		srand(time(NULL));
		if (turn == 0)
		{
			player1.playerAtakerSelection = false;
			player1.playerDefenderSelection = false;
			player1.playerAttkSelection = false;
			do
			{
				system("cls");
				showBoard(player1, player2, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
				SetConsoleTextAttribute(h, 11);
				cout << "\t""\t""\t""\t""\t""\t""Turno Jugador " << player1.name << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""\t""Seleccione el pokemon con el que va a atacar" << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 14);
				if (player1.pokemonTeam[0].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[0].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[0].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[0].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[0].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[0].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[0].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[0].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[1].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[1].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[1].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[1].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[1].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[1].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[1].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[1].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[2].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[2].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[2].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[2].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[2].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[2].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[2].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[2].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[3].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[3].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[3].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[3].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[3].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[3].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[3].tag << endl;

					}
					cout << "\t""\t" << player1.pokemonTeam[3].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[4].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[4].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[4].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[4].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[4].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[4].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[4].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[4].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[5].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[5].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[5].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[5].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[5].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[5].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[5].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[5].name << endl;
				}
				else
				{
					pointerCursor++;
				}
				SetConsoleTextAttribute(h, 14);
				cout << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""Usar W para subir" << endl;
				cout << "\t""Usar S para bajar" << endl;
				cout << "\t""Usar E para selecionar" << endl;
				cout << "\t""Usar P para Volver al menu" << endl;
				pokemonAttaker = pointer(6, 1, pointerCursor);
				if (pokemonAttaker != 0)
				{
					if (pokemonAttaker == exitToMenu)
					{
						pokemonAttaker;
						return;
					}
					else
					{
						player1.playerAtakerSelection = true;
					}
				}
			} while (!player1.playerAtakerSelection);
			do
			{
				system("cls");
				showBoard(player1, player2, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
				cout << "\t""\t""\t""\t""\t""\t""Turno Jugador " << player1.name << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""\t""Seleccione el pokemon al que va a atacar" << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 14);
				if (player2.pokemonTeam[0].lifes > 0)
				{
					if (pointerCursor == player2.pokemonTeam[0].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player2.pokemonTeam[0].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player2.pokemonTeam[0].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player2.pokemonTeam[0].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player2.pokemonTeam[0].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player2.pokemonTeam[0].tag << endl;
					}
					cout << "\t""\t" << player2.pokemonTeam[0].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player2.pokemonTeam[1].lifes > 0)
				{
					if (pointerCursor == player2.pokemonTeam[1].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player2.pokemonTeam[1].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player2.pokemonTeam[1].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player2.pokemonTeam[1].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player2.pokemonTeam[1].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player2.pokemonTeam[1].tag << endl;
					}
					cout << "\t""\t" << player2.pokemonTeam[1].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player2.pokemonTeam[2].lifes > 0)
				{
					if (pointerCursor == player2.pokemonTeam[2].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player2.pokemonTeam[2].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player2.pokemonTeam[2].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player2.pokemonTeam[2].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player2.pokemonTeam[2].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player2.pokemonTeam[2].tag << endl;
					}
					cout << "\t""\t" << player2.pokemonTeam[2].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player2.pokemonTeam[3].lifes > 0)
				{
					if (pointerCursor == player2.pokemonTeam[3].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player2.pokemonTeam[3].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player2.pokemonTeam[3].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player2.pokemonTeam[3].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player2.pokemonTeam[3].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player2.pokemonTeam[3].tag << endl;

					}
					cout << "\t""\t" << player2.pokemonTeam[3].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player2.pokemonTeam[4].lifes > 0)
				{
					if (pointerCursor == player2.pokemonTeam[4].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player2.pokemonTeam[4].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player2.pokemonTeam[4].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player2.pokemonTeam[4].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player2.pokemonTeam[4].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player2.pokemonTeam[4].tag << endl;
					}
					cout << "\t""\t" << player2.pokemonTeam[4].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player2.pokemonTeam[5].lifes > 0)
				{
					if (pointerCursor == player2.pokemonTeam[5].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player2.pokemonTeam[5].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player2.pokemonTeam[5].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player2.pokemonTeam[5].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player2.pokemonTeam[5].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player2.pokemonTeam[5].tag << endl;
					}
					cout << "\t""\t" << player2.pokemonTeam[5].name << endl;
				}
				else
				{
					pointerCursor++;
				}
				SetConsoleTextAttribute(h, 14);
				cout << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""Usar W para subir" << endl;
				cout << "\t""Usar S para bajar" << endl;
				cout << "\t""Usar E para selecionar" << endl;
				cout << "\t""Usar P para Volver al menu" << endl;
				pokemonDefender = pointer(6, 1, pointerCursor);
				if (pokemonDefender != 0)
				{
					if (pokemonDefender == exitToMenu)
					{
						pokemonDefender;
						return;
					}
					else
					{
						player1.playerDefenderSelection = true;
					}
				}
			} while (!player1.playerDefenderSelection);
			do
			{
				system("cls");
				showBoard(player1, player2, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
				cout << "\t""\t""\t""\t""\t""\t""Turno Jugador " << player1.name << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 14);
				cout << "\t""\t""Que ataque vas a usar" << endl;
				cout << endl;
				if (pointerCursor == 1)
				{
					SetConsoleTextAttribute(h, 224);
					consolecursorposition = { 80,13 };
					SetConsoleCursorPosition(h, consolecursorposition);
					cout << "\t""\t" << "Damage " << player2.pokemonTeam[pokemonAttaker - 1].attk1Damage << endl;
				}
				cout << "\t""\t" << player1.pokemonTeam[pokemonAttaker - 1].attk1Name << endl;
				SetConsoleTextAttribute(h, 14);
				if (pointerCursor == 2)
				{
					SetConsoleTextAttribute(h, 224);
					consolecursorposition = { 80,13 };
					SetConsoleCursorPosition(h, consolecursorposition);
					cout << "\t""\t" << "Damage " << player2.pokemonTeam[pokemonAttaker - 1].attk2Damage << endl;
				}
				cout << "\t""\t" << player1.pokemonTeam[pokemonAttaker - 1].attk2Name << endl;
				SetConsoleTextAttribute(h, 14);
				if (pointerCursor == 3)
				{
					SetConsoleTextAttribute(h, 224);
					consolecursorposition = { 80,13 };
					SetConsoleCursorPosition(h, consolecursorposition);
					cout << "\t""\t" << "Damage " << player2.pokemonTeam[pokemonAttaker - 1].attk3Damage << endl;
				}
				cout << "\t""\t" << player1.pokemonTeam[pokemonAttaker - 1].attk3Name << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""Usar W para subir" << endl;
				cout << "\t""Usar S para bajar" << endl;
				cout << "\t""Usar E para selecionar" << endl;
				cout << "\t""Usar P para Volver al menu" << endl;
				attkUsed = pointer(3, 1, pointerCursor);
				if (attkUsed != 0)
				{
					player1.playerAttkSelection = true;
				}
			} while (!player1.playerAttkSelection);
			system("cls");
			cout << "\t""\t" << "\t""\t""Accion Jugador 1 " << player1.name << endl;
			cout << endl;
			battle(player1, player2, boardArrayPlayer1, boardArrayPlayer2, (pokemonAttaker - 1), (pokemonDefender - 1), attkUsed, turn, player2.pokemonTeam[(pokemonDefender - 1)].level);
			cout << "\t""\t" << "\t""\t""Pokemon a atacado " << endl;
			cout << endl;
			cout << "\t""\t" << "nombre: " << player2.pokemonTeam[(pokemonDefender - 1)].name << endl;
			cout << "\t""\t" << "Vida: " << player2.pokemonTeam[(pokemonDefender - 1)].lifes << endl;
			cout << "\t""\t" << "Nivel: " << player2.pokemonTeam[(pokemonDefender - 1)].level << endl;
			cout << "\t""\t" << "Defensa: " << player2.pokemonTeam[(pokemonDefender - 1)].Deff << endl;
			turn = 1;
			system("pause");
			cout << endl;
		}
		else
		{
			player2.playerAtakerSelection = false;
			player2.playerDefenderSelection = false;
			player2.playerAttkSelection = false;
			do
			{
				system("cls");
				showBoard(player1, player2, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
				SetConsoleTextAttribute(h, 11);
				cout << "\t""\t""\t""\t""\t""\t""Turno Jugador " << player2.name << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""\t""Seleccione el pokemon con el que va a atacar" << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 14);
				if (player2.pokemonTeam[0].lifes > 0)
				{
					if (pointerCursor == player2.pokemonTeam[0].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player2.pokemonTeam[0].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player2.pokemonTeam[0].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player2.pokemonTeam[0].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player2.pokemonTeam[0].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player2.pokemonTeam[0].tag << endl;
					}
					cout << "\t""\t" << player2.pokemonTeam[0].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player2.pokemonTeam[1].lifes > 0)
				{
					if (pointerCursor == player2.pokemonTeam[1].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player2.pokemonTeam[1].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player2.pokemonTeam[1].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player2.pokemonTeam[1].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player2.pokemonTeam[1].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player2.pokemonTeam[1].tag << endl;
					}
					cout << "\t""\t" << player2.pokemonTeam[1].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player2.pokemonTeam[2].lifes > 0)
				{
					if (pointerCursor == player2.pokemonTeam[2].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player2.pokemonTeam[2].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player2.pokemonTeam[2].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player2.pokemonTeam[2].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player2.pokemonTeam[2].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player2.pokemonTeam[2].tag << endl;
					}
					cout << "\t""\t" << player2.pokemonTeam[2].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player2.pokemonTeam[3].lifes > 0)
				{
					if (pointerCursor == player2.pokemonTeam[3].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player2.pokemonTeam[3].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player2.pokemonTeam[3].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player2.pokemonTeam[3].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player2.pokemonTeam[3].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player2.pokemonTeam[3].tag << endl;

					}
					cout << "\t""\t" << player2.pokemonTeam[3].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player2.pokemonTeam[4].lifes > 0)
				{
					if (pointerCursor == player2.pokemonTeam[4].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player2.pokemonTeam[4].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player2.pokemonTeam[4].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player2.pokemonTeam[4].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player2.pokemonTeam[4].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player2.pokemonTeam[4].tag << endl;
					}
					cout << "\t""\t" << player2.pokemonTeam[4].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player2.pokemonTeam[5].lifes > 0)
				{
					if (pointerCursor == player2.pokemonTeam[5].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player2.pokemonTeam[5].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player2.pokemonTeam[5].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player2.pokemonTeam[5].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player2.pokemonTeam[5].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player2.pokemonTeam[5].tag << endl;
					}
					cout << "\t""\t" << player2.pokemonTeam[5].name << endl;
				}
				else
				{
					pointerCursor++;
				}
				SetConsoleTextAttribute(h, 14);
				cout << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""Usar W para subir" << endl;
				cout << "\t""Usar S para bajar" << endl;
				cout << "\t""Usar E para selecionar" << endl;
				cout << "\t""Usar P para Volver al menu" << endl;
				pokemonAttaker = pointer(6, 1, pointerCursor);
				if (pokemonAttaker != 0)
				{
					if (pokemonAttaker == exitToMenu)
					{
						pokemonAttaker;
						return;
					}
					else
					{
						player2.playerAtakerSelection = true;
					}
				}
			} while (!player2.playerAtakerSelection);
			do
			{
				system("cls");
				showBoard(player1, player2, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
				cout << "\t""\t""\t""\t""\t""\t""Turno Jugador " << player2.name << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""\t""Seleccione el pokemon al que va a atacar" << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 14);
				if (player1.pokemonTeam[0].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[0].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[0].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[0].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[0].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[0].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[0].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[0].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[1].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[1].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[1].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[1].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[1].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[1].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[1].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[1].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[2].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[2].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[2].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[2].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[2].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[2].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[2].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[2].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[3].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[3].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[3].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[3].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[3].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[3].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[3].tag << endl;

					}
					cout << "\t""\t" << player1.pokemonTeam[3].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[4].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[4].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[4].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[4].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[4].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[4].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[4].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[4].name << endl;
					SetConsoleTextAttribute(h, 14);
				}
				else
				{
					pointerCursor++;
				}
				if (player1.pokemonTeam[5].lifes > 0)
				{
					if (pointerCursor == player1.pokemonTeam[5].position)
					{
						SetConsoleTextAttribute(h, 10);
						consolecursorposition = { 80,13 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Name " << player1.pokemonTeam[5].name << endl;
						consolecursorposition = { 80,14 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Level " << player1.pokemonTeam[5].level << endl;
						consolecursorposition = { 80,15 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Lifes " << player1.pokemonTeam[5].lifes << endl;
						consolecursorposition = { 80,16 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Deff " << player1.pokemonTeam[5].Deff << endl;
						consolecursorposition = { 80,17 };
						SetConsoleCursorPosition(h, consolecursorposition);
						cout << "\t""\t" << "Pokemon Tag " << player1.pokemonTeam[5].tag << endl;
					}
					cout << "\t""\t" << player1.pokemonTeam[5].name << endl;
				}
				else
				{
					pointerCursor++;
				}
				SetConsoleTextAttribute(h, 14);
				cout << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""Usar W para subir" << endl;
				cout << "\t""Usar S para bajar" << endl;
				cout << "\t""Usar E para selecionar" << endl;
				cout << "\t""Usar P para Volver al menu" << endl;
				pokemonDefender = pointer(6, 1, pointerCursor);
				if (pokemonDefender != 0)
				{
					if (pokemonDefender == exitToMenu)
					{
						pokemonDefender;
						return;
					}
					else
					{
						player2.playerDefenderSelection = true;
					}
				}
			} while (!player2.playerDefenderSelection);
			do
			{
				system("cls");
				showBoard(player1, player2, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
				cout << "\t""\t""\t""\t""\t""\t""Turno Jugador " << player2.name << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 14);
				cout << "\t""\t""Que ataque vas a usar" << endl;
				cout << endl;
				if (pointerCursor == 1)
				{
					SetConsoleTextAttribute(h, 224);
					consolecursorposition = { 80,13 };
					SetConsoleCursorPosition(h, consolecursorposition);
					cout << "\t""\t" << "Damage " << player2.pokemonTeam[pokemonAttaker - 1].attk1Damage << endl;
				}
				cout << "\t""\t" << player2.pokemonTeam[pokemonAttaker - 1].attk1Name << endl;
				SetConsoleTextAttribute(h, 14);
				if (pointerCursor == 2)
				{
					SetConsoleTextAttribute(h, 224);
					consolecursorposition = { 80,13 };
					SetConsoleCursorPosition(h, consolecursorposition);
					cout << "\t""\t" << "Damage " << player2.pokemonTeam[pokemonAttaker - 1].attk2Damage << endl;
				}
				cout << "\t""\t" << player2.pokemonTeam[pokemonAttaker - 1].attk2Name << endl;
				SetConsoleTextAttribute(h, 14);
				if (pointerCursor == 3)
				{
					SetConsoleTextAttribute(h, 224);
					consolecursorposition = { 80,13 };
					SetConsoleCursorPosition(h, consolecursorposition);
					cout << "\t""\t" << "Damage " << player2.pokemonTeam[pokemonAttaker - 1].attk3Damage << endl;
				}
				cout << "\t""\t" << player2.pokemonTeam[pokemonAttaker - 1].attk3Name << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t""Usar W para subir" << endl;
				cout << "\t""Usar S para bajar" << endl;
				cout << "\t""Usar E para selecionar" << endl;
				cout << "\t""Usar P para Volver al menu" << endl;
				attkUsed = pointer(3, 1, pointerCursor);
				if (attkUsed != 0)
				{
					player2.playerAttkSelection = true;
				}
			} while (!player2.playerAttkSelection);
			system("cls");
			cout << "\t""\t" << "\t""\t""Accion Jugador 2 " << player2.name << endl;
			cout << endl;
			battle(player1, player2, boardArrayPlayer1, boardArrayPlayer2, (pokemonAttaker - 1), (pokemonDefender - 1), attkUsed, turn, player2.pokemonTeam[(pokemonDefender - 1)].level);
			cout << "\t""\t" << "\t""\t""Pokemon a atacado " << endl;
			cout << endl;
			cout << "\t""\t" << "nombre: " << player2.pokemonTeam[(pokemonDefender - 1)].name << endl;
			cout << "\t""\t" << "Vida: " << player2.pokemonTeam[(pokemonDefender - 1)].lifes << endl;
			cout << "\t""\t" << "Nivel: " << player2.pokemonTeam[(pokemonDefender - 1)].level << endl;
			cout << "\t""\t" << "Defensa: " << player2.pokemonTeam[(pokemonDefender - 1)].Deff << endl;
			turn = 1;
			system("pause");
			cout << endl;
		}
		if (player1.pokemonCount == 0)
		{
			endCondition = true;
		}
		else if (player2.pokemonCount == 0)
		{
			endCondition = true;
		}

	} while (!endCondition);
	if (player1.pokemonCount == 0)
	{
		SetConsoleTextAttribute(h, 10);
		system("cls");
		cout << "\t""\t""Felicidades " << player1.name << "Ganaste" << endl;
		system("pause");
	}
	else
	{
		SetConsoleTextAttribute(h, 12);
		system("cls");
		cout << "\t""\t""Felicidades " << player2.name << "Ganaste" << endl;
		system("pause");
	}
}
void showBoard(Player actualPlayer1, Player actualPlayer2, char boardArrayPlayer1[2][6], char boardArrayPlayer2[2][6], int maxRows, int maxColumns)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 9);
	char empty = 32;	// valor vacio en el tablero
	char uperLeftCorner = 201; // esquina superior izquierda ╔
	char uperRightCorner = 187; // esquina superior derecha ╗
	char lowerLeftCorner = 200; // esquina inferior izquierda ╚
	char lowerRightCorner = 188; // esquina inferior Derecha ╝
	char horizontalRow = 205;	// linea horizontal ═
	char verticalColumn = 186; // linea vertical ║
	char uperConection = 203; // conector superior ╦
	char lowerConection = 202; // conector inferior ╩
	char horizontalConection = 185; // conector derecho ╣
	char verticalConection = 204; // conector izquierdo ╠
	char crosConection = 206; // interseccion ╬


	//--------------------------- Inicio Dibujado del Tablero del Player 1 ----------------------------------------
	cout << "\t" "\t" "\t" "\t" "\t""\t" "\t""\t" "\t" << uperLeftCorner;
	for (int i = 0; i < maxColumns; i++)
	{
		cout << horizontalRow << horizontalRow << horizontalRow << uperConection;
	}
	cout << "\b" << uperRightCorner;
	cout << endl;
	for (int rows = 0; rows < maxRows; rows++)
	{
		cout << "\t" "\t" "\t" "\t" "\t""\t" "\t""\t" "\t";
		for (int columns = 0; columns < maxColumns; columns++)
		{
			if (boardArrayPlayer1[rows][columns] != 0)
			{
				cout << verticalColumn;
				SetConsoleTextAttribute(h, 8);
				cout << " " << boardArrayPlayer1[rows][columns] << " ";
				SetConsoleTextAttribute(h, 9);
			}
			else
			{
				cout << verticalColumn << " " << empty << " ";
			}
		}
		cout << verticalColumn;
		cout << endl;

		if (rows != maxRows - 1)
		{
			cout << "\t" "\t" "\t" "\t" "\t""\t" "\t""\t" "\t" << verticalConection;
			for (int i = 0; i < maxColumns; i++)
			{
				cout << horizontalRow << horizontalRow << horizontalRow << crosConection;
			}
			cout << "\b" << horizontalConection;
			cout << endl;
		}
	}
	cout << "\t" "\t" "\t" "\t" "\t""\t" "\t""\t" "\t" << lowerLeftCorner;
	for (int i = 0; i < maxColumns; i++)
	{
		cout << horizontalRow << horizontalRow << horizontalRow << lowerConection;
	}
	cout << "\b" << lowerRightCorner;
	cout << endl;
	//------------------------------- Fin del dibujado del Tablero Player 1 --------------------------------------------------
	//--------------------------- Inicio Dibujado del Tablero del Player 2 ----------------------------------------
	SetConsoleTextAttribute(h, 9);
	cout << "\t" "\t" "\t" "\t" "\t""\t" "\t""\t" "\t" << uperLeftCorner;
	for (int i = 0; i < maxColumns; i++)
	{
		cout << horizontalRow << horizontalRow << horizontalRow << uperConection;
	}
	cout << "\b" << uperRightCorner;
	cout << endl;
	for (int rows = 0; rows < maxRows; rows++)
	{
		cout << "\t" "\t" "\t" "\t" "\t""\t" "\t""\t" "\t";
		for (int columns = 0; columns < maxColumns; columns++)
		{
			if (boardArrayPlayer2[rows][columns] != 0)
			{
				cout << verticalColumn;
				SetConsoleTextAttribute(h, 8);
				cout << " " << boardArrayPlayer2[rows][columns] << " ";
				SetConsoleTextAttribute(h, 9);
			}
			else
			{
				cout << verticalColumn << " " << empty << " ";
			}
		}
		cout << verticalColumn;
		cout << endl;

		if (rows != maxRows - 1)
		{
			cout << "\t" "\t" "\t" "\t" "\t""\t" "\t""\t" "\t" << verticalConection;
			for (int i = 0; i < maxColumns; i++)
			{
				cout << horizontalRow << horizontalRow << horizontalRow << crosConection;
			}
			cout << "\b" << horizontalConection;
			cout << endl;
		}
	}
	cout << "\t" "\t" "\t" "\t" "\t""\t" "\t""\t" "\t" << lowerLeftCorner;
	for (int i = 0; i < maxColumns; i++)
	{
		cout << horizontalRow << horizontalRow << horizontalRow << lowerConection;
	}
	cout << "\b" << lowerRightCorner;
	cout << endl;
	//------------------------------- Fin del dibujado del Tablero Player 2 --------------------------------------------------
}
Pokemon pokemonMaker(Player actualPlayer, char pokemonTag, int PokemonLifes, int PokemonLevel, int PokemonDeff, int& PokemonsToPlace, int Pokemonposition)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD consolecursorposition = { 0,0 };

	Pokemon aux;
	string pokeName;
	string pokeAttk1;
	string pokeAttk2;
	string pokeAttk3;
	bool attkSelected = false;
	int pokemonlvl1Attk1 = 100;
	int pokemonlvl1Attk2 = 200;
	int pokemonlvl1Attk3 = 300;
	int pokemonlvl2Attk1 = 400;
	int pokemonlvl2Attk2 = 500;
	int pokemonlvl2Attk3 = 600;
	int pokemonlvl3Attk1 = 700;
	int pokemonlvl3Attk2 = 800;
	int pokemonlvl3Attk3 = 900;


	system("cls");
	SetConsoleTextAttribute(h, 96);
	cout << R"(
						 _____                     _           _         _____       _                         
						|  _  | ___  _____  ___  _| | ___    _| | ___   |  _  | ___ | |_  ___  _____  ___  ___ 
						|     ||  _||     || .'|| . || . |  | . || -_|  |   __|| . || '_|| -_||     || . ||   |
						|__|__||_|  |_|_|_||__,||___||___|  |___||___|  |__|   |___||_,_||___||_|_|_||___||_|_|
						                                                                                       )" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 14);
	cout << "                                                                                  Pokemons Restantes " << PokemonsToPlace << endl;
	SetConsoleTextAttribute(h, 14);
	cout << "\t""\t""Como se va a llamar tu pokemon ?" << endl;
	cout << "\t""\t" << actualPlayer.name << " ---> ";
	cin >> pokeName;
	cout << "\t""\t""Como se va a llamar tu  1 ataque?" << endl;
	cout << "\t""\t" << actualPlayer.name << " ---> ";
	cin >> pokeAttk1;
	cout << "\t""\t""Como se va a llamar tu  2 ataque?" << endl;
	cout << "\t""\t" << actualPlayer.name << " ---> ";
	cin >> pokeAttk2;
	cout << "\t""\t""Como se va a llamar tu  3 ataque?" << endl;
	cout << "\t""\t" << actualPlayer.name << " ---> ";
	cin >> pokeAttk3;
	aux.name = pokeName;
	aux.attk1Name = pokeAttk1;
	aux.attk2Name = pokeAttk2;
	aux.attk3Name = pokeAttk3;
	if (PokemonLevel == 1)
	{
		aux.attk1Damage = pokemonlvl1Attk1;
		aux.attk2Damage = pokemonlvl1Attk2;
		aux.attk3Damage = pokemonlvl1Attk3;
	}
	else if (PokemonLevel == 2)
	{
		aux.attk1Damage = pokemonlvl2Attk1;
		aux.attk2Damage = pokemonlvl2Attk2;
		aux.attk3Damage = pokemonlvl2Attk3;
	}
	else if (PokemonLevel == 3)
	{
		aux.attk1Damage = pokemonlvl3Attk1;
		aux.attk2Damage = pokemonlvl3Attk2;
		aux.attk3Damage = pokemonlvl3Attk3;
	}
	aux.tag = pokemonTag;
	aux.lifes = PokemonLifes;
	aux.level = PokemonLevel;
	aux.Deff = PokemonDeff;
	aux.position = Pokemonposition;

	PokemonsToPlace--;

	return aux;
}
Player cpuMaker()
{
	int pokemonlvl1Lifes = 1;
	int pokemonlvl2Lifes = 3;
	int pokemonlvl3Lifes = 5;
	int pokemonlvl1Deff = 500;
	int pokemonlvl2Deff = 1000;
	int pokemonlvl3Deff = 1500;
	int pokemonlvl1Attk1 = 100;
	int pokemonlvl1Attk2 = 200;
	int pokemonlvl1Attk3 = 300;
	int pokemonlvl2Attk1 = 400;
	int pokemonlvl2Attk2 = 500;
	int pokemonlvl2Attk3 = 600;
	int pokemonlvl3Attk1 = 700;
	int pokemonlvl3Attk2 = 800;
	int pokemonlvl3Attk3 = 900;


	Player aux;
	aux.name = "Trainer";
	Pokemon pokemon1Cpu;
	pokemon1Cpu.name = "Charmander";
	pokemon1Cpu.tag = 'g';
	pokemon1Cpu.lifes = pokemonlvl1Lifes;
	pokemon1Cpu.level = 1;
	pokemon1Cpu.Deff = pokemonlvl1Deff;
	pokemon1Cpu.attk1Name = "Bola de Fuego";
	pokemon1Cpu.attk1Damage = pokemonlvl1Attk1;
	pokemon1Cpu.attk2Name = "Lanza LLamas";
	pokemon1Cpu.attk2Damage = pokemonlvl1Attk2;
	pokemon1Cpu.attk3Name = "Ascuas";
	pokemon1Cpu.attk3Damage = pokemonlvl1Attk3;
	aux.pokemonTeam[0] = pokemon1Cpu;
	aux.pokemonTeam[0].position = 1;
	aux.pokemonCount++;

	Pokemon pokemon2Cpu;
	pokemon2Cpu.name = "Squirtle";
	pokemon2Cpu.tag = 'h';
	pokemon2Cpu.lifes = pokemonlvl1Lifes;
	pokemon2Cpu.level = 1;
	pokemon2Cpu.Deff = pokemonlvl1Deff;
	pokemon2Cpu.attk1Name = "Burbujas";
	pokemon2Cpu.attk1Damage = pokemonlvl1Attk1;
	pokemon2Cpu.attk2Name = "Tacle";
	pokemon2Cpu.attk2Damage = pokemonlvl1Attk2;
	pokemon2Cpu.attk3Name = "Chorro de Agua";
	pokemon2Cpu.attk3Damage = pokemonlvl1Attk3;
	aux.pokemonTeam[1] = pokemon2Cpu;
	aux.pokemonTeam[1].position = 2;
	aux.pokemonCount++;

	Pokemon pokemon3Cpu;
	pokemon3Cpu.name = "Bulbasaur";
	pokemon3Cpu.tag = 'i';
	pokemon3Cpu.lifes = pokemonlvl1Lifes;
	pokemon3Cpu.level = 1;
	pokemon3Cpu.Deff = pokemonlvl1Deff;
	pokemon3Cpu.attk1Name = "Latigazo";
	pokemon3Cpu.attk1Damage = pokemonlvl1Attk1;
	pokemon3Cpu.attk2Name = "Hoja Cortante";
	pokemon3Cpu.attk2Damage = pokemonlvl1Attk2;
	pokemon3Cpu.attk3Name = "Latigo Sepa";
	pokemon3Cpu.attk3Damage = pokemonlvl1Attk3;
	aux.pokemonTeam[2] = pokemon3Cpu;
	aux.pokemonTeam[2].position = 3;
	aux.pokemonCount++;

	Pokemon pokemon4Cpu;
	pokemon4Cpu.name = "Ivysaur";
	pokemon4Cpu.tag = 'j';
	pokemon4Cpu.lifes = pokemonlvl2Lifes;
	pokemon4Cpu.level = 2;
	pokemon4Cpu.Deff = pokemonlvl2Deff;
	pokemon4Cpu.attk1Name = "Bomba germen";
	pokemon4Cpu.attk1Damage = pokemonlvl2Attk1;
	pokemon4Cpu.attk2Name = "Ciclón de Hojas";
	pokemon4Cpu.attk2Damage = pokemonlvl2Attk2;
	pokemon4Cpu.attk3Name = "Hierba Lazo";
	pokemon4Cpu.attk3Damage = pokemonlvl2Attk3;
	aux.pokemonTeam[3] = pokemon4Cpu;
	aux.pokemonTeam[3].position = 4;
	aux.pokemonCount++;

	Pokemon pokemon5Cpu;
	pokemon5Cpu.name = "Charmeleon";
	pokemon5Cpu.tag = 'k';
	pokemon5Cpu.lifes = pokemonlvl2Lifes;
	pokemon5Cpu.level = 2;
	pokemon5Cpu.Deff = pokemonlvl2Deff;
	pokemon5Cpu.attk1Name = "Meteoro";
	pokemon5Cpu.attk1Damage = pokemonlvl2Attk1;
	pokemon5Cpu.attk2Name = "Infierno";
	pokemon5Cpu.attk2Damage = pokemonlvl2Attk2;
	pokemon5Cpu.attk3Name = "Giro de Fuego";
	pokemon5Cpu.attk3Damage = pokemonlvl2Attk3;
	aux.pokemonTeam[4] = pokemon5Cpu;
	aux.pokemonTeam[4].position = 5;
	aux.pokemonCount++;

	Pokemon pokemon6Cpu;
	pokemon6Cpu.name = "Venusaur";
	pokemon6Cpu.tag = 'l';
	pokemon6Cpu.lifes = pokemonlvl3Lifes;
	pokemon6Cpu.level = 3;
	pokemon6Cpu.Deff = pokemonlvl3Deff;
	pokemon6Cpu.attk1Name = "Aromaterapia";
	pokemon6Cpu.attk1Damage = pokemonlvl3Attk1;
	pokemon6Cpu.attk2Name = "Ciclón de hojas";
	pokemon6Cpu.attk2Damage = pokemonlvl3Attk2;
	pokemon6Cpu.attk3Name = "Cuchilla solar";
	pokemon6Cpu.attk3Damage = pokemonlvl3Attk3;
	aux.pokemonTeam[5] = pokemon6Cpu;
	aux.pokemonTeam[5].position = 6;
	aux.pokemonCount++;

	return aux;
}
void battle(Player& actualPlayer1, Player& actualPlayer2, char boardArrayPlayer1[2][6], char boardArrayPlayer2[2][6], int pokemonAttaker, int pokemonDefender, int attkUsed, int turn, int deffLevel)
{
	srand(time(NULL));
	int dice = rand() % 3 + 1;

	if (turn == 0)
	{
		if (dice == attkUsed)
		{
			cout << "\t""\t""El oponente se defendio" << endl;
		}
		else
		{
			switch (attkUsed)
			{
			case 1:
				actualPlayer2.pokemonTeam[pokemonDefender].Deff = actualPlayer2.pokemonTeam[pokemonDefender].Deff - actualPlayer1.pokemonTeam[pokemonAttaker].attk1Damage;
				cout << "\t""\t""Golpeaste por " << actualPlayer1.pokemonTeam[pokemonAttaker].attk1Damage << endl;
				cout << "\t""\t""al oponente le queda " << actualPlayer2.pokemonTeam[pokemonDefender].Deff << endl;
				if (actualPlayer2.pokemonTeam[pokemonDefender].Deff <= 0)
				{
					actualPlayer2.pokemonTeam[pokemonDefender].lifes--;
					if (actualPlayer2.pokemonTeam[pokemonDefender].level == 1)
					{
						actualPlayer2.pokemonTeam[pokemonDefender].Deff = actualPlayer2.pokemonTeam[pokemonDefender].pokemonlvl1DeffDefault;
					}
					else if (actualPlayer2.pokemonTeam[pokemonDefender].level == 2)
					{
						actualPlayer2.pokemonTeam[pokemonDefender].Deff = actualPlayer2.pokemonTeam[pokemonDefender].pokemonlvl2DeffDefault;
					}
					else
					{
						actualPlayer2.pokemonTeam[pokemonDefender].Deff = actualPlayer2.pokemonTeam[pokemonDefender].pokemonlvl3DeffDefault;
					}
					if (actualPlayer2.pokemonTeam[pokemonDefender].lifes <= 0)
					{
						for (int rows = 0; rows < 2; rows++)
						{
							for (int columns = 0; columns < 6; columns++)
							{
								if (boardArrayPlayer2[rows][columns] == actualPlayer2.pokemonTeam[pokemonDefender].tag)
								{
									boardArrayPlayer2[rows][columns] = 0;
									actualPlayer2.pokemonCount--;
								}
							}
						}
					}
				}
				break;
			case 2:
				actualPlayer2.pokemonTeam[pokemonDefender].Deff = actualPlayer2.pokemonTeam[pokemonDefender].Deff - actualPlayer1.pokemonTeam[pokemonAttaker].attk2Damage;
				cout << "\t""\t""Golpeaste por " << actualPlayer1.pokemonTeam[pokemonAttaker].attk2Damage << endl;
				cout << "\t""\t""al oponente le queda " << actualPlayer2.pokemonTeam[pokemonDefender].Deff << endl;
				if (actualPlayer2.pokemonTeam[pokemonDefender].Deff <= 0)
				{
					actualPlayer2.pokemonTeam[pokemonDefender].lifes--;
					if (actualPlayer2.pokemonTeam[pokemonDefender].level == 1)
					{
						actualPlayer2.pokemonTeam[pokemonDefender].Deff = actualPlayer2.pokemonTeam[pokemonDefender].pokemonlvl1DeffDefault;
					}
					else if (actualPlayer2.pokemonTeam[pokemonDefender].level == 2)
					{
						actualPlayer2.pokemonTeam[pokemonDefender].Deff = actualPlayer2.pokemonTeam[pokemonDefender].pokemonlvl2DeffDefault;
					}
					else
					{
						actualPlayer2.pokemonTeam[pokemonDefender].Deff = actualPlayer2.pokemonTeam[pokemonDefender].pokemonlvl3DeffDefault;
					}
					if (actualPlayer2.pokemonTeam[pokemonDefender].lifes <= 0)
					{
						for (int rows = 0; rows < 2; rows++)
						{
							for (int columns = 0; columns < 6; columns++)
							{
								if (boardArrayPlayer2[rows][columns] == actualPlayer2.pokemonTeam[pokemonDefender].tag)
								{
									boardArrayPlayer2[rows][columns] = 0;
									actualPlayer2.pokemonCount--;
								}
							}
						}
					}
				}
				break;
			case 3:
				actualPlayer2.pokemonTeam[pokemonDefender].Deff = actualPlayer2.pokemonTeam[pokemonDefender].Deff - actualPlayer1.pokemonTeam[pokemonAttaker].attk3Damage;
				cout << "\t""\t""Golpeaste por " << actualPlayer1.pokemonTeam[pokemonAttaker].attk3Damage << endl;
				cout << "\t""\t""al oponente le queda " << actualPlayer2.pokemonTeam[pokemonDefender].Deff << endl;
				if (actualPlayer2.pokemonTeam[pokemonDefender].Deff <= 0)
				{
					actualPlayer2.pokemonTeam[pokemonDefender].lifes--;
					if (actualPlayer2.pokemonTeam[pokemonDefender].level == 1)
					{
						actualPlayer2.pokemonTeam[pokemonDefender].Deff = actualPlayer2.pokemonTeam[pokemonDefender].pokemonlvl1DeffDefault;
					}
					else if (actualPlayer2.pokemonTeam[pokemonDefender].level == 2)
					{
						actualPlayer2.pokemonTeam[pokemonDefender].Deff = actualPlayer2.pokemonTeam[pokemonDefender].pokemonlvl2DeffDefault;
					}
					else
					{
						actualPlayer2.pokemonTeam[pokemonDefender].Deff = actualPlayer2.pokemonTeam[pokemonDefender].pokemonlvl3DeffDefault;
					}
					if (actualPlayer2.pokemonTeam[pokemonDefender].lifes <= 0)
					{
						for (int rows = 0; rows < 2; rows++)
						{
							for (int columns = 0; columns < 6; columns++)
							{
								if (boardArrayPlayer2[rows][columns] == actualPlayer2.pokemonTeam[pokemonDefender].tag)
								{
									boardArrayPlayer2[rows][columns] = 0;
									actualPlayer2.pokemonCount--;
								}
							}
						}
					}
				}
				break;
			default:
				break;
			}
		}
	}
	else
	{
		if (dice == attkUsed)
		{
			cout << "\t""\t""El oponente se defendio" << endl;
		}
		else
		{
			switch (attkUsed)
			{
			case 1:
				actualPlayer1.pokemonTeam[pokemonDefender].Deff = actualPlayer1.pokemonTeam[pokemonDefender].Deff - actualPlayer2.pokemonTeam[pokemonAttaker].attk1Damage;
				cout << "\t""\t""Golpeaste por " << actualPlayer2.pokemonTeam[pokemonAttaker].attk1Damage << endl;
				cout << "\t""\t""al oponente le queda " << actualPlayer1.pokemonTeam[pokemonDefender].Deff << endl;
				if (actualPlayer1.pokemonTeam[pokemonDefender].Deff <= 0)
				{
					actualPlayer1.pokemonTeam[pokemonDefender].lifes--;
					if (actualPlayer1.pokemonTeam[pokemonDefender].level == 1)
					{
						actualPlayer1.pokemonTeam[pokemonDefender].Deff = actualPlayer1.pokemonTeam[pokemonDefender].pokemonlvl1DeffDefault;
					}
					else if (actualPlayer1.pokemonTeam[pokemonDefender].level == 2)
					{
						actualPlayer1.pokemonTeam[pokemonDefender].Deff = actualPlayer1.pokemonTeam[pokemonDefender].pokemonlvl2DeffDefault;
					}
					else
					{
						actualPlayer1.pokemonTeam[pokemonDefender].Deff = actualPlayer1.pokemonTeam[pokemonDefender].pokemonlvl3DeffDefault;
					}
					if (actualPlayer1.pokemonTeam[pokemonDefender].lifes <= 0)
					{
						for (int rows = 0; rows < 2; rows++)
						{
							for (int columns = 0; columns < 6; columns++)
							{
								if (boardArrayPlayer1[rows][columns] == actualPlayer1.pokemonTeam[pokemonDefender].tag)
								{
									boardArrayPlayer1[rows][columns] = 0;
									actualPlayer1.pokemonCount--;
								}
							}
						}
					}
				}
				break;
			case 2:
				actualPlayer1.pokemonTeam[pokemonDefender].Deff = actualPlayer1.pokemonTeam[pokemonDefender].Deff - actualPlayer2.pokemonTeam[pokemonAttaker].attk2Damage;
				cout << "\t""\t""Golpeaste por " << actualPlayer2.pokemonTeam[pokemonAttaker].attk2Damage << endl;
				cout << "\t""\t""al oponente le queda " << actualPlayer1.pokemonTeam[pokemonDefender].Deff << endl;
				if (actualPlayer1.pokemonTeam[pokemonDefender].Deff <= 0)
				{
					actualPlayer1.pokemonTeam[pokemonDefender].lifes--;
					if (actualPlayer1.pokemonTeam[pokemonDefender].level == 1)
					{
						actualPlayer1.pokemonTeam[pokemonDefender].Deff = actualPlayer1.pokemonTeam[pokemonDefender].pokemonlvl1DeffDefault;
					}
					else if (actualPlayer1.pokemonTeam[pokemonDefender].level == 2)
					{
						actualPlayer1.pokemonTeam[pokemonDefender].Deff = actualPlayer1.pokemonTeam[pokemonDefender].pokemonlvl2DeffDefault;
					}
					else
					{
						actualPlayer1.pokemonTeam[pokemonDefender].Deff = actualPlayer1.pokemonTeam[pokemonDefender].pokemonlvl3DeffDefault;
					}
					if (actualPlayer1.pokemonTeam[pokemonDefender].lifes <= 0)
					{
						for (int rows = 0; rows < 2; rows++)
						{
							for (int columns = 0; columns < 6; columns++)
							{
								if (boardArrayPlayer1[rows][columns] == actualPlayer1.pokemonTeam[pokemonDefender].tag)
								{
									boardArrayPlayer1[rows][columns] = 0;
									actualPlayer1.pokemonCount--;
								}
							}
						}
					}
				}
				break;
			case 3:
				actualPlayer1.pokemonTeam[pokemonDefender].Deff = actualPlayer1.pokemonTeam[pokemonDefender].Deff - actualPlayer2.pokemonTeam[pokemonAttaker].attk3Damage;
				cout << "\t""\t""Golpeaste por " << actualPlayer2.pokemonTeam[pokemonAttaker].attk3Damage << endl;
				cout << "\t""\t""al oponente le queda " << actualPlayer1.pokemonTeam[pokemonDefender].Deff << endl;
				if (actualPlayer1.pokemonTeam[pokemonDefender].Deff <= 0)
				{
					actualPlayer1.pokemonTeam[pokemonDefender].lifes--;
					if (actualPlayer1.pokemonTeam[pokemonDefender].level == 1)
					{
						actualPlayer1.pokemonTeam[pokemonDefender].Deff = actualPlayer1.pokemonTeam[pokemonDefender].pokemonlvl1DeffDefault;
					}
					else if (actualPlayer1.pokemonTeam[pokemonDefender].level == 2)
					{
						actualPlayer1.pokemonTeam[pokemonDefender].Deff = actualPlayer1.pokemonTeam[pokemonDefender].pokemonlvl2DeffDefault;
					}
					else
					{
						actualPlayer1.pokemonTeam[pokemonDefender].Deff = actualPlayer1.pokemonTeam[pokemonDefender].pokemonlvl3DeffDefault;
					}
					if (actualPlayer1.pokemonTeam[pokemonDefender].lifes == 0)
					{
						for (int rows = 0; rows < 2; rows++)
						{
							for (int columns = 0; columns < 6; columns++)
							{
								if (boardArrayPlayer1[rows][columns] == actualPlayer1.pokemonTeam[pokemonDefender].tag)
								{
									boardArrayPlayer1[rows][columns] = 0;
									actualPlayer1.pokemonCount--;
								}
							}
						}
					}
				}
				break;
			default:
				break;
			}
		}
	}
}
void boardReset(char boardArrayPlayer1[2][6], char boardArrayPlayer2[2][6])
{
	for (int rows = 0; rows < 2; rows++)
	{
		for (int columns = 0; columns < 6; columns++)
		{
			boardArrayPlayer1[rows][columns] = 0;
		}
	}
	for (int rows = 0; rows < 2; rows++)
	{
		for (int columns = 0; columns < 6; columns++)
		{
			boardArrayPlayer2[rows][columns] = 0;
		}
	}
}