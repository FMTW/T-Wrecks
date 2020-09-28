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
#include "Button.h"

#include "LevelScene.h"
#include "PlayerSelectionScene.h"

class LevelSelectionScene : public GameScene {
public:
	LevelSelectionScene();
	~LevelSelectionScene();

	//override those abstract methods inherited from GameScene
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() { return "LevelSelectionScene"; }

private:
	Button *lvl1Button, *lvl2Button, *lvl3Button, *backButton;

	TTF_Font *font;
	SDL_Color fontColor;

	SDL_Texture *backgroundTexture, *titleTexture, *lvl1ButtonTexture, *lvl2ButtonTexture, *lvl3ButtonTexture, *backButtonTexture;
	SDL_Rect backgroundRect, titleRect, lvl1ButtonRect, lvl2ButtonRect, lvl3ButtonRect, backButtonRect;

	// List of stuffs to render;
	list<GameObject*> renderObjects;
	list<GameObject*> lvlObjects;

	float dt;
	Player *player;
	Ground *ground;
	TimeHandler *timeHandler;

	// Input Handler for MenuScene
	MouseHandler *mouseHandler;
	KeyboardHandler *keyboardHandler;
	Vector mousePos;

};