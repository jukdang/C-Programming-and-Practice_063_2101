#pragma once

#include <iostream>

class Mainmenu {
private:
	int menu[32][7];
public:
	void print_menu();
	int select_challenge_menu();
};