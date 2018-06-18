#pragma once

#include <string>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;

namespace gidway {
namespace game {

class Core final {
public:

	Core(const int argc, char ** argv, char ** env);

	~Core (void);

	int operator () (void);

	// --- getters
	void name (const std::string &);

private:
	static constexpr int windowWidth = 1024;
	static constexpr int windowHeight = 768;

	SDL_Window   * window {nullptr};
	SDL_Renderer * renderer {nullptr};
	SDL_Surface  * primarySurface {nullptr};

	struct _game {
		std::string name;
	} game;
}; // class Core

} // namespace game
} // namespace gidway
