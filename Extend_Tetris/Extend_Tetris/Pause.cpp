#pragma once

#include "Pause.h"
#include <iostream>

#define PLAY 112
#define EXIT 101

using namespace std;

void Pause::print_pause()
{
	system("cls");

	char b0[4] = { "　" };
	char b1[4] = { "□" }; //-1, 테두리
	char b2[4] = { "■" }; //-2, pause 글씨

	//테두리
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 32; j++) {
			if (i == 0 or i == 16 or j == 0 or j == 31) {
				pause[j][i] = -1;
			}
			else {
				pause[j][i] = 9;
			}
		}
	}

	//pause 글씨
	int p[13][2] = { {4, 3}, {5, 3}, {6, 3}, {7, 3}, {4, 4}, {7, 4}, {4, 5}, {5, 5}, {6, 5}, {7, 5}, {4, 6}, {4, 7}, {4, 8} };
	int a[16][2] = { {9, 3}, {10, 3}, {11, 3}, {12, 3}, {9, 4}, {12, 4}, {9, 5}, {10, 5}, {11, 5}, {12, 5}, {9, 6}, {12, 6}, {9, 7}, {12, 7}, {9, 8}, {12, 8} };
	int u[14][2] = { {14, 3}, {17, 3}, {14, 4}, {17, 4}, {14, 5}, {17, 5}, {14, 6}, {17, 6}, {14, 7}, {17, 7}, {14, 8}, {15, 8}, {16, 8}, {17, 8} };
	int s[15][2] = { {19, 3}, {20, 3}, {21, 3}, {22, 3}, {19, 4}, {19, 5}, {20, 5}, {21, 5}, {22, 5}, {22, 6}, {22, 7}, {19, 8}, {20, 8}, {21, 8}, {22, 8} };
	int e[15][2] = { {24, 3}, {25, 3}, {26, 3}, {27, 3}, {24, 4}, {24, 5}, {25, 5}, {26, 5}, {27, 5}, {24, 6}, {24, 7}, {24, 8}, {25, 8}, {26, 8}, {27, 8} };

	for (int i = 0; i < 13; i++) {
		pause[p[i][0]][p[i][1]] = -2;
	}

	for (int i = 0; i < 16; i++) {
		pause[a[i][0]][a[i][1]] = -2;
	}

	for (int i = 0; i < 14; i++) {
		pause[u[i][0]][u[i][1]] = -2;
	}

	for (int i = 0; i < 15; i++) {
		pause[s[i][0]][s[i][1]] = -2;
	}

	for (int i = 0; i < 15; i++) {
		pause[e[i][0]][e[i][1]] = -2;
	}

	//p, e 버튼 처리
	for (int i = 6; i <= 13; i++) {
		pause[i][12] = 0;
		pause[i + 12][12] = 0;
	}

	//출력 
	gotoxy(1, 0);
	for (int i = 0; i < 17; i++) {
		cout << "　";
		for (int j = 0; j < 32; j++) {

			if (pause[j][i] == -1) {
				cout << b1;
			}
			if (pause[j][i] == 9) {
				cout << b0;
			}
			if (pause[j][i] == -2) {
				cout << b2;
			}
			if (i == 12) {
				if (j == 6 or j == 18) {
					cout << "［";
				}
				if (j == 13 or j == 25) {
					cout << "］";
				}
				if (j == 8 or j == 20) {
					cout << "→";
				}
				if (j == 7 or j == 9) {
					cout << "Ｐ";
				}
				if (j == 10) {
					cout << "ｌ";
				}
				if (j == 11) {
					cout << "ａ";
				}
				if (j == 12) {
					cout << "ｙ";
				}
				if (j == 19 or j == 21) {
					cout << "Ｅ";
				}
				if (j == 22) {
					cout << "ｘ";
				}
				if (j == 23) {
					cout << "ｉ";
				}
				if (j == 24) {
					cout << "ｔ";
				}

			}

		}
		cout << endl;
	}
	con_or_esc();
}

void Pause::con_or_esc() {
	char c = _getch();
	switch (c)
	{
	case PLAY:
		system("cls");
		break;
	case EXIT:
		system("cls");
		*running = false;
		//gameover화면
		break;
	default:
		con_or_esc();
	}
}