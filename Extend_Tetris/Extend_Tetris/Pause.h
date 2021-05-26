#pragma once

class Pause {
private:
	int pause[32][17];
	bool* running;
public:
	Pause(bool* running) {
		this->running = running;
	}

	void print_pause(); //pause화면 콘솔 출력
	void con_or_esc(char c, int* num); //pause화면 키입력 컨트롤
};