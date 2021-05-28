#pragma once

#include <time.h>

#include "Score.h"

class Board
{
private:
	int board[22][12];
	// 1�̻� : ��
	// 0 : �����
	// -1 : �׵θ�
	Score* score;
	int* line;
	int* level;
	int* challenge;
	clock_t* pause_t;
	clock_t pause_tt;
	clock_t pause_o;

public:
	Board(Score* score, int* line, int* level, int* challenge, clock_t* pause_t) {
		//�׵θ�
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

		this->challenge = challenge;
		this->score = score;
		this->line = line;
		this->level = level;
		this->pause_t = pause_t;
		pause_tt = 0;
		pause_o = 0;
	};

	void draw_board(int y, int x, int color); //�� ���忡 �׸���
	void erase_board(int y, int x); //�� ���忡�� �����
	int board_status(int y, int x); //��ǥ�� ����ִ��� üũ
	void print_board(); //�ܼ� ���� ���
	void clear_board(int challenge); //���� �ʱ�ȭ
	void erase_line(); //���� �����
	bool check_gameover(); //���ӿ��� üũ
	bool is_clear(); //ç�������� Ŭ���� ���� üũ
	void print_how_to(clock_t start_t);
	void reset_time();
};