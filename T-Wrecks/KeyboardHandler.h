#pragma once
#include "InputHandler.h"
#include "Player.h"
class KeyboardHandler :	public InputHandler {
public:
	Player *p;

	KeyboardHandler(bool);
	~KeyboardHandler();

	void update(SDL_Event*);

	void runMenuControl(SDL_Event*);
	void runGameControl(SDL_Event*);

private:
	// Switch Keyboard Mode between Menu and Ingame, 0 = Menu, 1 = InGame;
	bool inGame;
	int playerJumpVel, playerRunVel, jumpCount;
	const Uint8 *keyState = SDL_GetKeyboardState(NULL);
};

