#include "levels.h"
#include "chickens.h"
#include "game.h"
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
			game->addEntity(new OrderedChicken(Vector2(x * 32 + 16, y * 25 + 50), getDifficulty()));
		}
	}
	return 5 * 10;
}