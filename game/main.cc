#include "Game.hh"
int main (int argc, char ** argv, char ** env) {
	gidway::Game game(argc, argv, env);
	return game();
}
