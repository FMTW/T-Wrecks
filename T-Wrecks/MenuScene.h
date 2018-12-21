#pragma once
#include <list>

#include "Globals.h"
#include "GameScene.h"
#include "GameObject.h"
#include "Button.h"

#include "LevelSelection.h"
#include "LeaderboardScene.h"

class MenuScene : public GameScene {
public:
	MenuScene();
	~MenuScene();

	//override those abstract methods inherited from GameScene
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() {
		return "MenuScene";
	}

private:
	Player *player;

	Button *playButton, *leaderboardButton, *settingButton, *exitButton;

	TTF_Font *font;
	SDL_Color fontColor;

	SDL_Texture *backgroundTexture, *titleTexture, *playButtonTexture, *leaderboardButtonTexture, *settingButtonTexture, *exitButtonTexture;
	SDL_Rect backgroundRect, titleRect, playButtonRect, leaderboardButtonRect, settingButtonRect, exitButtonRect;

	// List of stuffs to render;
	list<GameObject*> renderObjects;

	// Input Handler for MenuScene
	MouseHandler *mouseHandler;
	KeyboardHandler *keyboardHandler;
	Vector mousePos;


	Uint32 lastUpdate;
	float dt;

};