#include "Cactus.h"


Cactus::Cactus(bool state) {
	randNum = rand() % 4 + 1;

	if (state)
		randX = rand() % 1280 + 1281;
	else
		randX = rand() % 780 + 500;
	randY = rand() % 20 + 700;
	loadCactusTexture(randNum);
	
	vel.x = -500;
	inGame = state;
}

Cactus::~Cactus() {
	SDL_DestroyTexture(cactusTexture);
}

void Cactus::update(float dt) {
	if (inGame)
		updateMovement(dt);

	checkBoundry();
	//checkPosition();

	cactusRect.x = pos.x;
	cactusRect.y = pos.y;
}

void Cactus::draw(bool) {
	//SDL_SetRenderDrawColor(Globals::renderer, 100, 100, 100, 100);
	//SDL_RenderFillRect(Globals::renderer, &cactusRect);
	SDL_RenderCopy(Globals::renderer, cactusTexture, NULL, &cactusRect);
}

// Take a int then choose which cactus to use;
void Cactus::loadCactusTexture(int num) {
	switch (num) {
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
	pos.y = randY - frameHeight;
	cactusRect.w = frameWidth;
	cactusRect.h = frameHeight;
}


// Reset cactus position to create a loop
void Cactus::checkBoundry() {
	if (pos.x <= -frameWidth*2) {
		pos.x = rand() % 1280 + 1281;
		randNum = rand() % 4 + 1;
		loadCactusTexture(randNum);
	}
}

// Just for debugging
void Cactus::checkPosition() {
	cout << "  Cactus Position(" << pos.x << ", " << pos.y << ")\n"
		<< "  Cactus Rect Position(" << cactusRect.x << ", " << cactusRect.y << ")\n";
}