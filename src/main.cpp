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
#include "vector2.h"
#include "gtest_lite.h"
#include "memtrace.h"

int main() {
	// Vector2 Tests

	TEST(Vector2Test, Constructor) {
		Vector2 v(2.0, 3.0);
		EXPECT_DOUBLE_EQ(2.0, v.getX());
		EXPECT_DOUBLE_EQ(3.0, v.getY());
	}
	END

	TEST(Vector2Test, Addition) {
		Vector2 v1(2.0, 3.0);
		Vector2 v2(1.0, 2.0);
		Vector2 result = v1 + v2;
		EXPECT_DOUBLE_EQ(3.0, result.getX());
		EXPECT_DOUBLE_EQ(5.0, result.getY());
	}
	END

	TEST(Vector2Test, Subtraction) {
		Vector2 v1(2.0, 3.0);
		Vector2 v2(1.0, 2.0);
		Vector2 result = v1 - v2;
		EXPECT_DOUBLE_EQ(1.0, result.getX());
		EXPECT_DOUBLE_EQ(1.0, result.getY());
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
}

#endif