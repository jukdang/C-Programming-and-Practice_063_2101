#pragma once

#include "Tetris.h"
#include "gotoxy.h"
#include "Mainmenu.h"

#include <iostream>
#include <conio.h>
#include <Windows.h>

#define RE 114
#define ESC 27
#define START 49
#define CHALL 50
#define END 51

void CursorView(char show);

int main() {

	
	CursorView(0);

	Tetris tetris;
	Mainmenu mainmenu;
	mainmenu.print_menu();
	int challenge = 0;

	while (1) {
		char c = _getch();
		switch (c) {
		case START:
			system("cls");
			tetris.run(0); //Normal Mode
			break;
		case CHALL:
			system("cls");
			challenge = mainmenu.select_challenge_menu();
			system("cls");
			tetris.run(challenge); //Challenge Mode
			break;
		case END:
			system("cls");
			std::cout << "See you again" << std::endl;
			tetris.change_running();
			break;
		default:
			continue;
		}
		break;
	}
	


}

void CursorView(char show)//Ä¿¼­¼û±â±â
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}