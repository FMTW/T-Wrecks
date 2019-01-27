#pragma once
#include "GameObject.h"

class Cactus :
	public GameObject
{
public:
	Cactus(bool, float);
	~Cactus();

	virtual void update(float);
	virtual void draw(bool);
	void loadCactusTexture();
	void checkBoundry();
	void checkPosition();

private:
	SDL_Texture *cactusTexture;
	SDL_Rect cactusRect;

	bool inGame;
	int randX, randY;
};