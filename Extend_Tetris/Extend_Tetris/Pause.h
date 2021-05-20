#pragma once

#include "gotoxy.h"

#include <conio.h>

class Pause {
private:
	int pause[32][17];
public:
	void print_pause();
	void con_or_esc();
};