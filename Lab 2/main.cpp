#pragma once
#include <iostream>
#include "BasketballPlayer.h"
#include "Team.h"

int main(void) {
	BasketballPlayer team1[5];
	team1[0] = BasketballPlayer("Joe bob", 30, 40, 50, 90);
	team1[1] = BasketballPlayer("Steph Curry", 140, 145, 50, 90);
	team1[2] = BasketballPlayer("Michael Jordan", 100, 110, 70, 85);
	team1[3] = BasketballPlayer("Javele McGee", 10, 80, 5, 120);
	team1[4] = BasketballPlayer("Sample text", 45, 90, 50, 100);

	BasketballPlayer team2[5];
	team2[0] = BasketballPlayer("Kyrie Iving", 20, 80, 50, 120);
	team2[1] = BasketballPlayer("Kanye West", 2, 20, 5, 30);
	team2[2] = BasketballPlayer("Stephen Hawking", 1, 5, 2, 8);
	team2[3] = BasketballPlayer("Shaq", 80, 120, 60, 300);
	team2[4] = BasketballPlayer("Lebron", 50, 100, 60, 70);

	Team home = Team(team1);
	Team away = Team(team2);
	Team t;
	t.PlayGame(&home, &away);
	

	return 0;
}