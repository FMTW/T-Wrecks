#pragma once

#include <SDL_image.h>

#include "GameObject.h"
#include "Globals.h"
#include "Animation.h"

class Player : public GameObject {
public:
	Player(int, int, bool);
	~Player();
	
	virtual void update(float);
	virtual void draw(bool);
	
private:
	SDL_Texture *idleTexture, *runTexture;
	Animation *idle = NULL;
	Animation *run = NULL;
	bool faceLeft = false;
	bool inGame = false;
	bool isGround = true;

	int gravity = 5000;
	int frameWidth = 128;
	int frameHeight = 143;

	void setAnimation(int);
	void isFlip();
	void initialGravity(int);
	void checkPlayerBoundry();
};

