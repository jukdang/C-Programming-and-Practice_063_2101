#pragma once

#include "Board.h"

class Block
{
private:
	int x;
	int y;
	int shape;
	int direction;
	bool stop;
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
	bool can_place_on_board(); //블럭을 놓을수 있는지 체크
	void draw_block(); //보드에 블럭 그리기
	void erase_block(); //보드에서 블럭 지우기
	Block& create_block(int type); //새 블럭 생성
	bool is_stop(); //블럭이 더 내려갈곳이없는지 체크
	void move_left(); //moveleft
	void move_right(); //moveright
	void move_down(); //movedown
	void rotate_block(); //블럭 회전
	Block& get_block(Block* block); //next블럭->now블럭 가져오기
	void get_keep(Block* after, Block* now); 
	void print_block(int y,int x, int print_type, bool valid); // keep, next블럭 보여주는 인터페이스
	void keeping(bool *can_use_keep, bool *is_keeped, Block *next_block, Block *keep_block);
	
};

