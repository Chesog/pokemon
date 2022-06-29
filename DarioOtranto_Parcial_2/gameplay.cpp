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

	int boardArrayPlayer1[maxRows][maxColumns]{};
	int boardArrayPlayer2[maxRows][maxColumns]{};

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
	//Pokemon pokemon1Player = pokemonMaker( player1, 'a', pokemonlvl1Lifes, 1, pokemonlvl1Deff);
	//player1.pokemonTeam[0] = pokemon1Player;
	//player1.pokemonCount++;
	//Pokemon pokemon2Player = pokemonMaker( player1, 'b', pokemonlvl1Lifes, 1, pokemonlvl1Deff);
	//player1.pokemonTeam[1] = pokemon2Player;
	//player1.pokemonCount++;
	//Pokemon pokemon3Player = pokemonMaker( player1, 'c', pokemonlvl1Lifes, 1, pokemonlvl1Deff);
	//player1.pokemonTeam[2] = pokemon3Player;
	//player1.pokemonCount++;
	//Pokemon pokemon4Player = pokemonMaker( player1, 'd', pokemonlvl2Lifes, 2, pokemonlvl2Deff);
	//player1.pokemonTeam[3] = pokemon4Player;
	//player1.pokemonCount++;
	//Pokemon pokemon5Player = pokemonMaker( player1, 'e', pokemonlvl2Lifes, 2, pokemonlvl2Deff);
	//player1.pokemonTeam[4] = pokemon5Player;
	//player1.pokemonCount++;
	//Pokemon pokemon6Player = pokemonMaker( player1, 'f', pokemonlvl3Lifes, 3, pokemonlvl3Deff);
	//player1.pokemonTeam[5] = pokemon6Player;
	//player1.pokemonCount++;

	CPU = cpuMaker();
	system("cls");
	showBoard(player1, CPU, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);

	PointerCursorBoard cursorBoard;

	for (int i = 0; i < player1.pokemonCount; i++)
	{

		cout << "Pokemones por Colocar" << endl;
		showBoard(player1, CPU, boardArrayPlayer1, boardArrayPlayer2, maxRows, maxColumns);
		cout << "Selecione la posicion donde va a ir el pokemon" << endl;
		cout << "Fila ---> ";
		cin >> cursorBoard.posY;
		cout << "Columna ---> ";
		cin >> cursorBoard.posX;
		boardArrayPlayer1[cursorBoard.posY][cursorBoard.posX] == player1.pokemonTeam[i].tag;
	}
	for (int i = 0; i < CPU.pokemonCount; i++)
	{
		cursorBoard.posY = rand() % 2;
		cursorBoard.posX = rand() % 6;
	}


	system("pause");


}
void multiPlayer(int& pointerCursor)
{
	system("cls");
	cout << "MultiPlayer" << endl;
	system("pause");
}
void showBoard(Player actualPlayer1, Player actualPlayer2, int boardArrayPlayer1[2][6], int boardArrayPlayer2[2][6], int maxRows, int maxColumns)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


	char cardBack = 177;	// dorso de las cartas
	char cros = 88;		// valor "X" en el tablero
	char circle = 79;	// valor "O" en el tablero

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

	SetConsoleTextAttribute(h, 13);

	for (int rows = 0; rows < maxRows; rows++) // tablero para el jugador 1
	{
		if (rows == 0)
		{
			cout << "\t""\t""\t""\t""\t""\t""\t""\t" << uperLeftCorner;
			for (int columns = 0; columns < maxColumns; columns++)
			{
				cout << horizontalRow << horizontalRow << horizontalRow;
				cout << uperConection;
			}
			cout << horizontalRow << horizontalRow << horizontalRow << uperRightCorner;

		}
		else
		{
			cout << "\t""\t""\t""\t""\t""\t""\t""\t" << verticalConection;
			for (int columns = 0; columns < maxColumns; columns++)
			{
				cout << horizontalRow << horizontalRow << horizontalRow;
				cout << crosConection;
			}
			cout << horizontalRow << horizontalRow << horizontalRow << horizontalConection;
		}
		cout << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t" << verticalColumn;
		for (int columns = 0; columns < maxColumns; columns++)
		{
			if (boardArrayPlayer1[rows][columns] == 0)
			{
				cout << " " << " " << " ";
			}
			else
			{
				cout << " " << actualPlayer1.pokemonTeam[rows].tag << " ";
			}
			cout << verticalColumn;
		}
		cout << " " << " " << " " << verticalColumn;
		cout << endl;
		if (rows == 1)
		{
			cout << "\t""\t""\t""\t""\t""\t""\t""\t" << lowerLeftCorner;
			for (int columns = 0; columns < maxColumns; columns++)
			{
				cout << horizontalRow << horizontalRow << horizontalRow;
				cout << lowerConection;
			}
			cout << horizontalRow << horizontalRow << horizontalRow;
			cout << lowerRightCorner;
		}
	}
	cout << endl;

	for (int rows = 0; rows < maxRows; rows++) // tablero para el jugador 2
	{
		if (rows == 0)
		{
			cout << "\t""\t""\t""\t""\t""\t""\t""\t" << uperLeftCorner;
			for (int columns = 0; columns < maxColumns; columns++)
			{
				cout << horizontalRow << horizontalRow << horizontalRow;
				cout << uperConection;
			}
			cout << horizontalRow << horizontalRow << horizontalRow << uperRightCorner;

		}
		else
		{
			cout << "\t""\t""\t""\t""\t""\t""\t""\t" << verticalConection;
			for (int columns = 0; columns < maxColumns; columns++)
			{
				cout << horizontalRow << horizontalRow << horizontalRow;
				cout << crosConection;
			}
			cout << horizontalRow << horizontalRow << horizontalRow << horizontalConection;
		}
		cout << endl;
		cout << "\t""\t""\t""\t""\t""\t""\t""\t" << verticalColumn;
		for (int columns = 0; columns < maxColumns; columns++)
		{
			if (boardArrayPlayer2[rows][columns] == 0)
			{
				cout << " " << " " << " ";
			}
			else
			{
				cout << " " << actualPlayer2.pokemonTeam[rows].tag << " ";
			}
			cout << verticalColumn;
		}
		cout << " " << " " << " " << verticalColumn;
		cout << endl;
		if (rows == 1)
		{
			cout << "\t""\t""\t""\t""\t""\t""\t""\t" << lowerLeftCorner;
			for (int columns = 0; columns < maxColumns; columns++)
			{
				cout << horizontalRow << horizontalRow << horizontalRow;
				cout << lowerConection;
			}
			cout << horizontalRow << horizontalRow << horizontalRow;
			cout << lowerRightCorner;
		}
	}
	cout << endl;

}
Pokemon pokemonMaker(Player actualPlayer, char pokemonTag, int PokemonLifes, int PokemonLevel, int PokemonDeff)
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
	cout << "\t""\t""Como se va a llamar tu pokemon ?" << endl;
	cout << actualPlayer.name << " ---> ";
	cin >> pokeName;
	cout << "\t""\t""Como se va a llamar tu  1 ataque?" << endl;
	cout << actualPlayer.name << " ---> ";
	cin >> pokeAttk1;
	cout << "\t""\t""Como se va a llamar tu  2 ataque?" << endl;
	cout << actualPlayer.name << " ---> ";
	cin >> pokeAttk2;
	cout << "\t""\t""Como se va a llamar tu  3 ataque?" << endl;
	cout << actualPlayer.name << " ---> ";
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

	return aux;
}