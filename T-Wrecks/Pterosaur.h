#pragma once
#include "GameObject.h"
#include "Animation.h"

class Pterosaur :
	public GameObject
{
public:
	Pterosaur();
	~Pterosaur();

	virtual void update(float);
	virtual void draw(bool);

	void setupSprite();
	void checkBoundry();
	void checkPosition();

private:
	Animation *animation;
	SDL_Texture *pterosaurTexture;

	

};

