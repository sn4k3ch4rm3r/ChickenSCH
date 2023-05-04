#include <SDL.h>
#include "game.h"

int main(int argc, char* argv[]) {

	//Initialize game
	Game* game = new Game();
	//Run game
	game->gameLoop();
	//Clean up after the game has ended
	delete game;

	return 0;
}
