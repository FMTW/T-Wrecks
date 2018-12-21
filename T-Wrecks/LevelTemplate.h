#pragma once
#include <list>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Globals.h"
#include "GameScene.h"
#include "GameObject.h"
#include "Button.h"

#include "Player.h"

#include "KeyboardHandler.h"

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

private:
	Player *player;
	KeyboardHandler *kbHandler;

	// List of stuffs to render;
	list<GameObject*> lvlObjects;

	// Time related stuffs
	Uint32 lastUpdate;
	float dt;

	// Input Handler for MenuScene
	MouseHandler *mouseHandler;
	Vector mousePos;
};