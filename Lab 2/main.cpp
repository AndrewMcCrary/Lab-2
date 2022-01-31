#pragma once
#include <iostream>
#include "BasketballPlayer.h"
#include "Team.h"

int main(void) {
	BasketballPlayer team1[5];
	team1[0] = BasketballPlayer("Joe bob", 30, 40, 85, 90);
	team1[1] = BasketballPlayer("Steph Curry", 140, 145, 85, 90);
	team1[2] = BasketballPlayer("Michael Jordan", 100, 110, 70, 85);
	team1[3] = BasketballPlayer("Javele McGee", 10, 80, 110, 120);
	team1[4] = BasketballPlayer("Sample text", 45, 90, 90, 100);

	Team myTeam = Team(team1);
	Team t;
	t.PlayGame(&myTeam);
	

	return 0;
}