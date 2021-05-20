#pragma once

class Score
{
private:
	int score;
	int* speed;

public:
	Score(int* speed) {
		score = 0;
		this->speed = speed;
	}

	void score_up();
	void print_score();
};