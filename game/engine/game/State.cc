#include "State.hh"

#include "Core.hh"

namespace gidway {
namespace game {

State::~State (void) {}

State::State (void) {}

void State::show (void) {
	_showed = true;
}

void State::hide (void) {
	_showed = false;
}

} // namespace game
} // namespace gidway
