#pragma once
#include "GameScene.h"
#include "Globals.h"

#include "MenuScene.h"

class IntroScene :
	public GameScene
{
public:
	IntroScene();
	~IntroScene();

	//override those abstract methods inherited from GameScene
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() {
		return "IntroScene";
	}

private:
	int iWidth, iHeight;
	SDL_Rect backgroundRect, logoRect;
	SDL_Texture *imgTexture;
};

