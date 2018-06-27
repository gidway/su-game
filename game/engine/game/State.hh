#pragma once
#define nonconst // just like that, only to mark intentional
namespace gidway {
namespace game {
	class Core;

class State {
public:
	virtual ~State (void);
	State (void);

	virtual void show (void) = 0;
	virtual void hide (void) = 0;

	void focus (bool _) { _focused = _; }

	bool hidden (void) const { return (false == _showed); }
	bool showed (void) const { return _showed; }
	bool focused (void) const { return _focused; }

	virtual void redraw (void) nonconst = 0;

private:

	bool _focused {false};
	bool _showed  {false};

}; // class State

} // namespace game
} // namespace gidway
