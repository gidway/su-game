#include "Core.hh"

#include <string>

#include <SDL2/SDL.h>

namespace gidway {
namespace game {

Core::Core (const int argc, char ** argv, char ** env) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		//Log("Unable to Init SDL: %s", SDL_GetError());
		throw "Unable to init SDL";
	}
	if (not SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		//Log("Unable to Init hinting: %s", SDL_GetError());
		throw "Unable to init hinting SDL";
	}
	if ((window = SDL_CreateWindow("My SDL Core",
		                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		                           windowWidth, windowHeight, SDL_WINDOW_SHOWN))
		== NULL)
	{
		//Log("Unable to create SDL Window: %s", SDL_GetError());
		throw "Unable to create SDL Window";
	}
	primarySurface = SDL_GetWindowSurface(window);
	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
		//Log("Unable to create renderer");
		throw "Unable to create renderer";
	}
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

Core::~Core (void) {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
	}
	if (window) {
		SDL_DestroyWindow(window);
		window = nullptr;
	}
	SDL_Quit();
}

int Core::operator () (void) {
	return 0;
}

void Core::name (const std::string & _) {
	game.name = _;
}

} // namespace game
} // namespace gidway
