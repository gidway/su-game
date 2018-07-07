#pragma once

#include <memory>

#include <SDL2/SDL.h>

namespace gidway {
namespace engine {
namespace sdl {

using SharedWindowBase = std::shared_ptr<SDL_Window>;

struct SharedWindow : public SharedWindowBase
{
    using SharedWindowBase::shared_ptr;
    operator SDL_Windoiw* (void) const {
        return get();
    }
};

} // namespace sdl
} // namespace engine
} // namespace gidway
