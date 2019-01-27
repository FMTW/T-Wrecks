#pragma once
#include "GameObject.h"
#

class Ground :
	public GameObject
{
public:
	Ground(bool, float);
	~Ground();

	virtual void update(float);
	virtual void draw(bool);

	void checkBoundry();
	void checkPosition();

private:
	SDL_Texture *groundTexture;
	SDL_Rect groundRect;

	bool inGame;
};

