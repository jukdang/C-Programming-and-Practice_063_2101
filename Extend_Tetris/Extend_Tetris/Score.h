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

	void score_up(); //점수+
	void print_score_speed(); //점수,레벨 콘솔 출력
	void change_speed(int* level); //level에 따른 speed조절
};