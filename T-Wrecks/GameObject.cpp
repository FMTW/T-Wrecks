#include "GameObject.h"

void GameObject::setRenderer(SDL_Renderer* _renderer) {
	this->renderer = _renderer;
}

void GameObject::update(float dt) {
	//nuthin
}

void GameObject::updateMovement(float dt) {
	pos.x += (vel.x * dt);
	pos.y += (vel.y * dt);
}

void GameObject::draw(bool) {
	//nada
}

bool GameObject::checkIfHover(Vector _mousePos) {
	return 0;
}