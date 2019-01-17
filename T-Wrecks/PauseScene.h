#pragma once
#include <list>

#include "GameScene.h"
#include "Globals.h"
#include "Button.h"

class PauseScene :
	public GameScene
{
public:
	PauseScene();
	~PauseScene();

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() {
		return "PauseScene";
	}

private:
	TTF_Font *font;
	Button *resumeButton, *restartButton, *backToMenuButton;
	SDL_Texture *titleTexture, *resumeTexture, *restartTexture, *backToMenuTexture;
	SDL_Rect backgroundRect, titleRect, resumeRect, restartRect, backToMenuRect;

	list<GameObject*> buttonObjects;

	MouseHandler *mouseHandler;
	Vector mousePos;

};

