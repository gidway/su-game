// Copyright (C) 2018 Gidway // wwwgidway.net

#include "game/Core.hh"
#include "game/State.hh"

enum class GameFont {
	Intro,
};

enum class gameState {
	Intro,
};

int main (int argc, char ** argv) {
	gidway::game::Core game(argc, argv);

	game.name("children of the revolution");
	game.loadFont(GameFont::Intro, "children-of-the-revolution/Children of the revolution.ttf");
	game.addState(gameState::Intro, gidway::game::Core::GameState(new gidway::game::State()));

	return game(
		[& game](void) -> int { // GAME MAIN FUNCTION
			return 0;
		},
		[& game](SDL_Event & event) -> void { // GAME EVENT FUNCTION
			switch (event.type) {
				case SDL_KEYDOWN:
				case SDL_MOUSEBUTTONDOWN:
					game.quit();
					break;
			}
		}
	);
}
