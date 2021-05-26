#pragma once

#include "Board.h"
#include "func.h"

#include <iostream>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
using namespace std;

#define TABLE_Y 22
#define TABLE_X 12
#define ESC 27
#define CHALLENGE_CLEAR 10

void Board::draw_board(int y, int x,int color)
{
	this->board[y][x] = color+1;
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

	setColor(0);
	for (int i = 0; i < TABLE_Y; i++) {
		for (int j = 0; j < TABLE_X; j++) {
			if (board[i][j] == -1) {
				gotoxy(i + 1, 2*j + 2);
				cout << b1;
			}
			else if (board[i][j] == 0) {
				gotoxy(i + 1, 2*j + 2);
				cout << b0;
			}
			else {
				gotoxy(i + 1, 2*j + 2);
				setColor(board[i][j]);
				cout << b2;
				setColor(0);
			}
		}
	}
}

void Board::erase_line()  
{
	for (int Y = 1; Y < TABLE_Y - 1; Y++) { 
		bool isLinear = true;
		for (int X = 1; X < TABLE_X - 1; X++) { 
			if (board[Y][X] == 0) isLinear = false; 
		}
		//한줄이 꽉 채워졌을때
		if (isLinear) {
			//이펙트
			for (int i = 0; i < 3; i++) {
				for (int j = 1; j < TABLE_X - 1; j++) {
					board[Y][j] = 0;
				}
				print_board();
				Sleep(80);
				for (int j = 1; j < TABLE_X - 1; j++) {
					board[Y][j] = 8;
				}
				print_board();
				Sleep(80);
			}
			//줄 지우고 한칸씩 내리기
			for (int i = Y; i > 1; i--) { 
				for (int j = 1; j < TABLE_X - 1; j++) {
					board[i][j] = board[i - 1][j]; 
				}
			}
			print_board();
			//점수추가 및 레벨 조정
			score->score_up();
			*line += 1; 
			if (*line == 5) { // 라인 몇개당 레벨 올릴지
				*line = 0;
				*level += 1;
				gotoxy(5, 4); cout << "■■■■■■■■■■";
				gotoxy(3, 10); cout << "LEVEL UP!";
				Sleep(1000);
				score->change_speed(level);
			}
		}
	}
}

bool Board::check_gameover()
{
	for (int X = 1; X < TABLE_X - 1; X++) {
		if (board[5][X] != 0) {
			//이펙트
			gotoxy(10, 32);
			cout << "GAME OVER!";
			for (int i = 5; i > 0; i--) {
				for (int j = 1; j < TABLE_X - 1; j++) {
					board[i][j] = 8;
				}
				print_board();
				Sleep(80);
			}

			//esc누르면 메인메뉴로 돌아가기
			while (true) {
				char c = _getch();
				if (c == ESC) break;
			}

			return true;
		}
	}
	return false;
}

bool Board::is_clear()
{
	//남아있는 블럭수 체크
	int left_block = 0;
	for (int i = 1; i < TABLE_Y - 1; i++) {
		for (int j = 1; j < TABLE_X - 1; j++) {
			if (board[i][j] != 0) left_block++;
		}
	}
	//클리어 조건
	if (left_block > CHALLENGE_CLEAR) return false;

	//이펙트
	gotoxy(10, 32);
	cout << "Challenge";
	gotoxy(11, 32);
	cout << "  Clear!";

	for (int i = TABLE_Y-1-1; i > 0; i--) {
		for (int j = 1; j < TABLE_X - 1; j++) {
			board[i][j] = 1;
		}
		print_board();
		Sleep(80);
	}
	//esc누르면 메인메뉴로 돌아가기
	while (true) {
		char c = _getch();
		if (c == ESC) break;
	}

	return true;

}

