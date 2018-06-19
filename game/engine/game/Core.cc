#include "Core.hh"

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace gidway {
namespace game {

Core::Core (const int argc, char ** argv, char ** env) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		//Log("Unable to Init SDL: %s", SDL_GetError());
		throw "Unable to init SDL";
	}
	if (not SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		//Log("Unable to Init hinting: %s", SDL_GetError());
		throw "Unable to init hinting SDL";
	}
	if ((window = SDL_CreateWindow("My SDL Core",
		                           SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		                           windowWidth, windowHeight,
		                           SDL_WINDOW_SHOWN //| SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL
		)) == NULL)
	{
		//Log("Unable to create SDL Window: %s", SDL_GetError());
		throw "Unable to create SDL Window";
	}
	primarySurface = SDL_GetWindowSurface(window);
	//if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE)) == NULL) {
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
	SDL_ShowWindow(window);
	SDL_RaiseWindow(window);
	{
		TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
		SDL_Color White = {255, 255, 255};
		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, game.name.c_str(), White);
		SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
		SDL_Rect Message_rect;
		{
			Message_rect.x = 100;
			Message_rect.y = 100;
			Message_rect.w = 200;
			Message_rect.h = 200;
		}
		SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
	}
	{
		SDL_BlitSurface(primarySurface, 0, SDL_GetWindowSurface(window), 0);
		//SDL_UpdateWindowSurface(window); //<< wyjebka
	}
	return loop();
}

int Core::loop (void) {
	SDL_Event e;
	bool quit = false;
	SDL_Log("Test\n");
	while (not quit) {
		while (SDL_PollEvent(&e)) {
			quit = ((SDL_QUIT == e.type) or (SDL_KEYDOWN == e.type) or (SDL_MOUSEBUTTONDOWN == e.type));
			SDL_Delay(16); // for saving CPU
		}
	}
	return 0;
}

void Core::name (const std::string & _) {
	game.name = _;
}

} // namespace game
} // namespace gidway
