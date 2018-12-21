#include "MouseHandler.h"
#include <iostream>

MouseHandler::MouseHandler() {}
MouseHandler::~MouseHandler() {}

void MouseHandler::update(SDL_Event *e) {}

// Return a vector of mouse coordinate
Vector MouseHandler::getMouseState() {
	SDL_GetMouseState(&MouseCoordinate.x, &MouseCoordinate.y);

	return MouseCoordinate;
}