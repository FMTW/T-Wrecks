#pragma once
#include <list>

#include <SDL.h>
#include <SDL_ttf.h>

#include "Globals.h"
#include "GameScene.h"
#include "GameObject.h"
#include "Button.h"
#include "Player.h"
#include "Animation.h"

class PlayerSelectionScene : public GameScene {
public:
	PlayerSelectionScene();
	~PlayerSelectionScene();

	//override those abstract methods inherited from GameScene
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() {
		return "PlayerSelectionScene";
	}

private:
	Button *startButton, *backButton;

	TTF_Font *font;
	SDL_Color fontColor;

	SDL_Texture *titleTexture, *startButtonTexture, *backButtonTexture;
	SDL_Rect backgroundRect, titleRect, startButtonRect, backButtonRect;

	Player *character0, *character1, *character2;

	// List of Objects to render
	list<GameObject*> renderObjects;
	list<GameObject*> playerObjects;

	// Time related stuffs
	Uint32 lastUpdate;
	float dt;

	// Input Handler for MenuScene
	MouseHandler *mouseHandler;
	Vector mousePos;
};

