#include "Cloud.h"

Cloud::Cloud() {
	vel.x = -(rand() % 100 + 100);
	loadTexture();
}


Cloud::~Cloud() {
	SDL_DestroyTexture(cloudTexture);
}

void Cloud::update(float dt) {
	updateMovement(dt);
	checkBoundry();
	//checkPosition();

	cloudRect.x = pos.x;
	cloudRect.y = pos.y;
}

void Cloud::draw(bool) {
	SDL_RenderCopy(Globals::renderer, cloudTexture, NULL, &cloudRect);
}

void Cloud::loadTexture() {
	randNum = rand() % 3 + 1;
	switch (randNum) {
	case 1:
		cloudTexture = IMG_LoadTexture(Globals::renderer, "Assets/Clouds/Cloud_1.png");
		break;
	
	case 2:
		cloudTexture = IMG_LoadTexture(Globals::renderer, "Assets/Clouds/Cloud_2.png");
		break;

	case 3:
		cloudTexture = IMG_LoadTexture(Globals::renderer, "Assets/Clouds/Cloud_3.png");
		break;
	}
	SDL_QueryTexture(cloudTexture, NULL, NULL, &frameWidth, &frameHeight);

	pos.x = rand() % 1280 + 1281;
	pos.y = (rand() % 50 + 350) - frameWidth;

	cloudRect.w = frameWidth;
	cloudRect.h = frameHeight;
}

void Cloud::checkBoundry() {
	if (pos.x < -frameWidth*2) {
		loadTexture();
		vel.x = -(rand() % 100 + 100);
	}
}

// Just for debugging
void Cloud::checkPosition() {
	cout << "  Cloud Position(" << pos.x << ", " << pos.y << ")\n"
		<< "  Cloud Rect Position(" << cloudRect.x << ", " << cloudRect.y << ")\n";
}