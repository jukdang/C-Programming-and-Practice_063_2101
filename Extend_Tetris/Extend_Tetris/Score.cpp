#pragma once

#include "Score.h"
#include "gotoxy.h"

#include <iostream>

using namespace std;

void Score::score_up() { //ver.2 추가
	score += 200 / *speed;
}

void Score::print_score() { //ver.2 추가
	gotoxy(22, 30);
	cout << " Score : ";
	gotoxy(22, 39);
	cout << score;
}