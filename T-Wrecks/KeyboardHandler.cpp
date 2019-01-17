#include "KeyboardHandler.h"

KeyboardHandler::KeyboardHandler(bool state) { 
	inGame = state; 
	playerJumpVel = 1200;
	playerRunVel = 700;
}
KeyboardHandler::~KeyboardHandler() { }

void KeyboardHandler::update(SDL_Event *e) {
	// Set player velocity to 0 when key is released
	p->vel.x = 0;

	if (inGame)
		runGameControl(e);
	else
		runMenuControl(e);
	
}

// Run this set of control when in menu
void KeyboardHandler::runMenuControl(SDL_Event *e) {
	if ((keyState[SDL_SCANCODE_UP] && e->key.repeat == 0) || (keyState[SDL_SCANCODE_W] && e->key.repeat == 0))
		p->vel.y = -playerJumpVel;
	if ((keyState[SDL_SCANCODE_LEFT]) || (keyState[SDL_SCANCODE_A])) 
		p->vel.x = -playerRunVel;
	if ((keyState[SDL_SCANCODE_RIGHT]) || (keyState[SDL_SCANCODE_D]))
		p->vel.x = playerRunVel;
}

// Run this set of control when in game
void KeyboardHandler::runGameControl(SDL_Event *e) {
	if ((keyState[SDL_SCANCODE_UP] && e->key.repeat == 0) || (keyState[SDL_SCANCODE_W] && e->key.repeat == 0))
		p->vel.y = -playerJumpVel;
}