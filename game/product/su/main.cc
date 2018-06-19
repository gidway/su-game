// Copyright (C) 2018 Gidway // wwwgidway.net

#include "game/Core.hh"

int main (int argc, char ** argv, char ** env) {
	gidway::game::Core game(argc, argv, env);

	game
		.name("su.11")
		//.layer(gidway::game::Intro());
		;

	return game();
}
