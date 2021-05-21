#pragma once

#include "gotoxy.h"

#include <conio.h>

class Pause {
private:
	int pause[32][17];
	bool* running;
public:
	Pause(bool* running) {
		this->running = running;
	}
	void print_pause();
	void con_or_esc();
};