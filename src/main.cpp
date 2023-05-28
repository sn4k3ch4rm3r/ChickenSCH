#ifndef CPORTA

#include "m_random.h"
#include "scene_manager.h"
#include "memtrace.h"

int main() {
	Random::seed();
	SceneManager& sceneManager = SceneManager::getInstance();

	while (sceneManager.isRunning()) {
		sceneManager.handleEvents();
		sceneManager.update();
		sceneManager.render();
	}

	return 0;
}

#else

#include <iostream>
#include <sstream>
#include <string>
#include "game.h"
#include "game_over.h"
#include "gun.h"
#include "leaderboard.h"
#include "levels.h"
#include "scene_manager.h"
#include "start.h"
#include "vector2.h"
#include "gtest_lite.h"
#include "memtrace.h"

int main() {
	TEST(Vector2Test, Constructor) {
		Vector2 v(2.0, 3.0);
		EXPECT_DOUBLE_EQ(2.0, v.getX());
		EXPECT_DOUBLE_EQ(3.0, v.getY());

		Vector2 v2;
		EXPECT_DOUBLE_EQ(0.0, v2.getX());
		EXPECT_DOUBLE_EQ(0.0, v2.getY());
	}
	END

	TEST(Vector2Test, Addition) {
		Vector2 v1(2.0, 3.0);
		Vector2 v2(1.0, 2.0);
		Vector2 result = v1 + v2;
		EXPECT_DOUBLE_EQ(3.0, result.getX());
		EXPECT_DOUBLE_EQ(5.0, result.getY());

		Vector2 v3(1.0, 2.0);
		v3 += v1;
		EXPECT_DOUBLE_EQ(3.0, v3.getX());
		EXPECT_DOUBLE_EQ(5.0, v3.getY());
	}
	END

	TEST(Vector2Test, Subtraction) {
		Vector2 v1(2.0, 3.0);
		Vector2 v2(1.0, 2.0);
		Vector2 result = v1 - v2;
		EXPECT_DOUBLE_EQ(1.0, result.getX());
		EXPECT_DOUBLE_EQ(1.0, result.getY());

		Vector2 v3(1.0, 2.0);
		v3 -= v1;
		EXPECT_DOUBLE_EQ(-1.0, v3.getX());
		EXPECT_DOUBLE_EQ(-1.0, v3.getY());
	}
	END

	TEST(Vector2Test, Multiplication) {
		Vector2 v(2.0, 3.0);
		Vector2 result = v * 2.0;
		EXPECT_DOUBLE_EQ(4.0, result.getX());
		EXPECT_DOUBLE_EQ(6.0, result.getY());
		result = 2.0 * v;
		EXPECT_DOUBLE_EQ(4.0, result.getX());
		EXPECT_DOUBLE_EQ(6.0, result.getY());
	}
	END

	TEST(Vector2Test, Division) {
		Vector2 v(2.0, 3.0);
		Vector2 result = v / 2.0;
		EXPECT_DOUBLE_EQ(1.0, result.getX());
		EXPECT_DOUBLE_EQ(1.5, result.getY());
	}
	END

	TEST(Vector2Test, Print) {
		Vector2 v(2.0, 3.5);
		std::stringstream ss;
		ss << v;
		EXPECT_STREQ("Vector2(2, 3.5)", ss.str().c_str());
	}
	END

	TEST(Vector2Test, Rotation) {
		Vector2 v(1.0, 0.0);
		Vector2 result = v.rotate(90.0);
		EXPECT_DOUBLE_EQ(0.0, result.getX());
		EXPECT_DOUBLE_EQ(1.0, result.getY());
	}
	END

	TEST(LeaderBoardTest, LeaderBoardItem) {
		LeaderBoardItem item;
		item.score = 0;
		std::stringstream sIn("Alice 12300");
		sIn >> item;
		EXPECT_STREQ("Alice", item.name);
		EXPECT_EQ(12300, item.score);

		std::stringstream sOut;
		sOut << item;
		EXPECT_STREQ("Alice 12300", sOut.str().c_str());
	}
	END

	TEST(LeaderBoardTest, LeaderBoard) {
		LeaderBoard lb;
		LeaderBoardItem* item = new LeaderBoardItem();
		strcpy(item->name, "Bob");
		item->score = 23400;

		std::stringstream sIn("Alice 12300");
		lb.loadScores(sIn);
		lb.addScore(item);
		std::stringstream sOut;
		lb.saveScores(sOut);

		EXPECT_STREQ("Bob 23400\nAlice 12300\n", sOut.str().c_str());
	}
	END

	TEST(LevelTest, all) {
		Game* game = new Game();
		Level* level1 = new OrderedLevel();
		Level* level2 = new RandomLevel();
		Level* level3 = new DescendingLevel();

		EXPECT_EQ(50, (*level1)(game));
		EXPECT_EQ(1, level1->getDifficulty());
		level1->increaseDifficulty();
		EXPECT_EQ(2, level1->getDifficulty());

		EXPECT_GT(8, (*level2)(game));
		EXPECT_EQ(10, (*level3)(game));

		delete game;
		delete level1;
		delete level2;
		delete level3;
	}
	END

	TEST(Game, update) {
		Game* game = new Game();
		SceneManager::getInstance().setCurrentScene(game);
		game->update();
	}
	END

	TEST(Start, update) {
		Start* start = new Start();
		SceneManager::getInstance().setCurrentScene(start);
		start->update();
	}
	END

	TEST(GameOver, update) {
		GameOver* gameOver = new GameOver(1000);
		SceneManager::getInstance().setCurrentScene(gameOver);
		gameOver->update();
	}
	END

	TEST(Gun, all) {
		Game* game = new Game();
		SceneManager::getInstance().setCurrentScene(game);
		Gun gun;
		gun.shoot(Vector2(0, 0));
		gun.upgrade();
		gun.shoot(Vector2(0, 0));
		gun.upgrade();
		gun.upgrade();
		gun.shoot(Vector2(0, 0));
		gun.reset();
	}
	END

	TEST(SceneManager, update) {
		SceneManager::getInstance().update();
	}
	END
}
#endif