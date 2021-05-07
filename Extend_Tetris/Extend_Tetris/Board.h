#pragma once

#include "Block.h"

class Board
{
private:
	int board[22][12];
	// 0 : �����
	// -1 : �׵θ�
public:

	Board();  //clear

	void draw_block(int x, int y);
	void erase_block(int x, int y);

	int board_status(int x, int y);
	

	void clear_board();
	void erase_line();
	void check_gameover();
	void print_board();  //clear
};

