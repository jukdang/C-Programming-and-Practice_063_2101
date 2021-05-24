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


int main() {

	Tetris tetris;
	Mainmenu mainmenu;
	mainmenu.print_menu();

	while (1) {
		char c = _getch();
		switch (c) {
		case START:
			system("cls");
			tetris.run();
			break;
		case CHALL:
			system("cls");
			//ç���� ��� ���°�
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

