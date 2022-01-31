#include "Team.h"

using namespace std;

Team::Team() {}

Team::Team(BasketballPlayer players[5]) {
	this->Players[0] = players[0];
	this->Players[1] = players[1];
	this->Players[2] = players[2];
	this->Players[3] = players[3];
	this->Players[4] = players[4];
}

void Team::Possession(Team* team, int possessionsRemaining) {
	this->hasBall = &(this->Players[rand() % 5]);
	this->hasBall->DisplayStats();

	int choice;
	cout << "Select one of the options below by typing the number and pressing enter: " << endl
		<< "[1X] Shoot, where x is 1, 2, or 3" << endl
		<< "[2] Pass" << endl
		<< "[3] See player stats" << endl
		<< "[4] See score" << endl;
	cin >> choice;


	int buffer;
	switch (choice) {
	case 11:
		buffer = this->hasBall->TakeShot(1);
		if (buffer) {
			this->score += buffer;
			cout << "Possession has swapped teams." << endl;
		}
		else {
			float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			if (r > .5f) {
				cout << "Offensive rebound, possession retained!" << endl;
				this->Possession(team, possessionsRemaining);
				break;
			}
			cout << "Turnover!" << endl;
		}
		break;
	case 12:
		buffer = this->hasBall->TakeShot(2);
		if (buffer) {
			this->score += buffer;
			cout << "Possession has swapped teams." << endl;
		} else {
			float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			if (r > .5f) {
				cout << "Offensive rebound, possession retained!" << endl;
				this->Possession(team, possessionsRemaining);
				break;
			}
			cout << "Turnover!" << endl;
		}
		break;
	case 13:
		buffer = this->hasBall->TakeShot(3);
		if (buffer) {
			this->score += buffer;
			cout << "Possession has swapped teams." << endl;
		} else {
			float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			if (r > .5f) {
				cout << "Offensive rebound, possession retained!" << endl;
				this->Possession(team, possessionsRemaining);
				break;
			}
			cout << "Turnover!" << endl;		
		}
		break;
	case 2:
		for (int i = 0; i < 5; i++) {
			if (this->Players[i].Name != this->hasBall->Name) {
				cout << '[' << i + 1 << ']' << endl;
				this->Players[i].DisplayStats();
			}
		}

		do {
			cout << "Choose the player number you would like to pass to: ";
			cin >> buffer;
			if (this->Players[buffer].Name == this->hasBall->Name) {
				cout << "Pick a different player." << endl;
				continue;
			}
		} while (false);

		if (this->hasBall->PassBall()) {
			this->hasBall = &(this->Players[buffer]);
			this->Possession(team, possessionsRemaining);
		}

		break;
	case 3:
		this->hasBall->DisplayStats();
		this->Possession(team, possessionsRemaining);
		break;
	case 4:
		cout << "Score: " << this->score << '-' << team->getScore() << endl;
		this->Possession(team, possessionsRemaining);
		break;
	default:
		break;
	}
}

void Team::PlayGame(Team* home, Team* away) {
	int buffer;
	for (int i = 0; i < 40; i++) {
		if (i % 2 == 0) {
			home->Possession(away, i);
		}
		else {
			do {
				float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

				if (r < .6) {
					away->setScore(away->getScore() + 2);
					cout << "Bot scored!" << endl;
					break;
				}
				else {
					cout << "Bot missed!" << endl;
					float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
					if (r > .5)
						break;
				}
			} while (true);
		}
	}
}
