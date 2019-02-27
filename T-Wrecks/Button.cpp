#include "Button.h"
#include <iostream>

Button::Button(int x, int y) {
	w = 320;
	h = 60;
	pos.x = x;
	pos.y = y;
}

Button::~Button() {}

void Button::draw(bool _ifHover) {
	SDL_Rect button = { pos.x, pos.y, w, h };

	if (_ifHover) {
		SDL_SetRenderDrawColor(renderer, 230, 230, 230, 100);
		SDL_RenderFillRect(renderer, &button);
	} else {
		SDL_SetRenderDrawColor(renderer, 244, 244, 244, 100);
		SDL_RenderFillRect(renderer, &button);
	}

}

// Check if the mouse is over the button
bool Button::checkIfHover(Vector _MousePos) {
	if (_MousePos.x > pos.x && _MousePos.x < (pos.x + w) && _MousePos.y > pos.y && _MousePos.y < (pos.y + h)) {
		return true;
	} else {
		return false;
	}
}