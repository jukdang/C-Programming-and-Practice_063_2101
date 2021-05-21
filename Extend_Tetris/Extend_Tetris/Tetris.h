#pragma once

#include "Block.h"
#include "Board.h"
#include "Score.h"
#include "KeyInput.h"
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
	
	int speed;

	clock_t start_time;

public:

	Tetris() : board(&score), block(&board), next_block(&board), keep_block(&board), score(&speed), pause(&running) {
		running = true;
		speed = 5;
		start_time = clock();
	};

	void run();

	double time_difference();

	void process_key(char c);

	void print_screen();

	

};

