#pragma once

namespace gidway {
namespace engine {
namespace sdl {

	namespace helpers {
		struct SDL_Init_Wrapper final {
			SDL_Init_Wrapper (void);
			~SDL_Init_Wrapper (void);
		};
		struct SDL_TTF_Wrapper final {
			SDL_TTF_Wrapper (void);
			~SDL_TTF_Wrapper (void);
		};
	} // namespace helpers

class Workspace final {
	helpers::SDL_Init_Wrapper _sdlInit;
	helpers::SDL_TTF_Wrapper  _ttfIInit;
public:
	Workspace (void);
	~Workspace (void);
};

} // namespace sdl
} // namespace engine
} // namespace gidway
