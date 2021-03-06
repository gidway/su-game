#pragma once

#include "game/State.hh"

namespace gidway {
namespace product {
namespace su {
namespace states {

class Intro : public ::gidway::game::State
{
public:
	using State::State;

	void show (void) override { State::show(); }
	void hide (void) override { State::hide(); }

	void redraw (void) nonconst override {
		// empty
	}
}; // class Intro

} // namespace states
} // namespace su
} // namespace product
} // namespace gidway
