#pragma once

#include "Block.h"
#include "Board.h"
#include "gotoxy.h"

#include <iostream>


int block_list[7][4][4][2] = {
	//O미노 : 1
	{ { {0,0},{1,0},{0,1},{1,1} }, { {0,0},{1,0},{0,1},{1,1} }, { {0,0},{1,0},{0,1},{1,1} }, { {0,0},{1,0},{0,1},{1,1} } },
	//I미노 : 2
	{ { {0,0},{1,0},{2,0},{3,0} }, { {0,0},{0,1},{0,2},{0,3} }, { {0,0},{1,0},{2,0},{3,0} }, { {0,0},{0,1},{0,2},{0,3} } },
	//Z미노 : 3
	{ { {0,0},{0,1},{1,1},{1,2} }, { {1,0},{0,1},{1,1},{2,0} }, { {0,0},{0,1},{1,1},{1,2} }, { {1,0},{0,1},{1,1},{2,0} } },
	//S미노 : 4
	{ { {0,1},{1,0},{1,1},{0,2} }, { {0,0},{1,0},{1,1},{2,1} }, { {0,1},{1,0},{1,1},{0,2} }, { {0,0},{1,0},{1,1},{2,1} } },
	//J미노 : 5
	{ { {0,1},{1,1},{2,1},{2,0} }, { {0,0},{1,0},{1,1},{1,2} }, { {0,0},{1,0},{0,1},{2,0} }, { {0,0},{0,1},{0,2},{1,2} } },
	//L미노 : 6
	{ { {0,0},{1,0},{2,0},{2,1} }, { {0,0},{0,1},{1,0},{0,2} }, { {0,0},{0,1},{1,1},{2,1} }, { {1,0},{1,1},{1,2},{0,2} } },
	//T미노 : 7
	{ { {1,0},{0,1},{1,1},{1,2} }, { {0,0},{1,0},{2,0},{1,1} }, { {0,0},{0,1},{0,2},{1,1} }, { {1,0},{0,1},{1,1},{2,1} } },
};


bool Block::can_place_on_board()
{
	for (int i = 0; i < 4; i++) {
		int nx = this->x + block_list[this->shape][this->direction][i][1];
		int ny = this->y + block_list[this->shape][this->direction][i][0];

		if (0 != board->board_status(ny, nx)) return false;
	}
	
	return true;;
}

void Block::draw_block()
{
	for (int i = 0; i < 4; i++) {
		int nx = this->x + block_list[this->shape][this->direction][i][1];
		int ny = this->y + block_list[this->shape][this->direction][i][0];

		board->draw_board(ny, nx);
	}
}

void Block::erase_block()
{
	for (int i = 0; i < 4; i++) {
		int nx = this->x + block_list[this->shape][this->direction][i][1];
		int ny = this->y + block_list[this->shape][this->direction][i][0];

		board->erase_board(ny, nx);
	}
}

Block& Block::create_block(int type)
{
	x = 5;
	y = 4;
	shape = type;
	direction = 0;
	stop = false;
	return *this;
}

void Block::rotate_block() // 편경찬 작성
{

	Block::erase_block();  // 일단 지우고 

	direction = direction + 1;		// 모양도 돌려놓고 
	if (direction == 4)
		direction = 0;

	if (Block::can_place_on_board())	 	//true면 돌린 모양 그리고 
		Block::draw_block();

	else
	{
		direction = direction - 1;		//false면 돌리기전 모양 그리고 
		Block::draw_block();
	}
}

Block& Block::get_block(Block* block)
{
	this->x = block->x;
	this->y = block->y;
	this->direction = block->direction;
	this->shape = block->shape;
	this->stop = block->stop;

	return *this;
}
Block& Block::get_keep(Block* block)
{
	this->direction = 0;
	this->shape = block->shape;
	this->stop = block->stop;

	return *this;
}

void Block::print_block(int y, int x, int print_type, bool valid)
{
	if (print_type == 1) {
		gotoxy(y, x); std::cout << "□□ Next □□";
	}
	else {
		gotoxy(y, x); std::cout << "□□ Keep □□";
	}
	for (int i = 1; i < 6; i++) {
		gotoxy(y + i, x); std::cout << "□          □";
	}
	gotoxy(y+6, x); std::cout << "□□□□□□□";

	if (valid) {
		for (int i = 0; i < 4; i++) {
			gotoxy(y + 2 + block_list[shape][0][i][0], x + 4 + block_list[shape][0][i][1] * 2);
			std::cout << "■";
		}
	}
	
	
}

void Block::move_down() //김채원 작성
{
	erase_block();
	this->y += 1;
	if (can_place_on_board()) {
		draw_block();
	}
	else {
		this->y -= 1;
		Block::stop = true;
		draw_block();
	}
}

void Block::move_left() //김채원 작성
{
	erase_block();
	this->x -= 1;
	if (can_place_on_board()) {
		draw_block();
	}
	else {
		this->x += 1;
		draw_block();
	}
}

void Block::move_right() //김채원 작성
{
	erase_block();
	this->x += 1;
	if (can_place_on_board()) {
		draw_block();
	}
	else {
		this->x -= 1;
		draw_block();
	}
}

bool Block::is_stop()
{
	if (stop) return true;
	return false;
}
