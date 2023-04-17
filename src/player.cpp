#include <SDL.h>
#include <iostream>

#include "game.h"
#include "player.h"

void Player::render() {
	SDL_FRect rect = {
	    (float)position.getX(),
	    (float)position.getY(),
	    16, 16};
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	SDL_RenderFillRectF(Game::renderer, &rect);
}

void Player::update() {
	Entity::update();
}