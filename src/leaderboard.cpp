#include "leaderboard.h"
#include <cstring>
#include <iostream>
#include "presentation.h"
#include "scene_manager.h"
#include "vector2.h"
#include "memtrace.h"

std::ostream& operator<<(std::ostream& os, const LeaderBoardItem& item) {
	os << item.name << " " << item.score;
	return os;
}

std::istream& operator>>(std::istream& is, LeaderBoardItem& item) {
	is >> item.name >> item.score;
	return is;
}

void LeaderBoard::addScore(LeaderBoardItem* item) {
	_scores.push_back(item);
	std::sort(_scores.begin(), _scores.end(), [](const LeaderBoardItem* a, const LeaderBoardItem* b) {
		return a->score > b->score;
	});
}

void LeaderBoard::saveScores(std::ostream& os) {
	for (const LeaderBoardItem* item : _scores) {
		os << *item << std::endl;
	}
}

void LeaderBoard::loadScores(std::istream& is) {
	LeaderBoardItem* item = new LeaderBoardItem();
	while (is >> *item) {
		addScore(item);
		item = new LeaderBoardItem();
	}
	delete item;
}

void LeaderBoard::render() {
	IPresentation* presentation = SceneManager::getInstance().getPresentation();
	for (int i = 0; i < 10; i++) {
		presentation->renderText(_scores[i]->name, Vector2(80, 85 + i * 17));
		presentation->renderText(std::to_string(_scores[i]->score).c_str(), Vector2(285, 85 + i * 17));
	}
}

LeaderBoard::~LeaderBoard() {
	for (LeaderBoardItem* item : _scores) {
		delete item;
	}
}
