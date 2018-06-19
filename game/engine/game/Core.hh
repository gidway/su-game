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

protected:
	int loop (void);

private:
	static constexpr int windowWidth = 800;
	static constexpr int windowHeight = 600;

	SDL_Window   * window {nullptr};
	SDL_Renderer * renderer {nullptr};
	SDL_Surface  * primarySurface {nullptr};

	struct _game {
		std::string name;
	} game;
}; // class Core

} // namespace game
} // namespace gidway
