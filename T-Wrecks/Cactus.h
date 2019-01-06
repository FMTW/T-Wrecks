#pragma once
#include "GameObject.h"
class Cactus :
	public GameObject
{
public:
	Cactus(int, int, int);
	~Cactus();

	virtual void update(float);
	virtual void draw(bool);

private:
	SDL_Texture *CactusTexture;
	SDL_Rect CactusRect;

	int w, h;
};