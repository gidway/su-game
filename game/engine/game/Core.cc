#include "Core.hh"

#include <atomic>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "sdl/Window.hh"

#include "State.hh"

using namespace ::gidway::engine;

namespace gidway {
namespace game {

Core::Core (const int argc, char ** argv) {
	name("gidway games");

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		//Log("Unable to Init SDL: %s", SDL_GetError());
		throw "Unable to init SDL";
	}
	if (TTF_Init() < 0) {
		throw "Unable to init SDL_ttf";
	}
	if (not SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		//Log("Unable to Init hinting: %s", SDL_GetError());
		throw "Unable to init hinting SDL";
	}
	if ((window = sdl::Window(SDL_CreateWindow("My SDL Core",
	                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	                          window_width, window_height,
	                          SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL
	))) == nullptr) {
		//Log("Unable to create SDL Window: %s", SDL_GetError());
		throw "Unable to create SDL Window";
	}

	primarySurface = sdl::Surface(SDL_GetWindowSurface(window));

	if ((renderer = sdl::Renderer(SDL_CreateRenderer(window, -1,
	     SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE
	))) == nullptr)
	{
		//Log("Unable to create renderer");
		throw "Unable to create renderer";
	}

    /*
	{
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
		SDL_RenderClear(renderer);
		SDL_Rect rect {0, 0, window_width, window_height};
		SDL_RenderDrawRect(renderer, &rect);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
	}

	game._base_path = SDL_GetBasePath();

	loadFont(666, "ARIAL.TTF");

	banner();
    */
}

Core::~Core (void) {
	renderer.reset(nullptr);
	window.reset(nullptr);
    /*
	if (renderer) {
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
	}
	if (window) {
		SDL_DestroyWindow(window);
		window = nullptr;
	}
    */
    /*
	SDL_free(game._base_path); game._base_path = nullptr;
    */

	TTF_Quit();
	SDL_Quit();
}

void Core::banner (void) const {
    /*
	SDL_ShowWindow(window);
	SDL_RaiseWindow(window);

	if (not game.fonts.collection.empty()) {
		auto Sans = defaultFont();
		SDL_Color White = {0xff, 0xff, 0xff};
		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, game.name.c_str(), White);
		SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
		SDL_Rect Message_rect;
		{
			Message_rect.x = 0;
			Message_rect.y = (window_height / 2) - 50;
			Message_rect.w = window_width;
			Message_rect.h = (window_height / 2);
		}
		SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
		SDL_RenderPresent(renderer);
	}
	else {
		SDL_Log("TTF_OpenFonti - No fonts...");
	}
    */
}

int Core::operator () (GameMainFunction _game_main, GameEventFunction _game_event) {
    return 0;/*
	return loop(_game_main, _game_event);
    */
}

int Core::loop (GameMainFunction _game_main, GameEventFunction _game_event) {
	SDL_Event e;
	int result = 0;
    /*
	_working = true;
	while (_working) {
		(result = _game_main()) == 0 ? 0 : (_working = false, 0);
		while (SDL_PollEvent(&e)) {
			_game_event(e);
			((SDL_QUIT == e.type) ? (quit(), 0) : 0);
		}
		SDL_Delay(100); // for saving CPU
		render();
	}
    */
	return result;
}

void Core::render (void) {
    /*
	SDL_RenderPresent(renderer);
    */
}

void Core::addState (const GameStateId _state_id, GameState _state) {
    /*
	game.states.collection[_state_id] = _state;
    */
}

void Core::loadFont (const FontId _font_id, const std::string & _path) {
    /*
	const auto & _path_main_font = game._base_path + std::string("data/fonts/") + _path;
	if (TTF_Font * _loaded_font = TTF_OpenFont(_path_main_font.c_str(), 500)) {
		game.fonts.collection.emplace(_font_id, FontSurface(_loaded_font, ::TTF_CloseFont));
	}
	else {
		SDL_Log("TTF_OpenFont: [fontId=%d] [%s] %s", _font_id, _path_main_font.c_str(), SDL_GetError());
		throw "Can't load font - no alternative....";
	}
    */
}

TTF_Font * Core::font (const FontId _font_id) const {
    return nullptr;/*
	return game.fonts.collection.at(_font_id).get();
    */
}

void Core::name (const std::string & _) {
    /*
	game.name = _;
    */
}

} // namespace game
} // namespace gidway
