#include "levels.h"
#include "chickens.h"
#include "game.h"
#include "m_random.h"
#include "vector2.h"

Level::Level()
    : _difficulty(1) {}

int Level::getDifficulty() const {
	return _difficulty;
}

void Level::increaseDifficulty() {
	_difficulty++;
}

int OrderedLevel::operator()(Game* game) {
	for (size_t y = 0; y < 5; y++) {
		for (size_t x = 0; x < 10; x++) {
			game->addEntity(
			    new OrderedChicken(
			        Vector2(x * 32 + 16, y * 25 + 50),
			        getDifficulty()
			    )
			);
		}
	}
	return 5 * 10;
}

int RandomLevel::operator()(Game* game) {
	int count = 0;
	for (int i = 0; i < getDifficulty() * 8; i++) {
		if (Random::randBool(0.5)) {
			count++;
			game->addEntity(
			    new RandomChicken(
			        Vector2(
			            Random::randInt(10, 310),
			            40 + Random::randInt(0, 15)
			        ),
			        getDifficulty()
			    )
			);
		}
	}
	return count;
}

// TODO: Make it properly
int DescendingLevel::operator()(Game* game) {
	for (int y = 0; y < getDifficulty(); y++) {
		for (size_t x = 0; x < 10; x++) {
			game->addEntity(
			    new DescendingChicken(
			        Vector2(x * 32 + 16, y * 25 + 50),
			        getDifficulty()
			    )
			);
		}
	}
	return getDifficulty() * 10;
}