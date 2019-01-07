#pragma once
#include "GameObject.h"
#include <time.h>
#include <stdlib.h>

class Cactus :
	public GameObject
{
public:
	Cactus(int, int, int, bool);
	~Cactus();

	virtual void update(float);
	virtual void draw(bool);
	void loadCactusTexture(int);
	void checkBoundry();
	void checkPosition();

private:
	SDL_Texture *cactusTexture;
	SDL_Rect cactusRect;

	bool inGame;
	int w, h, randNum;
};