#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>

struct LeaderBoardItem {
	char name[20];
	int score;
};

class LeaderBoard {
public:
	LeaderBoard() = default;
	~LeaderBoard(){};
	void addScore(char* name, int score);
	void render();
	void saveScores(const char* fileName = "leaderboard.txt");
	void loadScores(const char* fileName = "leaderboard.txt");

private:
	std::vector<LeaderBoardItem> _scores;
};

#endif