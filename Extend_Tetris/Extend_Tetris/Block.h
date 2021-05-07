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

	void rotate_block();  //rotate������ can_place_on_board()���� Ȯ���� true->rotate, false->�״��
	void move_left();  //move������ can_place_on_board()���� Ȯ���� true->move, false->�״��
	void move_right();  //move������ can_place_on_board()���� Ȯ���� true->move, false->�״��
	void move_down();  //move������ can_place_on_board()���� Ȯ���� true->move, false->erase _line()����,

};

