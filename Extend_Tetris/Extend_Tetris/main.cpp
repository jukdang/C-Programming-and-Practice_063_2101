#pragma once

#include "Tetris.h"
#include "gotoxy.h"

#include <iostream>
#include <conio.h>
#include <Windows.h>

#define RE 114
#define ESC 27


int main() {

	bool playing = false;

	Tetris tetris;

	playing = true;
	while (playing) {
		system("cls");
		tetris.run();


		system("cls");
		gotoxy(10, 22);
		std::cout << "[Game over]";
		gotoxy(12, 10);
		std::cout << "[다시 시작하려먼 \'R\'키를 눌러주세요]";


		bool waiting_key_input = true;
		while (waiting_key_input) {
			if (_kbhit()) {
				char c = _getch();
				switch (c) {
				case RE:
					waiting_key_input = false;
					playing = true;
					break;
				case ESC:
					waiting_key_input = false;
					playing = false;
					break;
				default:
					waiting_key_input = true;
					break;
				}
			}
		}



	}
	


}

