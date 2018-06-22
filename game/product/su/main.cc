// Copyright (C) 2018 Gidway // wwwgidway.net

#include "game/Core.hh"

#include "states/Intro.hh"
#include "states/Begin.hh"

enum class GameFont {
	Intro,
};

enum class gameState {
	Intro,
	Begin,
	Pause,
	Play,
	Close,
	End,
	Quit,
};

int main (int argc, char ** argv) {
	using namespace ::gidway::product::su::states;

	gidway::game::Core game(argc, argv);

	game.name("children of the revolution");

	game.loadFont(GameFont::Intro, "children-of-the-revolution/Children of the revolution.ttf");

	game.addState(gameState::Intro, std::make_shared<Intro>());
	game.addState(gameState::Begin, std::make_shared<Begin>());
	//game.addState(gameState::Pause, std::make_shared<Pause>());
	//game.addState(gameState::Play, std::make_shared<Play>());
	//game.addState(gameState::Close, std::make_shared<Close>());
	//game.addState(gameState::End, std::make_shared<End>());
	//game.addState(gameState::Quit, std::make_shared<Quit>());

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
