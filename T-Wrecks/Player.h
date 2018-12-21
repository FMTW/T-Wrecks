#pragma once

#include <SDL_image.h>

#include "GameObject.h"
#include "Globals.h"
#include "Animation.h"

class Player : public GameObject {
public:
	Player(int, int);
	~Player();
	
	virtual void update(float);
	virtual void draw(bool);
	
private:
	SDL_Surface *animatedSurface;
	SDL_Texture *playerTexture;
	Animation *idle = NULL;
	Animation *run = NULL;
	bool isFlipped = true;
	bool isActive = false;
	bool isGround = true;

	int gravity = 2000;
	int frameWidth = 128;
	int frameHeight = 143;

	void setAnimation(int);
	void isFlip();
	void initialGravity(int);
	void checkPlayerBoundry();
};

