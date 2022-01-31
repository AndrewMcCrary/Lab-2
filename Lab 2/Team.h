#pragma once
#include <iostream>
#include <random>
#include "BasketballPlayer.h"

class Team {
private:
	BasketballPlayer Players[5];

	BasketballPlayer* hasBall;

	bool hasPossession;

	int score;
	
	void Possession(Team* team, int possessionRemaining);

public:

	Team();

	Team(BasketballPlayer[5]);

	static void PlayGame(Team* home, Team* away);

	int getScore() { return this->score; }

	void setScore(int score) { this->score = score; }

	bool getPossession() { return this->hasPossession; }

	void setPossession(bool p) { this->hasPossession = p; }
};

