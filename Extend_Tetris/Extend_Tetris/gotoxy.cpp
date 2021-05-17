#pragma once

#include "gotoxy.h"

#include <Windows.h>

void gotoxy(int y, int x) {
	COORD point;
	point.X = x;
	point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}