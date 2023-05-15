#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>

struct LeaderBoardItem {
	char name[20];
	int score;
};

class LeaderBoard {
public:
	LeaderBoard();
	~LeaderBoard();
	void addScore(char* name, int score);
	void render();
	void saveScores();
	void loadScores();

private:
	std::vector<LeaderBoardItem> _scores;
};

#endif