#include "Workspace.hh"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "exceptions/Workspace.hh"

namespace gidway {
namespace engine {
namespace sdl {

	namespace helpers {
		SDL_Init_Wrapper::SDL_Init_Wrapper (void) {
			if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
				throw exceptions::Workspace("Unable to init SDL");
			}
		}
		SDL_Init_Wrapper::~SDL_Init_Wrapper (void) {
				SDL_Quit();
		}
		SDL_TTF_Wrapper::SDL_TTF_Wrapper (void){
			if (TTF_Init() < 0) {
				throw exceptions::Workspace("Unable to init SDL_ttf");
			}
		}
		SDL_TTF_Wrapper::~SDL_TTF_Wrapper (void) {
				TTF_Quit();
		}
	 } // namespace helpers

Workspace::Workspace (void) {
	if (not SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		//Log("Unable to Init hinting: %s", SDL_GetError());
		throw exceptions::Workspace("Unable to init hinting SDL");
	}
}

Workspace::~Workspace (void) {
	/* TODO FIXME
	 * valgrind announce some issue with destroying this object
	 * REASON: Workspace - included directly to c-tor and d-tor don't generate any errors
	 */
}

} // namespace sdl
} // namespace engine
} // namespace gidway