void Board::clear_board(int challenge)
{
	for (int i = 1; i < TABLE_Y - 1; i++) {
		for (int j = 1; j < TABLE_X - 1; j++) {
			board[i][j] = 0;
		}
	}
	//챌린지 일경우 보드 초기화
	if (challenge == 1) {
		board[TABLE_Y - 1 - 1][1] = board[TABLE_Y - 1 - 1][TABLE_X - 1 - 1] = 1;
		board[TABLE_Y - 1 - 2][2] = board[TABLE_Y - 1 - 2][TABLE_X - 1 - 2] = 1;
		board[TABLE_Y - 1 - 3][3] = board[TABLE_Y - 1 - 3][TABLE_X - 1 - 3] = 1;
		board[TABLE_Y - 1 - 4][4] = board[TABLE_Y - 1 - 4][TABLE_X - 1 - 4] = 1;
		board[TABLE_Y - 1 - 5][3] = board[TABLE_Y - 1 - 5][TABLE_X - 1 - 3] = 1;
		board[TABLE_Y - 1 - 6][2] = board[TABLE_Y - 1 - 6][TABLE_X - 1 - 2] = 1;
		board[TABLE_Y - 1 - 7][1] = board[TABLE_Y - 1 - 7][TABLE_X - 1 - 1] = 1;
		board[TABLE_Y - 1 - 8][1] = board[TABLE_Y - 1 - 8][TABLE_X - 1 - 1] = 1;
	}
	else if (challenge == 2) {
		board[TABLE_Y - 1 - 1][5] = board[TABLE_Y - 1 - 1][TABLE_X - 1 - 5] = 4;
		board[TABLE_Y - 1 - 2][4] = board[TABLE_Y - 1 - 2][TABLE_X - 1 - 4] = 4;
		board[TABLE_Y - 1 - 3][3] = board[TABLE_Y - 1 - 3][TABLE_X - 1 - 3] = 4;
		board[TABLE_Y - 1 - 4][2] = board[TABLE_Y - 1 - 4][TABLE_X - 1 - 2] = 4;
		board[TABLE_Y - 1 - 5][1] = board[TABLE_Y - 1 - 5][TABLE_X - 1 - 1] = 4;
		board[TABLE_Y - 1 - 6][2] = board[TABLE_Y - 1 - 6][TABLE_X - 1 - 2] = 4;
		board[TABLE_Y - 1 - 7][3] = board[TABLE_Y - 1 - 7][TABLE_X - 1 - 3] = 4;
		board[TABLE_Y - 1 - 8][4] = board[TABLE_Y - 1 - 8][TABLE_X - 1 - 4] = 4;
	}
	else if (challenge == 3) {
		board[TABLE_Y - 1 - 1][5] = board[TABLE_Y - 1 - 1][TABLE_X - 1 - 5] = 2;
		board[TABLE_Y - 1 - 2][4] = board[TABLE_Y - 1 - 2][TABLE_X - 1 - 4] = 2;
		board[TABLE_Y - 1 - 3][3] = board[TABLE_Y - 1 - 3][TABLE_X - 1 - 3] = 2;
		board[TABLE_Y - 1 - 4][2] = board[TABLE_Y - 1 - 4][TABLE_X - 1 - 2] = 2;
		board[TABLE_Y - 1 - 5][1] = board[TABLE_Y - 1 - 5][TABLE_X - 1 - 1] = 2;
		board[TABLE_Y - 1 - 6][2] = board[TABLE_Y - 1 - 6][TABLE_X - 1 - 2] = 2;
		board[TABLE_Y - 1 - 7][3] = board[TABLE_Y - 1 - 7][TABLE_X - 1 - 3] = 2;
		board[TABLE_Y - 1 - 7][4] = board[TABLE_Y - 1 - 7][TABLE_X - 1 - 4] = 2;
		board[TABLE_Y - 1 - 6][5] = board[TABLE_Y - 1 - 6][TABLE_X - 1 - 5] = 2;
	}
	else if (challenge == 4) {
		board[TABLE_Y - 1 - 1][1] = board[TABLE_Y - 1 - 3][1] = 5;
		board[TABLE_Y - 1 - 5][1] = board[TABLE_Y - 1 - 7][1] = 5;
		board[TABLE_Y - 1 - 2][4] = board[TABLE_Y - 1 - 4][4] = 5;
		board[TABLE_Y - 1 - 6][4] = board[TABLE_Y - 1 - 1][5] = 5;
		board[TABLE_Y - 1 - 3][5] = board[TABLE_Y - 1 - 5][5] = 5;
		board[TABLE_Y - 1 - 2][8] = board[TABLE_Y - 1 - 4][8] = 5;
		board[TABLE_Y - 1 - 1][9] = board[TABLE_Y - 1 - 3][9] = 5;
	}
	else if (challenge == 5) {
		board[TABLE_Y - 1 - 1][3] = board[TABLE_Y - 1 - 1][4] = 1;
		board[TABLE_Y - 1 - 1][5] = board[TABLE_Y - 1 - 1][6] = 1;
		board[TABLE_Y - 1 - 1][7] = board[TABLE_Y - 1 - 1][8] = 1;
		board[TABLE_Y - 1 - 2][3] = board[TABLE_Y - 1 - 2][8] = 1;
		board[TABLE_Y - 1 - 3][8] = board[TABLE_Y - 1 - 4][8] = 1;
		board[TABLE_Y - 1 - 5][3] = board[TABLE_Y - 1 - 5][4] = 1;
		board[TABLE_Y - 1 - 5][5] = board[TABLE_Y - 1 - 5][6] = 1;
		board[TABLE_Y - 1 - 5][7] = board[TABLE_Y - 1 - 5][8] = 1;
		board[TABLE_Y - 1 - 6][3] = board[TABLE_Y - 1 - 7][3] = 1;
		board[TABLE_Y - 1 - 8][3] = board[TABLE_Y - 1 - 8][4] = 1;
		board[TABLE_Y - 1 - 8][5] = board[TABLE_Y - 1 - 8][6] = 1;
		board[TABLE_Y - 1 - 8][7] = board[TABLE_Y - 1 - 8][8] = 1;
	}

}
