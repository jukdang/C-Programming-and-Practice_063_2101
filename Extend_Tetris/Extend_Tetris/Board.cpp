#pragma once

#include "Board.h"

#include <iostream>
using namespace std;

Board::Board()
{
	for (int i = 0; i < 12; i++) {
		board[0][i] = board[21][i] = -1;
	}
	for (int i = 1; i < 21; i++) {
		board[i][0] = board[i][11] = -1;
	}
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 11; j++) {
			board[i][j] = 0;
		}
	}
}

void Board::draw_block(int y, int x)
{
	board[y][x] = 1;
}

void Board::erase_block(int y, int x)
{
	board[y][x]=0;
}

int Board::board_status(int y, int x)
{
	return board[y][x];
}


void Board::print_board()
{
	char b0[4] = { "бд" };
	char b1[4] = { "бр" };
	char b2[4] = { "бс" };

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 12; j++) {
			if (board[i][j] == -1) cout << b1 << " ";
			else if (board[i][j] == 0) cout << b0 << " ";
			else if (board[i][j] == 1) cout << b2 << " ";
		}
		std::cout << "\n";
	}
}
