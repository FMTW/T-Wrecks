#include "Ground.h"

Ground::Ground(bool state) {
	groundTexture = IMG_LoadTexture(Globals::renderer, "Assets/ground.png");
	SDL_QueryTexture(groundTexture, NULL, NULL, &w, &h);

	vel.x = -500;

	pos.x = 0;
	pos.y = 670;
	groundRect.w = w;
	groundRect.h = h;

	inGame = state;
}

Ground::~Ground() {
	SDL_DestroyTexture(groundTexture);
}

// update stuffs
void Ground::update(float dt) {
	if (inGame)
		updateMovement(dt);

	checkBoundry();
	//checkPosition();

	groundRect.x = pos.x;
	groundRect.y = pos.y;
}

// draw stuffs
void Ground::draw(bool) {
	SDL_RenderCopy(Globals::renderer, groundTexture, NULL, &groundRect);
}

// Reset ground position to create a loop
void Ground::checkBoundry() {
	if (pos.x <= (-w / 1.5))
		pos.x = 0;
}

// Just for debugging
void Ground::checkPosition() {
	cout << "  Ground Position(" << pos.x << ", " << pos.y << ")\n"
		<< "  Ground Rect Position(" << groundRect.x << ", " << groundRect.y << ")\n";
}