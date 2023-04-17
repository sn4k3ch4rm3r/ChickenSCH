#include "game.h"

int main(int argc, char* argv[]) {

	Game game = Game("Los Pollos HermanoSCH", 320, 180);
	game.gameLoop();

	SDL_Quit();

	return 0;
}
