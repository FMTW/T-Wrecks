#include "Ground.h"

Ground::Ground(bool state) {
	groundTexture = IMG_LoadTexture(Globals::renderer, "Assets/ground.png");
	SDL_QueryTexture(groundTexture, NULL, NULL, &w, &h);

	groundRect.x = 0;
	groundRect.y = 670;
	groundRect.w = w;
	groundRect.h = h;

	inGame = state;
}

Ground::~Ground() {
	SDL_DestroyTexture(groundTexture);
}

void Ground::update(float) {
	if (inGame)
		groundRect.x -= groundVel;
	else
		groundRect.x = 0;
	
	checkBoundry();
}

void Ground::draw(bool) {
	SDL_RenderCopy(Globals::renderer, groundTexture, NULL, &groundRect);
}

void Ground::checkBoundry() {
	if (groundRect.x == (-w / 2))
		groundRect.x = 0;
}
