#pragma once

#include "func.h"

#include <Windows.h>

void gotoxy(int y, int x) {
	COORD point;
	point.X = x;
	point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void setColor(unsigned short text) {
	int bg = 240; //240ÇÏ¾ç
	switch (text) {
	case 0:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240 + 0); //ÇÏ¾ç+ÇÏ¾ç
		break;
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg + 10); //ÃÊ
		break;
	case 2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg + 4); //»¡
		break;
	case 3:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg + 11); //ÇÏ´Ã
		break;
	case 4:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg + 13); //ÆÄ¶û
		break;
	case 5:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg + 1); //ÇÎÅ©
		break;
	case 6:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg + 6); //³ë¶û
		break;
	case 7:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg + 2); //
		break;
	case 8:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg + 0); //
		break;
	}


}