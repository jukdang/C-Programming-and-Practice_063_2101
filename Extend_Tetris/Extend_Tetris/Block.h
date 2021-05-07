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
	Block(Board *board, int type) {
		x = 5, y = 5; direction = 1; saved_shape = 0, next_shape = 0;
		this->board = board;
		shape = type;
	}
	//완성
	bool can_place_on_board();
	void draw_block();
	void erase_block();

	//미완성
	void rotate_block();  
	void move_left();  
	void move_right(); 
	void move_down();  

};

