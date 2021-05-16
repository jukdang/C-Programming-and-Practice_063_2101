#pragma once

#include "Board.h"

#include <iostream>
using namespace std;

#define TABLE_Y 22
#define TABLE_X 12


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
	char b0[4] = { "·" };
	char b1[4] = { "□" };
	char b2[4] = { "■" };

	for (int i = 0; i < TABLE_Y; i++) {
		for (int j = 0; j < TABLE_X; j++) {
			if (board[i][j] == -1) cout << b1;
			else if (board[i][j] == 0) cout << b0;
			else if (board[i][j] == 1) cout << b2;
		}
		std::cout << "\n";
	}
}

void Board::clear_board()
{
	for (int i = 1; i < TABLE_Y-1; i++) {
		for (int j = 1; j < TABLE_X-1; j++) {
			board[i][j] = 0;
		}
	}
}

void Board::erase_line()  // 알리님 작성. // 일부 수정
{
	for (int Y = 1; Y < TABLE_Y - 1; Y++) { // 변수수정
		bool isLinear = true;
		for (int X = 1; X < TABLE_X - 1; X++) { 
			if (board[Y][X] == 0) isLinear = false; // 0(3) board(table)
		}
		if (isLinear) {
			for (int i = Y; i > 1; i--) { // 변수수정
				for (int j = 1; j < TABLE_X - 1; j++) {
					board[i][j] = board[i - 1][j]; // board(table)
				}
			}
		}
	}
}

bool Board::check_gameover() // 알리님이 작성. // 일부 수정
{
	for (int X = 1; X < TABLE_X - 1; X++) {
		if (board[5][X] == 1) return true; // 1(3) board(table)  //test를 위해 y=7이면 gameover
	}
	return false;
}
