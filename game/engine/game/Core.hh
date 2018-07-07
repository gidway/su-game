#pragma once

#include <atomic>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "sdl/Workspace.hh"
#include "sdl/Window.hh"
#include "sdl/Renderer.hh"
#include "sdl/Surface.hh"

struct SDL_Renderer;
struct SDL_Surface;
union  SDL_Event;
struct _TTF_Font;

namespace gidway {
namespace game {
	class State;

class Core final {
public:
	using FontId = int;
	using FontSurface = std::shared_ptr<_TTF_Font>;
	using FontsCollection = std::unordered_map<FontId, FontSurface>;
	//
	using GameStateId = int;
	using GameState = std::shared_ptr<State>;
	using GameStates = std::unordered_map<GameStateId, GameState>;
	//
	using GameMainFunction = std::function<int(void)>;
	using GameEventFunction = std::function<void(SDL_Event &)>;
	//

	Core(const int argc, char ** argv);

	~Core (void);

	int operator () (GameMainFunction, GameEventFunction);

	void quit (void) { _working = false; }

	// --- SETTERS ---

	/**
	 */
	void name (const std::string &);

	void addState (const GameStateId _state_id, GameState _state);

	template <typename T>
	void addState (const T _state_id, GameState _state) {
		/*
		return addState(static_cast<GameStateId>(_state_id), _state);
		*/
	}

	// --- LOADERS ---

	/**
	 * Load font to fonts collection inside the Core
	 */
	void loadFont (const FontId _font_id, const std::string & _path);

	template <typename TID>
	void loadFont (const TID _font_id, const std::string & _path) {
		/*
		return loadFont(static_cast<FontId>(_font_id), _path);
		*/
	}

	// --- GETTERS ---

	/**
	 * This function has no any guards for collection contracts
	 */
	TTF_Font * defaultFont (void) const {
		return nullptr;/*
		return (*(game.fonts.collection.begin())).second.get();
		*/
	}

	TTF_Font * font (const FontId _font_id) const;

	template <typename T>
	TTF_Font * font (const T _font_id) const {
		return nullptr;/*
		return font(static_cast<FontId>(_font_id));
		*/
	}

protected:

	/**
	 * Take interaction with main function, grab events etc.
	 */
	int loop (GameMainFunction, GameEventFunction);

	/**
	 * Render current state
	 */
	void render (void);

	void banner (void) const;

private:
	static constexpr int window_width = 800;
	static constexpr int window_height = 600;

	bool _working {false};

	engine::sdl::Workspace      workspace;
	engine::sdl::Window         window;
	engine::sdl::Renderer      renderer;
	engine::sdl::WindowSurface primarySurface;

	struct _game {
		char * _base_path;
		std::string name;

		struct _fonts {
			FontsCollection collection;
		} fonts;

		struct _states {
			GameStates collection;
		} states;
	} game;
}; // class Core

} // namespace game
} // namespace gidway
