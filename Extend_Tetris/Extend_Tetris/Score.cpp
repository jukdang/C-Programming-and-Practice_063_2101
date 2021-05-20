#pragma once

#include "Score.h"
#include "gotoxy.h"

#include <iostream>

using namespace std;

void Score::score_up() { //ver.2 추가
	score += 200 / *speed;
}

void Score::print_score() { //ver.2 추가
	gotoxy(20, 30);
	cout << " Score : ";
	gotoxy(20, 39);
	cout << score;
}