#pragma once

#include "Block.h"
#include "Board.h"


int block_list[7][4][4][2] = {
	//O�̳� : 1
	{ { {0,0},{1,0},{0,1},{1,1} }, { {0,0},{1,0},{0,1},{1,1} }, { {0,0},{1,0},{0,1},{1,1} }, { {0,0},{1,0},{0,1},{1,1} } },
	//I�̳� : 2
	{ { {0,0},{1,0},{2,0},{3,0} }, { {0,0},{0,1},{0,2},{0,3} }, { {0,0},{1,0},{2,0},{3,0} }, { {0,0},{0,1},{0,2},{0,3} } },
	//Z�̳� : 3
	{ { {0,0},{0,1},{1,1},{1,2} }, { {1,0},{0,1},{1,1},{2,0} }, { {0,0},{0,1},{1,1},{1,2} }, { {1,0},{0,1},{1,1},{2,0} } },
	//S�̳� : 4
	{ { {0,1},{1,0},{1,1},{0,2} }, { {0,0},{1,0},{1,1},{2,1} }, { {0,1},{1,0},{1,1},{0,2} }, { {0,0},{1,0},{1,1},{2,1} } },
	//J�̳� : 5
	{ { {0,1},{1,1},{2,1},{2,0} }, { {0,0},{1,0},{1,1},{1,2} }, { {0,0},{1,0},{0,1},{2,0} }, { {0,0},{0,1},{0,2},{1,2} } },
	//L�̳� : 6
	{ { {0,0},{1,0},{2,0},{2,1} }, { {0,0},{0,1},{1,0},{0,2} }, { {0,0},{0,1},{1,1},{2,1} }, { {1,0},{1,1},{1,2},{0,2} } },
	//T�̳� : 7
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

void Block::create_block(int type)
{
	x = 5;
	y = 5;
	shape = type;
	direction = 0;
	stop = false;
	draw_block();
}

void Block::rotate_block() // ������� �ۼ�
{
	int i, j;

	Block::erase_block();  // �ϴ� ����� 

	direction = direction + 1;		// ��絵 �������� 
	if (direction == 4)
		direction = 0;

	if (Block::can_place_on_board())	 	//true�� ���� ��� �׸��� 
		Block::draw_block();

	else
	{
		direction = direction - 1;		//false�� �������� ��� �׸��� 
		Block::draw_block();
	}
}

void Block::move_down() //��ä���� �ۼ�
{
	erase_block();
	this->y += 1;
	if (can_place_on_board()) {
		draw_block();
	}
	else {
		this->y -= 1;
		Block::stop = true;
		draw_block(); // �߰�
	}
}

void Block::move_left() //��ä���� �ۼ�
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

void Block::move_right() //��ä���� �ۼ�
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