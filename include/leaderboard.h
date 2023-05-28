#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <iostream>
#include <vector>
#include "texture.h"

/// @brief A ranglista egy elemét reprezentáló struct.
struct LeaderBoardItem {
	char name[20];
	int score;

	/// @brief Kiíró operátor csv formátumban.
	friend std::ostream& operator<<(std::ostream& os, const LeaderBoardItem& item);

	/// @brief Beolvasó operátor csv formátumból.
	friend std::istream& operator>>(std::istream& is, LeaderBoardItem& item);
};

/// @brief A ranglistát reprezentáló osztály.
class LeaderBoard {
public:
	~LeaderBoard();

	/// @brief Új elem hozzáadása a ranglistához.
	/// @param item A ranglistához hozzáadandó elemre mutató pointer.
	void addScore(LeaderBoardItem* item);

	/// @brief A ranglista kirajzolása.
	void render();

	/// @brief A ranglista kiírása csv formátumban.
	/// @param os A stream, amire a ranglista kiírásra kerül.
	void saveScores(std::ostream& os);

	/// @brief A ranglista beolvasása csv formátumból.
	/// @param is A stream, amiről a ranglista beolvasásra kerül.
	void loadScores(std::istream& is);

private:
	std::vector<LeaderBoardItem*> _scores;
};

#endif