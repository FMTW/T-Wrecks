#include "PlayerSelectionScene.h"

PlayerSelectionScene::PlayerSelectionScene() {
	backgroundRect = { 0, 0, 1280, 720 };

	// Button Related Stuffs -----------------------------------------------------------------------------------
	// Button default is (370 * 50), But it also takes two params Button(w, h);
	
	startButton = new Button();
	startButton->setRenderer(Globals::renderer);
	startButton->pos.x = 40;
	startButton->pos.y = 535;

	renderObjects.push_back(startButton);

	backButton = new Button();
	backButton->setRenderer(Globals::renderer);
	backButton->pos.x = 40;
	backButton->pos.y = 610;

	renderObjects.push_back(backButton);

	// Font Related Stuffs -----------------------------------------------------------------------------------

	font = TTF_OpenFont("Assets/MONO.ttf", 32);
	fontColor = { 83, 83, 83, 100 };

	// Add title --------------------------------------------------------------------------------------------------------------------------------------------------------
	TTF_Font *titleFont = TTF_OpenFont("Assets/MONO.ttf", 75);
	SDL_Surface *titleTextSurface = TTF_RenderText_Blended(titleFont, "SELECT DINO", fontColor);
	titleTexture = SDL_CreateTextureFromSurface(Globals::renderer, titleTextSurface);
	SDL_FreeSurface(titleTextSurface);

	titleRect.x = 40;
	titleRect.y = 40;
	SDL_QueryTexture(titleTexture, NULL, NULL, &titleRect.w, &titleRect.h);

	// Add start button font --------------------------------------------------------------------------------------------------------------------------------------------------------
	SDL_Surface *startTextSurface = TTF_RenderText_Blended(font, "START", fontColor);
	startButtonTexture = SDL_CreateTextureFromSurface(Globals::renderer, startTextSurface);
	SDL_FreeSurface(startTextSurface);

	startButtonRect.x = 70;
	startButtonRect.y = 545;
	SDL_QueryTexture(startButtonTexture, NULL, NULL, &startButtonRect.w, &startButtonRect.h);

	// Add back button font --------------------------------------------------------------------------------------------------------------------------------------------------------
	SDL_Surface *exitTextSurface = TTF_RenderText_Blended(font, "BACK TO MENU", fontColor);
	backButtonTexture = SDL_CreateTextureFromSurface(Globals::renderer, exitTextSurface);
	SDL_FreeSurface(exitTextSurface);

	backButtonRect.x = 70;
	backButtonRect.y = 620;
	SDL_QueryTexture(backButtonTexture, NULL, NULL, &backButtonRect.w, &backButtonRect.h);

	// Render character for player to choose Player(AnimationNumber, position.x, position.y)
	character0 = new Player(500, 200, false);
	character1 = new Player(850, 200, false);
	character2 = new Player(1200, 200, false);

	playerObjects.push_back(character0);
	playerObjects.push_back(character1);
	playerObjects.push_back(character2);

	// Prep time stuff
	lastUpdate = SDL_GetTicks(); // Milliseconds since the start of the game running

	// Input Handlers
	mouseHandler = new MouseHandler();
}


PlayerSelectionScene::~PlayerSelectionScene() {
	SDL_DestroyTexture(titleTexture);
	SDL_DestroyTexture(startButtonTexture);
	SDL_DestroyTexture(backButtonTexture);
}

void PlayerSelectionScene::update() {
	Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
	dt = timeDiff / 1000.0;
	lastUpdate = SDL_GetTicks();

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		// Check if the window is closed
		if (event.type == SDL_QUIT) {
			Globals::quitGame = true;
			Globals::gsm.clearAll();
			return;
		}

		// Go back to last scene when clicked "Back" button
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
			if (event.button.x >= startButton->pos.x && event.button.x <= startButton->pos.x + 400
				&&
				event.button.y >= startButton->pos.y && event.button.y <= startButton->pos.y + 70) {
				Globals::gsm.pushScene(new LevelTemplate());
				return;
			}
		}

		// Go back to last scene when clicked "Back" button
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
			if (event.button.x >= backButton->pos.x && event.button.x <= backButton->pos.x + 400
				&&
				event.button.y >= backButton->pos.y && event.button.y <= backButton->pos.y + 70) {
				Globals::gsm.popScene();
				return;
			}
		}
	}

	// Monitor Mouse Coordinate
	mousePos = mouseHandler->getMouseState();
}

void PlayerSelectionScene::render() {
	// Render Background
	SDL_SetRenderDrawColor(Globals::renderer, 244, 244, 244, 100);
	SDL_RenderFillRect(Globals::renderer, &backgroundRect);

	// Draw each menu objects
	for (GameObject *ro : renderObjects) {
		ro->draw(ro->checkIfHover(mousePos));
	}

	for (GameObject *po : playerObjects) {
		po->update(dt);
	}

	// Render textTexture
	SDL_RenderCopy(Globals::renderer, titleTexture, NULL, &titleRect);
	SDL_RenderCopy(Globals::renderer, startButtonTexture, NULL, &startButtonRect);
	SDL_RenderCopy(Globals::renderer, backButtonTexture, NULL, &backButtonRect);

	// Present all our renderings to the window when you have enough drawing stuffs
	SDL_RenderPresent(Globals::renderer);
}

bool PlayerSelectionScene::onEnter() {
	cout << "Pushed Player Selection Scene" << endl;
	return true;
}

bool PlayerSelectionScene::onExit() {
	cout << "Popped Player Selection Scene" << endl;
	return true;
}
