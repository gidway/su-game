#pragma once

#include <memory>

#include <SDL2/SDL.h>

#include "UniqueWindow.hh"

namespace gidway {
namespace engine {
namespace sdl {

struct Window
    : public UniqueWindow
{
    using UniqueWindow::unique_ptr;
    operator SDL_Window* (void) const {
        return get();
    }
};

} // namespace sdl
} // namespace engine
} // namespace gidway
