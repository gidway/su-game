#include "Workspace.hh"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace gidway {
namespace engine {
namespace sdl {

Workspace::Workspace (void) {
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
}

Workspace::~Workspace (void) {
	TTF_Quit();
	SDL_Quit();
}

} // namespace gidway
} // namespace engine
} // namespace sdl
