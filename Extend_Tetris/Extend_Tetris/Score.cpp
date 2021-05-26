#pragma once

#include "Score.h"
#include "func.h"

#include <iostream>

using namespace std;

namespace SPEED {
	enum {
		LEVEL1 = 7, LEVEL2 = 6, LEVEL3 = 5, LEVEL4 = 4, LEVEL5 = 3, LEVEL6 = 2, LEVEL7 = 1
	};
}

void Score::score_up() { //ver.2 추가
	score += 200 / *speed;
}

void Score::print_score_speed() { //ver.2 추가
	gotoxy(20, 30);
	cout << " Level: ";
	gotoxy(20, 39);
	cout << *level;
	gotoxy(21, 30);
	cout << " Score : "; 
	cout << score; 
	gotoxy(22, 30); //나중에 삭제할 부분 게임하면서 스피드 확인하려고 잠깐 넣어둠
	cout << " Speed: ";
	cout << *speed;
}

void Score::change_speed(int* level) {
	if (*level == 1) {
		*speed = SPEED::LEVEL1;
	}
	if (*level == 2) {
		*speed = SPEED::LEVEL2;
	}
	if (*level == 3) {
		*speed = SPEED::LEVEL3;
	}
	if (*level == 4) {
		*speed = SPEED::LEVEL4;
	}
	if (*level == 5) {
		*speed = SPEED::LEVEL5;
	}
	if (*level == 6) {
		*speed = SPEED::LEVEL6;
	}
	if (*level == 7) {
		*speed = SPEED::LEVEL7;
	}
}