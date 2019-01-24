#include "LevelTemplate.h"

LevelTemplate::LevelTemplate() {
	backgroundRect = { 0, 0, 1280, 720 };

	// Setup Player
	player = new Player(20, 560, true);
	lvlObjects.push_back(player);

	// Setup Ground
	ground = new Ground(true);
	lvlObjects.push_back(ground);

	// Setup Clouds
	cloud1 = new Cloud();
	cloud2 = new Cloud();
	cloud3 = new Cloud();
	lvlObjects.push_back(cloud1);
	lvlObjects.push_back(cloud2);
	lvlObjects.push_back(cloud3);

	// Setup Cactus
	cactus = new Cactus(true);
	cactus->setRenderer(Globals::renderer);
	obstObjects.push_back(cactus);

	// Setup Pterosaur
	ptsaur1 = new Pterosaur();
	ptsaur2 = new Pterosaur();
	ptsaur3 = new Pterosaur();
	obstObjects.push_back(ptsaur1);
	obstObjects.push_back(ptsaur2);
	obstObjects.push_back(ptsaur3);

	// Setup Keyboard Controller
	kbHandler = new KeyboardHandler(true);
	kbHandler->p = player;

	// Setup time (RIP Steven Hawkin)
	t = new TimeHandler();

	// Setup Score
	isAlive = true;
	score = 0;
	font = TTF_OpenFont("Assets/MONO.ttf", 46); 
	scoreRect.x = 1000;
	scoreRect.y = 40;

	// Setup Game Over Message
	SDL_Surface *goSurface = TTF_RenderText_Blended(font, "GAME OVER", { 83, 83, 83 });
	goTexture = SDL_CreateTextureFromSurface(Globals::renderer, goSurface);
	SDL_FreeSurface(goSurface);
	SDL_QueryTexture(goTexture, NULL, NULL, &goRect.w, &goRect.h);
	goRect.x = 640 - (goRect.w / 2);
	goRect.y = 360 - (goRect.h / 2);
}

LevelTemplate::~LevelTemplate() {
	SDL_DestroyTexture(scoreTexture);
}


void LevelTemplate::update() {
	// Check for input
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		// Check if the window is closed
		if (event.type == SDL_QUIT) {
			Globals::quitGame = true;
			return;
		}

		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				Globals::gsm.pushScene(new PauseScene());
				return;
			}
		}
	}

	// Update DeltaTime
	if (isAlive){
		dt = t->getDeltaTime();
		// Update level objects
		for (GameObject *lo : lvlObjects)
			lo->update(dt);

		// Update level objects
		for (GameObject *oo : obstObjects)
			oo->update(dt);

		kbHandler->update(&event);
		checkCollision();
		updateScore();
	}
	else {
		if (countDown == NULL)
			countDown = SDL_GetTicks() + 3000;
		cout << " Current Ticks: " << SDL_GetTicks()/1000 << "/" << countDown/1000 << endl;
		if (SDL_GetTicks() >= countDown) {
			Globals::gsm.popScene();
			Globals::gsm.popScene();
			Globals::gsm.pushScene(new LeaderboardScene());
		}
	}
}

void LevelTemplate::render() {
	SDL_SetRenderDrawColor(Globals::renderer, 244, 244, 244, 100);
	SDL_RenderFillRect(Globals::renderer, &backgroundRect);

	// Render all the Game Objects in the level
	for (GameObject *lo : lvlObjects)
		lo->draw(false);

	// Update level objects
	for (GameObject *oo : obstObjects)
		oo->draw(false);

	// Copy Score Text to renderer
	SDL_RenderCopy(Globals::renderer, scoreTexture, NULL, &scoreRect);
	if (!isAlive) {
		SDL_RenderCopy(Globals::renderer, goTexture, NULL, &goRect);
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

void LevelTemplate::checkCollision() {
	for (GameObject *obst : obstObjects)
		if (!CollisionHandler::checkCollision(*player, *obst))
			isAlive = false;
}

void LevelTemplate::updateScore() {
	if (isAlive)
		score += (dt / dt);
	sprintf_s(scoreStr, "Score: %d", score);
	cout << scoreStr << endl;
	SDL_Surface *scoreSurface = TTF_RenderText_Blended(font, scoreStr, { 83, 83, 83 });
	scoreTexture = SDL_CreateTextureFromSurface(Globals::renderer, scoreSurface);
	SDL_FreeSurface(scoreSurface);
	SDL_QueryTexture(scoreTexture, NULL, NULL, &scoreRect.w, &scoreRect.h);

}