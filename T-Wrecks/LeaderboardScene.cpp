#include "LeaderboardScene.h"

LeaderboardScene::LeaderboardScene() {
	// Add title image
	backgroundRect = { 0, 0, 1280, 720 };

	// Button default is (370 * 50), But it also takes two params Button(w, h);
	backButton = new Button();
	backButton->setRenderer(Globals::renderer);
	backButton->pos.x = 40;
	backButton->pos.y = 610;

	renderObjects.push_back(backButton);

	// Setup the font and font color
	font = TTF_OpenFont("Assets/MONO.ttf", 32);
	fontColor = { 83, 83, 83, 100 }; // RGBA

	// Add title --------------------------------------------------------------------------------------------------------------------------------------------------------
	TTF_Font *titleFont = TTF_OpenFont("Assets/MONO.ttf", 75);
	SDL_Surface *titleTextSurface = TTF_RenderText_Blended(titleFont, "LEADERBOARD", fontColor);
	titleTexture = SDL_CreateTextureFromSurface(Globals::renderer, titleTextSurface);
	SDL_FreeSurface(titleTextSurface);

	titleRect.x = 40;
	titleRect.y = 40;
	SDL_QueryTexture(titleTexture, NULL, NULL, &titleRect.w, &titleRect.h);

	// Add back button font --------------------------------------------------------------------------------------------------------------------------------------------------------
	SDL_Surface *exitTextSurface = TTF_RenderText_Blended(font, "BACK", fontColor);
	backButtonTexture = SDL_CreateTextureFromSurface(Globals::renderer, exitTextSurface);
	SDL_FreeSurface(exitTextSurface);

	backButtonRect.x = 70;
	backButtonRect.y = 620;
	SDL_QueryTexture(backButtonTexture, NULL, NULL, &backButtonRect.w, &backButtonRect.h);

	// Input Handlers
	mouseHandler = new MouseHandler();
}

LeaderboardScene::~LeaderboardScene() {
	SDL_DestroyTexture(backgroundTexture);
	SDL_DestroyTexture(titleTexture);
	SDL_DestroyTexture(backButtonTexture);
}


void LeaderboardScene::update() {
	// Check for input
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		// Check if the window is closed
		if (event.type == SDL_QUIT) {
			Globals::quitGame = true;
			return;
		}

		// Go back to last scene when "Back" is clicked.
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
			if (event.button.x >= backButton->pos.x && event.button.x <= backButton->pos.x + 320
				&&
				event.button.y >= backButton->pos.y && event.button.y <= backButton->pos.y + 60) {
				Globals::gsm.popScene();
				return;
			}
		}
	}


	// Monitor Mouse Coordinate
	mousePos = mouseHandler->getMouseState();
	//cout << "  Mouse Coordinate (" << mousePos.x << ", " << mousePos.y << ")\n";



}

void LeaderboardScene::render() {
	// Render Background
	SDL_SetRenderDrawColor(Globals::renderer, 244, 244, 244, 100);
	SDL_RenderFillRect(Globals::renderer, &backgroundRect);

	// Draw each menu objects
	for (GameObject *ro : renderObjects) {
		ro->draw(ro->checkIfHover(mousePos));
	}

	// Render textTexture
	SDL_RenderCopy(Globals::renderer, titleTexture, NULL, &titleRect);
	SDL_RenderCopy(Globals::renderer, backButtonTexture, NULL, &backButtonRect);

	// Present all our renderings to the window when you have enough drawing stuffs
	SDL_RenderPresent(Globals::renderer);
}

bool LeaderboardScene::onEnter() {
	cout << "Pushed Leaderboard Scene" << endl;
	return true;
}

bool LeaderboardScene::onExit() {
	cout << "Popped Leaderboard Scene" << endl;
	return true;
}
