#include "Cactus.h"


Cactus::Cactus(int num, int x, int y, bool state) {
	srand(time(0));
	randNum = rand() % 4 + 1;
	cout << "  This is cactus number " << randNum << endl;
	loadCactusTexture(randNum);
	SDL_QueryTexture(cactusTexture, NULL, NULL, &w, &h);
	
	vel.x = -500;

	pos.x = x;
	pos.y = y - h;
	cactusRect.w = w;
	cactusRect.h = h;

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
}


// Reset ground position to create a loop
void Cactus::checkBoundry() {
	if (pos.x <= -w)
		pos.x = rand() % 1280 + 1281;
}

// Just for debugging
void Cactus::checkPosition() {
	cout << "  Cactus Position(" << pos.x << ", " << pos.y << ")\n"
		<< "  Cactus Rect Position(" << cactusRect.x << ", " << cactusRect.y << ")\n";
}