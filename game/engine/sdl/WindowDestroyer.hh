#pragma once

#include <memory>

struct SDL_Window;
void SDL_DestroyWindow(SDL_Window*);

namespace gidway {
namespace engine {
namespace sdl {

struct SDL_Window_Deleter {
  void operator()(SDL_Window* ptr) {
      SDL_DestroyWindow(ptr);
  }
};


} // namespace sdl
} // namespace engine
} // namespace gidway
