#include "PlayerSelectionScene.h"

PlayerSelectionScene::PlayerSelectionScene() {

	// Button default is (370 * 50), But it also takes two params Button(w, h);
	// Button to select character to play
	c1Button = new Button(300, 300);
	c1Button->setRenderer(Globals::renderer);
	c1Button->pos.x = 500;
	c1Button->pos.y = 200;

	renderObjects.push_back(c1Button);

	c2Button = new Button(300, 300);
	c2Button->setRenderer(Globals::renderer);
	c2Button->pos.x = 850;
	c2Button->pos.y = 200;

	renderObjects.push_back(c2Button);

	c3Button = new Button(300, 300);
	c3Button->setRenderer(Globals::renderer);
	c3Button->pos.x = 1200;
	c3Button->pos.y = 200;

	renderObjects.push_back(c3Button);

	backButton = new Button();
	backButton->setRenderer(Globals::renderer);
	backButton->pos.x = 40;
	backButton->pos.y = 790;

	renderObjects.push_back(backButton);

	// Setup the font and font color
	font = TTF_OpenFont("Assets/Roboto/Roboto-Regular.ttf", 32);
	fontColor = { 220, 220, 220, 0 }; // RGBA

	// Add title --------------------------------------------------------------------------------------------------------------------------------------------------------
	TTF_Font *titleFont = TTF_OpenFont("Assets/Roboto/Roboto-Regular.ttf", 80);
	SDL_Surface *titleTextSurface = TTF_RenderText_Blended(titleFont, "> Select Character", fontColor);
	titleTexture = SDL_CreateTextureFromSurface(Globals::renderer, titleTextSurface);
	SDL_FreeSurface(titleTextSurface);

	titleRect.x = 40;
	titleRect.y = 40;
	SDL_QueryTexture(titleTexture, NULL, NULL, &titleRect.w, &titleRect.h);


	// Add back button font --------------------------------------------------------------------------------------------------------------------------------------------------------
	SDL_Surface *exitTextSurface = TTF_RenderText_Blended(font, "Back", fontColor);
	backButtonTexture = SDL_CreateTextureFromSurface(Globals::renderer, exitTextSurface);
	SDL_FreeSurface(exitTextSurface);

	backButtonRect.x = 70;
	backButtonRect.y = 800;
	SDL_QueryTexture(backButtonTexture, NULL, NULL, &backButtonRect.w, &backButtonRect.h);

	// Render character for player to choose Player(AnimationNumber, position.x, position.y)
	character0 = new Player(500, 200);
	character1 = new Player(850, 200);
	character2 = new Player(1200, 200);

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
	SDL_DestroyTexture(backButtonTexture);
}

void PlayerSelectionScene::update() {
	//update time management stuff
	Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
	dt = timeDiff / 1000.0;
	lastUpdate = SDL_GetTicks();

	// Check for input
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
	// Draw each menu objects
	for (GameObject *ro : renderObjects) {
		ro->draw(ro->checkIfHover(mousePos));
	}

	for (GameObject *po : playerObjects) {
		po->update(dt);
	}

	// Render textTexture
	//SDL_RenderCopy(renderer, titleTexture, NULL, &titleRect);
	SDL_RenderCopy(Globals::renderer, titleTexture, NULL, &titleRect);
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
