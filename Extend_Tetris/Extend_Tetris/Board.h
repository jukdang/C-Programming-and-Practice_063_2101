#pragma once


class Board
{
private:
	int board[22][12];
	// 1 : 블럭
	// 0 : 빈공간
	// -1 : 테두리
public:
	
	Board() {
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
	};

	void draw_board(int y, int x);
	void erase_board(int y, int x);
	int board_status(int y, int x);
	void print_board();
	void clear_board();
	void erase_line();
	bool check_gameover();
	
};

