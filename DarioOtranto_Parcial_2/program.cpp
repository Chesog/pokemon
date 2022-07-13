#include "program.h"

void mainMenu()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SetConsoleTitle((L"Batalla de Pokemones, la venganza de Pikachu"));

	int pointerCursor = (int)MenuStates::Gameplay;
	int menuAnsw = 0;

	bool gameOn = true;

	do
	{
		switch (menuAnsw)
		{
		case (int)MenuStates::MainMenu:
			menuAnsw = showMainMenu(pointerCursor);
			break;
		case (int)MenuStates::Gameplay:
			menuAnsw = modeSelection(pointerCursor);
			break;
		case (int)MenuStates::Rules:
			menuAnsw = showRules();
			break;
		case (int)MenuStates::Credits:
			menuAnsw = credits();
			break;
		case (int)MenuStates::Exit:
			gameOn = exitProgram();
			break;
		default:
			break;
		}
	} while (gameOn);
}
int showMainMenu(int& pointerCursor)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD consolecursorposition = { 0,0 };
	int answ;
	system("cls");
	SetConsoleTextAttribute(h, 14);
	cout << R"(
			______         _           _  _              _        ______         _                                                    
			| ___ \       | |         | || |            | |       | ___ \       | |                                                   
			| |_/ /  __ _ | |_   __ _ | || |  __ _    __| |  ___  | |_/ /  ___  | | __  ___  _ __ ___    ___   _ __    ___  ___       
			| ___ \ / _` || __| / _` || || | / _` |  / _` | / _ \ |  __/  / _ \ | |/ / / _ \| '_ ` _ \  / _ \ | '_ \  / _ \/ __|      
			| |_/ /| (_| || |_ | (_| || || || (_| | | (_| ||  __/ | |    | (_) ||   < |  __/| | | | | || (_) || | | ||  __/\__ \      
			\____/  \__,_| \__| \__,_||_||_| \__,_|  \__,_| \___| \_|     \___/ |_|\_\ \___||_| |_| |_| \___/ |_| |_| \___||___/      
			                                                                                                                          
			                                                                                                                          
			 _                                                                    _        ______  _  _                  _            
			| |                                                                  | |       | ___ \(_)| |                | |           
			| |  __ _  __   __  ___  _ __    __ _   __ _  _ __   ____  __ _    __| |  ___  | |_/ / _ | | __  __ _   ___ | |__   _   _ 
			| | / _` | \ \ / / / _ \| '_ \  / _` | / _` || '_ \ |_  / / _` |  / _` | / _ \ |  __/ | || |/ / / _` | / __|| '_ \ | | | |
			| || (_| |  \ V / |  __/| | | || (_| || (_| || | | | / / | (_| | | (_| ||  __/ | |    | ||   < | (_| || (__ | | | || |_| |
			|_| \__,_|   \_/   \___||_| |_| \__, | \__,_||_| |_|/___| \__,_|  \__,_| \___| \_|    |_||_|\_\ \__,_| \___||_| |_| \__,_|
			                                 __/ |                                                                                    
			                                |___/                                                                                     )" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 9);
	SetConsoleTextAttribute(h, 11);
	if (pointerCursor == (int)MenuStates::Gameplay)
	{
		SetConsoleTextAttribute(h, 144);
	}
	consolecursorposition = { 80,18 };
	SetConsoleCursorPosition(h, consolecursorposition);
	cout << ".-------." << endl;
	consolecursorposition = { 80,19 };
	SetConsoleCursorPosition(h, consolecursorposition);
	cout << "| Jugar |" << endl;
	consolecursorposition = { 80,20 };
	SetConsoleCursorPosition(h, consolecursorposition);
	cout << "'-------'" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 11);
	if (pointerCursor == (int)MenuStates::Rules)
	{
		SetConsoleTextAttribute(h, 144);
	}
	consolecursorposition = { 80,22 };
	SetConsoleCursorPosition(h, consolecursorposition);
	cout << ".--------." << endl;
	consolecursorposition = { 80,23 };
	SetConsoleCursorPosition(h, consolecursorposition);
	cout << "| Reglas |" << endl;
	consolecursorposition = { 80,24 };
	SetConsoleCursorPosition(h, consolecursorposition);
	cout << "'--------'" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 11);
	if (pointerCursor == (int)MenuStates::Credits)
	{
		SetConsoleTextAttribute(h, 144);
	}
	consolecursorposition = { 80,26 };
	SetConsoleCursorPosition(h, consolecursorposition);
	cout << ".----------." << endl;
	consolecursorposition = { 80,27 };
	SetConsoleCursorPosition(h, consolecursorposition);
	cout << "| Creditos |" << endl;
	consolecursorposition = { 80,28 };
	SetConsoleCursorPosition(h, consolecursorposition);
	cout << "'----------'" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 11);
	if (pointerCursor == (int)MenuStates::Exit)
	{
		SetConsoleTextAttribute(h, 144);
	}
	consolecursorposition = { 80,30 };
	SetConsoleCursorPosition(h, consolecursorposition);
	cout << ".-------." << endl;
	consolecursorposition = { 80,31 };
	SetConsoleCursorPosition(h, consolecursorposition);
	cout << "| Salir |" << endl;
	consolecursorposition = { 80,32 };
	SetConsoleCursorPosition(h, consolecursorposition);
	cout << "'-------'" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 11);
	SetConsoleTextAttribute(h, 9);
	cout << "\t""Usar W para subir" << endl;
	cout << "\t""Usar S para bajar" << endl;
	cout << "\t""Usar E para selecionar" << endl;

	answ = pointer((int)MenuStates::Exit, (int)MenuStates::Gameplay, pointerCursor);
	return answ;
}