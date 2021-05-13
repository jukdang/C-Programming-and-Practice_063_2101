#pragma once

#include "Board.h"

class Block
{
private:
	int x;
	int y;
	int shape;
	int direction;

	int stop;

	Board* board;


public:
	Block(Board *board) {
		x = 0;
		y = 0;
		direction = 0;
		shape = 0;
		stop = false;
		this->board = board;
	}
	//완성
	bool can_place_on_board();
	void draw_block();
	void erase_block();
	void create_block(int type);
	bool is_stop();

	//미완성
	void rotate_block();  
	void move_left();  
	void move_right(); 
	void move_down();  

	
};

