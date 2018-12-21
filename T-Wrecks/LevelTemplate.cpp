#include "LevelTemplate.h"

LevelTemplate::LevelTemplate() { 
	// Setting up player in the level
	player = new Player(20, 20);
	player->setRenderer(Globals::renderer);
	lvlObjects.push_back(player);

	// Setup Keyboard Controller
	kbHandler = new KeyboardHandler();
	kbHandler->p = player;

	// Prep time stuff
	lastUpdate = SDL_GetTicks(); // Milliseconds since the start of the game running
}

LevelTemplate::~LevelTemplate() { }


void LevelTemplate::update() {
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
			return;
		}
	}
	
	// Update level objects
	for (GameObject *lo : lvlObjects) {
		lo->update(dt);
	}

	kbHandler->update(&event);

	// Monitor Mouse Coordinate
	//mousePos = mouseHandler->getMouseState();
}

void LevelTemplate::render() {
	// Render Background
	SDL_SetRenderDrawBlendMode(Globals::renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Globals::renderer, 10, 10, 10, 200);
	SDL_RenderClear(Globals::renderer);

	// Render all the Game Objects in the level
	for (GameObject *lo : lvlObjects) {
		lo->draw(false);
	}

	// Present all our renderings to the window when you have enough drawing stuffs
	SDL_RenderPresent(Globals::renderer);
}

bool LevelTemplate::onEnter() {
	cout << "Pushed Level Template Scene" << endl;
	return true;
}

bool LevelTemplate::onExit() {
	cout << "Popped Level Template Scene" << endl;
	return true;
}