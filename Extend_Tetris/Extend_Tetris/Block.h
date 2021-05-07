#pragma once

#include "Board.h"

class Block
{
private:
	int x;
	int y;
	int shape;
	int direction;

	int saved_shape;
	
	int next_shape;

	Board* board;



public:
	Block();
	Block(Board *board, int type) : board(board), shape(type) {
		x = 5, y = 5;
		direction = 1;
		saved_shape = 0, next_shape = 0;
	}

	bool can_place_on_board();

	void rotate_block();  //rotate했을때 can_place_on_board()인지 확인후 true->rotate, false->그대로
	void move_left();  //move했을때 can_place_on_board()인지 확인후 true->move, false->그대로
	void move_right();  //move했을때 can_place_on_board()인지 확인후 true->move, false->그대로
	void move_down();  //move했을때 can_place_on_board()인지 확인후 true->move, false->erase _line()실행,

};

