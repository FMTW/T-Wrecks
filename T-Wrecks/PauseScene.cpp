#include "PauseScene.h"


PauseScene::PauseScene() {
	backgroundRect = {0, 0, 1280, 720};
	// Button Related Stuffs -----------------------------------------------------------------------------------
	// Button default is (370 * 50), But it also takes two params Button(w, h);
	resumeButton = new Button(40, 460);
	restartButton = new Button(40, 535);
	backToMenuButton = new Button(40, 610);

	buttonObjects.push_back(resumeButton);
	buttonObjects.push_back(restartButton);
	buttonObjects.push_back(backToMenuButton);

	// Font Related Stuffs -----------------------------------------------------------------------------------

	font = TTF_OpenFont("Assets/MONO.ttf", 32);

	// Add title --------------------------------------------------------------------------------------------------------------------------------------------------------
	TTF_Font *titleFont = TTF_OpenFont("Assets/MONO.ttf", 75);
	SDL_Surface *titleTextSurface = TTF_RenderText_Blended(titleFont, "PAUSED", { 83, 83, 83 });
	titleTexture = SDL_CreateTextureFromSurface(Globals::renderer, titleTextSurface);
	SDL_FreeSurface(titleTextSurface);

	titleRect.x = 40;
	titleRect.y = 40;
	SDL_QueryTexture(titleTexture, NULL, NULL, &titleRect.w, &titleRect.h);


	// Add play button font --------------------------------------------------------------------------------------------------------------------------------------------------------
	SDL_Surface *resumeSurface = TTF_RenderText_Blended(font, "RESUME", { 83, 83, 83 });
	resumeTexture = SDL_CreateTextureFromSurface(Globals::renderer, resumeSurface);
	SDL_FreeSurface(resumeSurface);

	resumeRect.x = 70;
	resumeRect.y = 470;
	SDL_QueryTexture(resumeTexture, NULL, NULL, &resumeRect.w, &resumeRect.h);

	// Add play button font --------------------------------------------------------------------------------------------------------------------------------------------------------
	SDL_Surface *restartSurface = TTF_RenderText_Blended(font, "RESTART", { 83, 83, 83 });
	restartTexture = SDL_CreateTextureFromSurface(Globals::renderer, restartSurface);
	SDL_FreeSurface(restartSurface);

	restartRect.x = 70;
	restartRect.y = 545;
	SDL_QueryTexture(restartTexture, NULL, NULL, &restartRect.w, &restartRect.h);

	// Add leaderboard button font --------------------------------------------------------------------------------------------------------------------------------------------------------
	SDL_Surface *backToMenuSurface = TTF_RenderText_Blended(font, "BACK TO MENU", { 83, 83, 83 });
	backToMenuTexture = SDL_CreateTextureFromSurface(Globals::renderer, backToMenuSurface);
	SDL_FreeSurface(backToMenuSurface);

	backToMenuRect.x = 70;
	backToMenuRect.y = 620;
	SDL_QueryTexture(backToMenuTexture, NULL, NULL, &backToMenuRect.w, &backToMenuRect.h);

	mouseHandler = new MouseHandler();
}

PauseScene::~PauseScene() {
	SDL_DestroyTexture(titleTexture);
	SDL_DestroyTexture(resumeTexture);
	SDL_DestroyTexture(restartTexture);
	SDL_DestroyTexture(backToMenuTexture);

	delete mouseHandler;
	delete resumeButton;
	delete restartButton;
	delete backToMenuButton;
	resumeButton = NULL;
	restartButton = NULL;
	backToMenuButton = NULL;
	mouseHandler = NULL;

}

void PauseScene::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE) {
				Globals::gsm.popScene();
				return;
			}
		}

		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
			if (event.button.x >= resumeButton->pos.x && event.button.x <= resumeButton->pos.x + 320
				&&
				event.button.y >= resumeButton->pos.y && event.button.y <= resumeButton->pos.y + 60) {
				Globals::gsm.popScene();
				return;
			}
		}

		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
			if (event.button.x >= restartButton->pos.x && event.button.x <= restartButton->pos.x + 320
				&&
				event.button.y >= restartButton->pos.y && event.button.y <= restartButton->pos.y + 60) {
				Globals::gsm.popScene();
				Globals::gsm.popScene();
				return;
			}
		}

		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
			if (event.button.x >= backToMenuButton->pos.x && event.button.x <= backToMenuButton->pos.x + 320
				&&
				event.button.y >= backToMenuButton->pos.y && event.button.y <= backToMenuButton->pos.y + 60) {
				Globals::gsm.popScene();
				Globals::gsm.popScene();
				Globals::gsm.popScene();
				return;
			}
		}

	}
	
	mousePos = mouseHandler->getMouseState();
}

void PauseScene::render() {
	SDL_SetRenderDrawBlendMode(Globals::renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Globals::renderer, 244, 244, 244, 100);
	SDL_RenderFillRect(Globals::renderer, &backgroundRect);


	for (GameObject *ro : buttonObjects)
		ro->draw(ro->checkIfHover(mousePos));


	SDL_RenderCopy(Globals::renderer, titleTexture, NULL, &titleRect);
	SDL_RenderCopy(Globals::renderer, resumeTexture, NULL, &resumeRect);
	SDL_RenderCopy(Globals::renderer, restartTexture, NULL, &restartRect);
	SDL_RenderCopy(Globals::renderer, backToMenuTexture, NULL, &backToMenuRect);

	SDL_RenderPresent(Globals::renderer);
}

bool PauseScene::onEnter() {
	cout << "Pushed Pause Scene\n";
	return true;
}
bool PauseScene::onExit() {
	cout << "Popped Pasue Scene\n";
	return true;
}