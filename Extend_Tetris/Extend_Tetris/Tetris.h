#pragma once

#include "Block.h"
#include "Board.h"
#include "Score.h"
#include "KeyInput.h"
#include <iostream>

class Tetris
{
private:
	
	Block block;

	Board board;

	Score score;

	bool running;
	
	int speed;

	clock_t start_time;

public:

	Tetris() : board(), block(&board) {
		running = true;
		speed = 5;
		start_time = clock();
	};

	void run();

	double time_difference();

	void process_key(char c);

	void print_screen();

};

