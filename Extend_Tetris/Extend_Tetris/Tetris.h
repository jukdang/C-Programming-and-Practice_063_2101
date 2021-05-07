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
	

public:

	Tetris() {
		Board board;
		Block block(&board, 1);
	}

	void run();
};
