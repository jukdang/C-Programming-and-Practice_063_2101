#pragma once

#include "Tetris.h"
#include "gotoxy.h"

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <iostream>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define CLOCK_PER_SEC 100

void Tetris::run()
{
	srand((unsigned int)time(NULL));
	start_time = clock();

	running = true;

	block.create_block(rand() % 7).draw_block();
	next_block.create_block(rand() % 7);
	
	while (running) {
		if (_kbhit()) {
			char c = _getch();
			process_key(c);
			
			print_screen();
		}
		else {
			if (time_difference() / CLOCK_PER_SEC > speed) {
				block.move_down();

				start_time = clock();

				print_screen();
			}
		}
		if (block.is_stop()) {
			
			board.erase_line();
			if (board.check_gameover()) {
				running = false;
				break;
			}

			block.get_next_block(&next_block).draw_block();
			next_block.create_block(rand() % 7);

			print_screen();
		}
	}
	system("cls");
	gotoxy(10, 10);
	std::cout << "Game over";
}

double Tetris::time_difference()
{
	clock_t now_time = clock();
	return now_time-start_time;
}

void Tetris::process_key(char c)
{
	switch (c)
	{
	case UP:
		block.rotate_block();
		break;
	case DOWN:
		block.move_down();
		break;
	case LEFT:
		block.move_left();
		break;
	case RIGHT:
		block.move_right();
		break;
	default:
		break;
	}
}

void Tetris::print_screen()
{
	board.print_board();
	next_block.print_block(1, 30, 1); // print_type=1, next;
	//keep_block.print_block(14,30,2); // print_type=2, keep;
	//score.print_score();
	gotoxy(0, 0);
}

