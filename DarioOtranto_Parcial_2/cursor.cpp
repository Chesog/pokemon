#include "cursor.h"

int pointer(int maxOption, int minOption, int& pointerCursor) // cursor para el menu
{
	COORD consolecursorposition = { 0,0 };

	int defaultOption = 0;
	int max = maxOption;
	int min = minOption;
	char cursor;
	cursor = _getch();
	switch (cursor)
	{
	case 'W':
	case 'w':
		pointerCursor--;
		if (pointerCursor < min)
		{
			pointerCursor = max;
		}
		return defaultOption;
		break;
	case 'S':
	case 's':
		pointerCursor++;
		if (pointerCursor > max)
		{
			pointerCursor = min;
		}
		return defaultOption;
		break;
	case 'E':
	case 'e':
		return pointerCursor;
		break;
	case 'P':
	case 'p':
		pointerCursor = 14;
		return pointerCursor;
		break;
	default:
		return defaultOption;
		break;
	}

}
bool boardPointer(int maxOption, int minOption, int& pointerCursorX, int& pointerCursorY)	// cursor para el tablero del juego
{

	char cursor;
	bool exitToMenu = false;
	cursor = _getch();
	switch (cursor)
	{
	case 'W':
	case 'w':
		pointerCursorY--;
		if (pointerCursorY < minOption)
		{
			pointerCursorY = maxOption;
		}
		return false;
		break;
	case 'S':
	case 's':
		pointerCursorY++;
		if (pointerCursorY > maxOption)
		{
			pointerCursorY = minOption;
		}
		return false;
		break;
	case 'A':
	case 'a':
		pointerCursorX--;
		if (pointerCursorX < minOption)
		{
			pointerCursorX = maxOption;
		}
		return false;
		break;
	case 'D':
	case 'd':
		pointerCursorX++;
		if (pointerCursorX > maxOption)
		{
			pointerCursorX = minOption;
		}
		return false;
		break;
	case 'E':
	case 'e':
		return true;
		break;
	case 'P':
	case 'p':
		exitToMenu = true;
		break;
	default:
		break;
	}

}