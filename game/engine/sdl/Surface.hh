#pragma once

#include <memory>

#include <SDL2/SDL.h>

namespace gidway {
namespace engine {
namespace sdl {
	struct Surface;

struct SDL_Surface_Deleter {
	void operator()(SDL_Surface* ptr) {
		SDL_FreeSurface(ptr);
	}
};

using UniqueSurface = std::unique_ptr<SDL_Surface, SDL_Surface_Deleter>;

struct Surface final : public UniqueSurface
{
	using UniqueSurface::unique_ptr;

	operator SDL_Surface* (void) const {
		return get();
	}
};

class WindowSurface final
{
	SDL_Surface* _ptr {nullptr};
public:
	operator SDL_Surface* (void) const {
		return _ptr;;
	}

	WindowSurface (void) {}

	WindowSurface (const WindowSurface& ws) : _ptr(ws._ptr) {}

	WindowSurface (SDL_Surface* _) : _ptr(_) {}

	~WindowSurface (void) {
		_ptr = nullptr; // XXX don't delete handled pointer!
	}

	WindowSurface& operator = (SDL_Surface* _) {
		_ptr = _;
		return *this;
	}

	WindowSurface& operator = (const WindowSurface& ws) {
		_ptr = ws._ptr;
		return *this;
	}
};

} // namespace sdl
} // namespace engine
} // namespace gidway
