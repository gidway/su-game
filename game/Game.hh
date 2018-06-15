#pragma once

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;

namespace gidway {
class Game final {
public:

	Game(const int argc, char ** argv, char ** env);

	~Game (void);

	int operator () (void);

private:
	static constexpr int windowWidth = 1024;
	static constexpr int windowHeight = 768;

	SDL_Window   * window {nullptr};
	SDL_Renderer * renderer {nullptr};
	SDL_Surface  * primarySurface {nullptr};
}; // class Game
} // namespace gidway
