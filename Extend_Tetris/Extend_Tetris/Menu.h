#pragma once

#include <iostream>

class Menu {
private:
	int menu[32][7];
public:
	int main_menu();
	int challenge_menu();

	void control_chal(char c, int* num);
	void control_main(char c, int* num);
};