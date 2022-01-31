#include "BasketballPlayer.h"

using namespace std;

BasketballPlayer::BasketballPlayer() {
	this->Name = "";
	this->ShotsMade = 0;
	this->ShotsTaken = 0;
	this->PassesMade = 0;
	this->PassesAttempted = 0;
}

BasketballPlayer::BasketballPlayer(string name, int shotsmade, int shotstaken, int passesmade, int passesattempted) {
	this->Name = name;
	this->ShotsMade = shotsmade;
	this->ShotsTaken = shotstaken;
	this->PassesMade = passesmade;
	this->PassesAttempted = passesattempted;
}

bool BasketballPlayer::PassBall() {
	int success = (rand() % 100) + 1;

	if (PassesMade / (float)PassesAttempted * 100.0f > success) {
		PassesAttempted++;
		PassesMade++;
		cout << this->Name << " passed successfully!" << endl;
		return 1;
	}
	else {
		PassesAttempted++;
		cout << "Turnover!" << endl;
		return 0;
	}
}

int BasketballPlayer::TakeShot(int score) {
	if (score <= 0 || score >= 4)
		return 0;

	int success = (rand() % (60 + (score * 20)));
	
	if (ShotsMade / (float)ShotsTaken * 100.0f > success) {
		ShotsTaken++;
		ShotsMade++;
		cout << this->Name << " made the shot!" << endl;
		return score;
	}
	else {
		ShotsTaken++;
		cout << "Shot missed!" << endl;
		return 0;
	}
}

void BasketballPlayer::DisplayStats() {
	cout << "Name: " << this->Name << endl;
	cout << "Shots: " << this->ShotsMade << '-' << ShotsTaken << endl;
	cout << "Passes: " << this->PassesMade << '-' << PassesAttempted << endl << endl;
}
