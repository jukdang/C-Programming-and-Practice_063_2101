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
	//�ϼ�
	bool can_place_on_board(); //���� ������ �ִ��� üũ
	void draw_block(); //���忡 �� �׸���
	void erase_block(); //���忡�� �� �����
	Block& create_block(int type); //�� �� ����
	bool is_stop(); //���� �� ���������̾����� üũ
	void move_left(); //moveleft
	void move_right(); //moveright
	void move_down(); //movedown
	void rotate_block(); //�� ȸ��
	Block& get_block(Block* block); //next��->now�� ��������
	void get_keep(Block* after, Block* now); 
	void print_block(int y,int x, int print_type, bool valid); // keep, next�� �����ִ� �������̽�
	void keeping(bool *can_use_keep, bool *is_keeped, Block *next_block, Block *keep_block);
	
};

