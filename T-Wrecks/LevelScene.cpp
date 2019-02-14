#include "LevelScene.h"

LevelScene::LevelScene(int difficulty) {
	// Setup difficulty of the game
	velMultiplier = 50;
	point = 1;
	if (difficulty == 0)
		bonus = true;
	if (difficulty == 2) {
		medium = true;
		velMultiplier = 53;
		point = 2;
	}
	if (difficulty == 3) {
		hard = true;
		velMultiplier = 55;
		point = 4;
	}
	setupObjects();

	// Setup backgroundRect
	backgroundRect = { 0, 0, 1280, 720 };

	// Setup font
	font = TTF_OpenFont("Assets/MONO.ttf", 46);

	// Setup variables
	isAlive = true;
	debugActive = false;

	// Setup Keyboard Controller
	kbHandler = new KeyboardHandler(true);
	kbHandler->p = player;

	// Setup time (RIP Steven Hawkin)
	t = new TimeHandler();

	// Setup Score
	score = 0;
	scoreRect = { 900, 40 };

	// Setup Game Over Message
	SDL_Surface *goSurface = TTF_RenderText_Blended(font, "GAME OVER", { 83, 83, 83 });
	goTexture = SDL_CreateTextureFromSurface(Globals::renderer, goSurface);
	SDL_FreeSurface(goSurface);
	SDL_QueryTexture(goTexture, NULL, NULL, &goRect.w, &goRect.h);
	goRect.x = (640 - (goRect.w / 2));
	goRect.y = (300 - (goRect.h / 2));
};

LevelScene::~LevelScene() {
	SDL_DestroyTexture(scoreTexture);
	SDL_DestroyTexture(goTexture);

	lvlObjects.empty();
	obstObjects.empty();
	delete player;
	delete ground;
	delete cactus;
	delete cloud1, cloud2, cloud3;
	if (medium || hard)
		delete ptsaur1, ptsaur2, ptsaur3;
	delete kbHandler;
	delete t;
}

void LevelScene::update() {
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

			if (event.key.keysym.scancode == SDL_SCANCODE_F1) {
				if (debugActive)
					debugActive = false;
				else
					debugActive = true;
			}
		}
	}

	// Update Game if player is still alive
	if (isAlive) {
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
	else
		gameover();

	//if (debugActive)
		//loadDebugInfo();
}
 
void LevelScene::render() {
	SDL_SetRenderDrawColor(Globals::renderer, 244, 244, 244, 100);
	SDL_RenderClear(Globals::renderer);

	// Render all the Game Objects in the level
	for (GameObject *lo : lvlObjects)
		lo->draw(false);

	// Update level objects
	for (GameObject *oo : obstObjects)
		oo->draw(false);

	// Copy Score Text to renderer
	SDL_RenderCopy(Globals::renderer, scoreTexture, NULL, &scoreRect);
	if (!isAlive)
		SDL_RenderCopy(Globals::renderer, goTexture, NULL, &goRect);
	
	// Present all our renderings to the window when you have enough drawing stuffs
	SDL_RenderPresent(Globals::renderer);
}

bool LevelScene::onEnter() {
	cout << "Pushed Level Template Scene" << endl;
	return true;
}

bool LevelScene::onExit() {
	cout << "Popped Level Template Scene" << endl;
	return true;
}

// Setup all the objects and push them to the list
void LevelScene::setupObjects() {
	// Setup Player
	player = new Player(20, 560, true);
	lvlObjects.push_back(player);

	// Setup Ground
	ground = new Ground(true, velMultiplier);
	lvlObjects.push_back(ground);

	// Setup Clouds
	cloud1 = new Cloud(velMultiplier);
	cloud2 = new Cloud(velMultiplier);
	cloud3 = new Cloud(velMultiplier);
	lvlObjects.push_back(cloud1);
	lvlObjects.push_back(cloud2);
	lvlObjects.push_back(cloud3);

	// Setup Cactus
	cactus = new Cactus(true, velMultiplier);
	obstObjects.push_back(cactus);

	if (medium || hard) {
		// Setup Pterosaur
		ptsaur1 = new Pterosaur(velMultiplier, hard);
		ptsaur2 = new Pterosaur(velMultiplier, hard);
		ptsaur3 = new Pterosaur(velMultiplier, hard);
		obstObjects.push_back(ptsaur1);
		obstObjects.push_back(ptsaur2);
		obstObjects.push_back(ptsaur3);
	}

}

// Check collision for player and all objects in obstObjects list
void LevelScene::checkCollision() {
	for (GameObject *obst : obstObjects)
		if (!CollisionHandler::checkCollision(*player, *obst))
			isAlive = false;
}

// Calculate the score then display on the screen
void LevelScene::updateScore() {
	if (isAlive)
		score += point;
	sprintf_s(scoreStr, "Score: %d", score);
	SDL_Surface *scoreSurface = TTF_RenderText_Blended(font, scoreStr, { 83, 83, 83 });
	scoreTexture = SDL_CreateTextureFromSurface(Globals::renderer, scoreSurface);
	SDL_FreeSurface(scoreSurface);
	SDL_QueryTexture(scoreTexture, NULL, NULL, &scoreRect.w, &scoreRect.h);

}

// Do this when game is finished
void LevelScene::gameover() {
	if (countDown == NULL)
		countDown = SDL_GetTicks() + 3000;
	if (SDL_GetTicks() >= countDown) {
		Globals::gsm.popScene();
		Globals::gsm.popScene();
		Globals::gsm.pushScene(new LeaderboardScene());
	}
}

// Load information of the objects in this level
void LevelScene::loadDebugInfo() {
	system("cls");
	cout << "  Debug Infos\n";
	cout << "    " << scoreStr << endl;
	cout << "  Object Velocity:\n";
	cout << "    Cloud 1: " << cloud1->vel.x << endl;
	cout << "    Cloud 2: " << cloud2->vel.x << endl;
	cout << "    Cloud 3: " << cloud3->vel.x << endl;
	if (medium || hard) {
		cout << "    Pterosaur 1: " << ptsaur1->vel.x << endl;
		cout << "    Pterosaur 2: " << ptsaur2->vel.x << endl;
		cout << "    Pterosaur 3: " << ptsaur3->vel.x << endl;
	}
	cout << "    Cactus: " << cactus->vel.x << endl;
	cout << "    Ground: " << ground->vel.x << endl;
}