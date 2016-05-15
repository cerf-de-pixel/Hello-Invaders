/*********************************************
**          -   Hello Invaders   -          **
**********************************************
**                                          **
**      Programmer par cerf-de-pixel.fr     **
**         <julien@cerf-de-pixel.fr>        **
**                                          **
**********************************************/

#include "stdafx.h"
#include "ConsoleUtile.h"

using namespace std;

/**************************************
*  modifier l'emplacement du curseur  *
***************************************/
void GotoXY(int x, int y)
{
	COORD dwCursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwCursorPosition);
}

/**************************************
*    efface le texte de la console    *
***************************************/
void ClearScreen(void)
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hstdout, &csbi))
	{
		COORD coordScreen = { 0, 0 };
		DWORD cCharsWritten;
		DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
		FillConsoleOutputCharacter(hstdout, ' ', dwConSize, coordScreen, &cCharsWritten);
		FillConsoleOutputAttribute(hstdout, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
		SetConsoleCursorPosition(hstdout, coordScreen);
	}
}

void color(int f)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, f);
}