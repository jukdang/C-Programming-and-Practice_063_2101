#pragma once
class Score
{
private:
	int score;
	int* speed;
	int* line;
	int* level;

public:
	Score(int* speed, int* line, int* level) {
		score = 0;
		this->speed = speed;
		this->line = line;
		this->level = level;
	}

	void score_up();
	void print_score_speed();
	void change_speed(int* level);
};