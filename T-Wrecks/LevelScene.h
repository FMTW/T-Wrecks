#pragma once
#include <list>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Globals.h"
#include "GameScene.h"
#include "GameObject.h"

#include "Player.h"
#include "Ground.h"
#include "Cactus.h"
#include "Cloud.h"
#include "Pterosaur.h"

#include "PauseScene.h"
#include "LeaderboardScene.h"

#include "TimeHandler.h"
#include "KeyboardHandler.h"
#include "CollisionHandler.h"

class LevelScene : public GameScene {
public:
	LevelScene(int);
	~LevelScene();

	//override those abstract methods inherited from GameScene
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() { return "LevelScene"; }

	void setupObjects();
	void checkCollision();
	void updateScore();
	bool readPreviousScore();
	void writeScore();
	void exitRound();
	void loadDebugInfo();

private:
	bool debugActive;
	bool bonus = false;
	bool medium = false;
	bool hard = false;
	float velMultiplier;

	Player *player;
	KeyboardHandler *kbHandler;

	SDL_Rect backgroundRect;

	Ground *ground;
	Cactus *cactus;
	Cloud *cloud1, *cloud2, *cloud3;
	Pterosaur *ptsaur1, *ptsaur2, *ptsaur3;
	
	// List of stuffs to render;
	list<GameObject*> lvlObjects;
	list<GameObject*> obstObjects;

	// Time related stuffs
	TimeHandler *t;
	float dt;

	// Stuffs for show off
	bool isAlive;
	int score, point;
	TTF_Font *font;
	SDL_Texture *scoreTexture, *goTexture, *nameInputTexture;
	SDL_Rect scoreRect, goRect;
	char scoreStr[20], readScore[20];
	SDL_RWops *scoreFile;
	string scoreOutput;
	int previousScore;

	// End Game Countdown
	int countDown;

	// Handle Text Input
	char *name;
};