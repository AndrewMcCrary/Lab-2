#pragma once
#include <iostream>
#include <random>
#include "BasketballPlayer.h"

class Team {
private:
	BasketballPlayer Players[5];

	BasketballPlayer* hasBall = nullptr;

	int score = 0;

	int botScore = 0;
	
	void Possession(Team* team, int possessionRemaining);

public:

	Team();

	Team(BasketballPlayer[5]);

	static void PlayGame(Team* t);

	int getScore() { return this->score; }

	void setScore(int score) { this->score = score; }
};

