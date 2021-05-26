#pragma once

#include "Tetris.h"
#include "Block.h"
#include "Pause.h"
#include "func.h"

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
#define KEEP 107
#define SPACE 32
#define ESC 27
#define CLOCK_PER_SEC 100

void Tetris::run(int challenge)
{
	srand((unsigned int)time(NULL));
	start_time = clock();

	running = true;
	is_keeped = false;
	can_use_keep = true;
	board.clear_board(challenge); //최초 보드 초기화

	//블럭생성
	block.create_block(rand() % 7).draw_block(); 
	next_block.create_block(rand() % 7); 
	
	while (running) {
		//키입력이 있으면 키입력 처리
		if (_kbhit()) {
			char c = _getch();
			process_key(c);
			if(running)	print_screen();
		}
		//키입력이 없으면 일정시간마다 블럭 내려가게
		else {
			if (time_difference() / CLOCK_PER_SEC > speed) {
				block.move_down();

				start_time = clock();

				print_screen();
			}
		}
		//블럭이 바닥에 내려왔다면
		if (block.is_stop()) {
			board.erase_line();
			//게임오버인가?
			if (board.check_gameover()) {
				running = false;
				break;
			}
			//챌린지일경우 클리어조건확인
			if (challenge!=0) {
				if (board.is_clear()) {
					running = false;
					break;
				}
			}
			//다음블럭생성
			block.get_block(&next_block).draw_block();
			next_block.create_block(rand() % 7);
			can_use_keep = true;

			print_screen();
		}
	}

}

double Tetris::time_difference()
{
	clock_t now_time = clock();
	return now_time - start_time;
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
	case ESC: 
		pause.print_pause();
		break;
	case SPACE: 
		//킵횟수 확인
		if (can_use_keep) {
			block.erase_block();
			//킵한적 있으면 keep <-> now
			if (is_keeped) {
				Block temp(&board);
				temp.get_keep(&keep_block);
				keep_block.get_keep(&block);
				block.get_keep(&temp);
				//swap 가능여부 확인
				if (!block.can_place_on_board()) {
					temp.get_keep(&keep_block);
					keep_block.get_keep(&block);
					block.get_keep(&temp);
					break;
				}
				can_use_keep = false;
			}
			//처음 킵하면 next-> now
			else {
				keep_block.get_keep(&block);
				block.get_keep(&next_block);
				//swap 가능여부 확인
				if (!block.can_place_on_board()) {
					next_block.get_keep(&block);
					block.get_keep(&keep_block);
					break;
				}
				next_block.create_block(rand() % 7);
				is_keeped = true;
				can_use_keep = false;
			}
			block.draw_block();
		}
		break;
	default:
		break;
	}
}

void Tetris::print_screen()
{
	board.print_board();
	next_block.print_block(1, 30, 1, true); 
	keep_block.print_block(14, 30, 2, is_keeped); 
	score.print_score_speed();
	gotoxy(0, 0);
}
