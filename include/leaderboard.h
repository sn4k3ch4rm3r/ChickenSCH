#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <iostream>
#include <vector>
#include "texture.h"

struct LeaderBoardItem {
	char name[20];
	int score;

public:
	friend std::ostream& operator<<(std::ostream& os, const LeaderBoardItem& item);
	friend std::istream& operator>>(std::istream& is, LeaderBoardItem& item);
};

class LeaderBoard {
public:
	~LeaderBoard();
	void addScore(LeaderBoardItem* item);
	void render();
	void saveScores(std::ostream& os);
	void loadScores(std::istream& is);

private:
	std::vector<LeaderBoardItem*> _scores;
};

#endif