#pragma once
#include "InputHandler.h"
#include "Player.h"
class KeyboardHandler :	public InputHandler {
public:
	Player *p;

	KeyboardHandler();
	~KeyboardHandler();

	void update(SDL_Event*);
};

