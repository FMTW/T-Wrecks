#pragma once
#include "InputHandler.h"
#include "Vector.h"

class MouseHandler :
	public InputHandler
{
public:
	MouseHandler();
	~MouseHandler();

	void update(SDL_Event*);
	Vector getMouseState();

private:
	Vector MouseCoordinate;
};

