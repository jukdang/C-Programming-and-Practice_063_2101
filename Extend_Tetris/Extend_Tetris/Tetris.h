#pragma once

#include "Block.h"
#include "Board.h"
#include "Score.h"
#include "Pause.h"
#include <iostream>

class Tetris
{
private:
	Block block;
	Block keep_block;
	Block next_block;
	Board board;
	Score score;
	Pause pause;
	bool running;
	bool is_keeped;
	bool can_use_keep;
	int speed;
	int line;
	int level;
	clock_t start_time;

public:
	Tetris() : board(&score, &line, &level), block(&board), next_block(&board), keep_block(&board), score(&speed, &line, &level), pause(&running) {
		running = true;
		is_keeped = false;
		can_use_keep = false;
		speed = 5;
		start_time = clock();
		line = 0; 
		level = 1;
	};

	void run(int challenge); //테트리스 시작(챌린지여부)
	double time_difference(); //시간차 확인
	void process_key(char c); //키입력 처리
	void print_screen(); //콘솔 화면 출력

};

