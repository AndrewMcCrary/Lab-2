#pragma once
#include <string>
#include <random>
#include <iostream>

class BasketballPlayer {
public:
	std::string Name;
	int ShotsTaken;
	int ShotsMade;
	int PassesAttempted;
	int PassesMade;

	BasketballPlayer();

	BasketballPlayer(std::string name, int shotsmade, int shotstaken, int passesmade, int passesattempted);

	bool PassBall();

	int TakeShot(int);

	void DisplayStats();
};