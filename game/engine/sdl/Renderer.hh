#pragma once

#include <memory>

#include <SDL2/SDL.h>

namespace gidway {
namespace engine {
namespace sdl {
	struct Renderer;

struct SDL_Renderer_Deleter final {
	void operator()(SDL_Renderer* ptr) {
		SDL_DestroyRenderer(ptr);
	}
};

using UniqueRenderer = std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter>;

struct Renderer final : public UniqueRenderer
{
	using UniqueRenderer::unique_ptr;
	operator SDL_Renderer* (void) const {
		return get();
	}
};

} // namespace sdl
} // namespace engine
} // namespace gidway
