#include "IntroScene.h"

IntroScene::IntroScene() {
	backgroundRect = { 0, 0, 1280, 720 };

	imgTexture = IMG_LoadTexture(Globals::renderer, "Assets/CupyCat.png");
	SDL_QueryTexture(imgTexture, NULL, NULL, &iWidth, &iHeight);
	logoRect = { 511, 169, iWidth/2, iHeight/2 };
}

IntroScene::~IntroScene() {
	SDL_DestroyTexture(imgTexture);
}

void IntroScene::update() {

	if (SDL_GetTicks() > 3000) {
		Globals::gsm.popScene();
		Globals::gsm.pushScene(new MenuScene());
	}

}

void IntroScene::render() {
	SDL_SetRenderDrawColor(Globals::renderer, 244, 244, 244, 100);
	SDL_RenderFillRect(Globals::renderer, &backgroundRect);

	SDL_RenderCopy(Globals::renderer, imgTexture, NULL, &logoRect);

	SDL_RenderPresent(Globals::renderer);
}

bool IntroScene::onEnter() {
	cout << "Pushed Intro Scene" << endl;
	return true;
}

bool IntroScene::onExit() {
	cout << "Popped Intro Scene" << endl;
	return true;
}