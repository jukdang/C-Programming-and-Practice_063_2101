#pragma once

#include "Board.h"

#include <iostream>
using namespace std;


void Board::draw_board(int y, int x)
{
	this->board[y][x] = 1;
}

void Board::erase_board(int y, int x)
{
	this->board[y][x] = 0;
}

int Board::board_status(int y, int x)
{
	return this->board[y][x];
}


void Board::print_board()
{
	char b0[4] = { "��" };
	char b1[4] = { "��" };
	char b2[4] = { "��" };

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 12; j++) {
			if (board[i][j] == -1) cout << b1;
			else if (board[i][j] == 0) cout << b0;
			else if (board[i][j] == 1) cout << b2;
		}
		std::cout << "\n";
	}
}
