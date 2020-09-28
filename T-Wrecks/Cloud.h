#pragma once
#include "GameObject.h"

class Cloud :
	public GameObject
{
public:
	Cloud(float);
	~Cloud();

	virtual void update(float);
	virtual void draw(bool);

	void loadTexture();
	void checkBoundry();
	void checkPosition();

private:
	int randNum, frameWidth, frameHeight;
	SDL_Texture *cloudTexture;
	SDL_Rect cloudRect;

};

