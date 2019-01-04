#include "Cactus.h"


Cactus::Cactus(int num, int x, int y) {
	switch (num) {
	case 1:
		CactusTexture = IMG_LoadTexture(Globals::renderer, "Assets/Cactus_Small.png");
		break;
	case 2:
		CactusTexture = IMG_LoadTexture(Globals::renderer, "Assets/Cactus_Small_Row.png");
		break;
	case 3:
		CactusTexture = IMG_LoadTexture(Globals::renderer, "Assets/Cactus_Big.png");
		break;
	case 4:
		CactusTexture = IMG_LoadTexture(Globals::renderer, "Assets/Cactus_Big_Row.png");
		break;
	}
	SDL_QueryTexture(CactusTexture, NULL, NULL, &w, &h);
	
	CactusRect.x = x;
	CactusRect.y = y - h;
	CactusRect.w = w;
	CactusRect.h = h;
}

Cactus::~Cactus() {
	SDL_DestroyTexture(CactusTexture);
}

void Cactus::update(float dt) {

}

void Cactus::draw() {
	SDL_RenderCopy(Globals::renderer, CactusTexture, NULL, &CactusRect);
}