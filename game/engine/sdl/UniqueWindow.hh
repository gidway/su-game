#pragma once

#include <memory>

#include <SDL2/SDL.h>

#include "WindowDestroyer.hh"

namespace gidway {
namespace engine {
namespace sdl {

using UniqueWindow = std::unique_ptr<SDL_Window, SDL_Window_Deleter>;

} // namespace sdl
} // namespace engine
} // namespace gidway
