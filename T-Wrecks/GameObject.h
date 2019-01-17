#pragma once
#include <SDL.h>

#include "Globals.h"
#include "Vector.h"

class GameObject {
protected:
	SDL_Renderer * renderer = Globals::renderer;

public:
	Vector pos;  // Position
	Vector vel;  // Velocity
	int frameWidth, frameHeight;

	void setRenderer(SDL_Renderer*);

	virtual void update(float);
	virtual void updateMovement(float);
	virtual void draw(bool);
	virtual bool checkIfHover(Vector);

};