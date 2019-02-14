#include "Cactus.h"


Cactus::Cactus(bool state, float velMultiplier) {
	if (state)
		randX = rand() % 1280 + 1281;
	else
		randX = rand() % 780 + 500;

	randY = rand() % 20 + 700;
	loadCactusTexture();
	
	vel.x = -500;
	this->velMultiplier = velMultiplier;
	inGame = state;
}

Cactus::~Cactus() {
	SDL_DestroyTexture(cactusTexture);
}

void Cactus::update(float dt) {
	if (inGame) {
		vel.x -= velMultiplier * dt;
		updateMovement(dt);
	}
	checkBoundry();

	cactusRect.x = pos.x;
	cactusRect.y = pos.y;
}

void Cactus::draw(bool) {
	SDL_RenderCopy(Globals::renderer, cactusTexture, NULL, &cactusRect);
}

// Take a int then choose which cactus to use;
void Cactus::loadCactusTexture() {
	switch (rand() % 4 + 1) {
	case 1:
		cactusTexture = IMG_LoadTexture(Globals::renderer, "Assets/Cactus_Small.png");
		break;
	case 2:
		cactusTexture = IMG_LoadTexture(Globals::renderer, "Assets/Cactus_Small_Row.png");
		break;
	case 3:
		cactusTexture = IMG_LoadTexture(Globals::renderer, "Assets/Cactus_Big.png");
		break;
	case 4:
		cactusTexture = IMG_LoadTexture(Globals::renderer, "Assets/Cactus_Big_Row.png");
		break;
	}
	SDL_QueryTexture(cactusTexture, NULL, NULL, &frameWidth, &frameHeight);
	pos.x = randX;
	pos.y = (rand() % 10 + 700) - frameHeight;
	cactusRect.w = frameWidth;
	cactusRect.h = frameHeight;
}


// Reset cactus position to create a loop
void Cactus::checkBoundry() {
	if (pos.x <= -frameWidth*2) {
		pos.x = rand() % 1280 + 1281;
		loadCactusTexture();
	}
}

// Just for debugging
void Cactus::checkPosition() {
	cout << "  Cactus Position(" << pos.x << ", " << pos.y << ")\n"
		<< "  Cactus Rect Position(" << cactusRect.x << ", " << cactusRect.y << ")\n";
}