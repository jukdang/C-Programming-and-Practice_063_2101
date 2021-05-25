#pragma once

#include <iostream>

class Menu {
private:
	int menu[32][7];
public:
	void main_menu();
	int challenge_menu();

	void control_cur(char c, int* num);
};