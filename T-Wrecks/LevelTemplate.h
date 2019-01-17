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
#include "EndScene.h"
#include "TimeHandler.h"
#include "KeyboardHandler.h"
#include "CollisionHandler.h"

class LevelTemplate : public GameScene {
public:
	LevelTemplate();
	~LevelTemplate();

	//override those abstract methods inherited from GameScene
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() { return "LevelTemplate"; }

	void checkCollision();
	void updateScore();

private:
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
	int score;
	TTF_Font *font;
	SDL_Texture *scoreTexture;
	SDL_Rect scoreRect;
	char scoreStr[20];
};