#pragma once

#include "Tetris.h"
#include "gotoxy.h"
#include "Menu.h"

#include <iostream>
#include <conio.h>
#include <Windows.h>

#define RE 114
#define ESC 27

#define UP 72
#define DOWN 80
#define SELEC 13

#define NORMAL 0
#define CHALLENGE 1
#define EXIT 2

using namespace std;

void CursorView(char show);
void control_cur(char c, int* num);

int main() {

	
	CursorView(0);

	Tetris tetris;
	Menu menu;
	int loop = true;

	while (loop) {
		int challenge = 0;
		int num = 0;
		system("cls");
		menu.main_menu();
		while (1) {
			if (num == 0) {
				gotoxy(12, 24); cout << "¢º";
				gotoxy(12, 36); cout << "¢¸";
				gotoxy(14, 24); cout << "¡¡";
				gotoxy(14, 36); cout << "¡¡";
				gotoxy(16, 24); cout << "¡¡";
				gotoxy(16, 36); cout << "¡¡";
			}

			if (num == 1) {
				gotoxy(12, 24); cout << "¡¡";
				gotoxy(12, 36); cout << "¡¡";
				gotoxy(14, 24); cout << "¢º";
				gotoxy(14, 36); cout << "¢¸";
				gotoxy(16, 24); cout << "¡¡";
				gotoxy(16, 36); cout << "¡¡";
			}

			if (num == 2) {
				gotoxy(12, 24); cout << "¡¡";
				gotoxy(12, 36); cout << "¡¡";
				gotoxy(14, 24); cout << "¡¡";
				gotoxy(14, 36); cout << "¡¡";
				gotoxy(16, 24); cout << "¢º";
				gotoxy(16, 36); cout << "¢¸";
			}

			char c = _getch();
			if (c == SELEC) {
				break;
			}
			control_cur(c, &num);
		}


		switch (num) {
		case NORMAL:
			system("cls");
			tetris.run(0); //Normal Mode
			break;
		case CHALLENGE:
			system("cls");
			challenge = menu.challenge_menu();
			system("cls");
			tetris.run(challenge); //Challenge Mode
			break;
		case EXIT:
			system("cls");
			std::cout << "See you again" << std::endl;
			loop = false;
			break;
		default:
			break;
		}
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

void control_cur(char c, int* num) {
	switch (c) {
	case UP:
		if ((*num) > 0) {
			(*num)--;
		}
		else {
			(*num) = 2;
		}
		break;
	case DOWN:
		if ((*num) < 2) {
			(*num)++;
		}
		else {
			(*num) = 0;
		}
		break;
	}
}