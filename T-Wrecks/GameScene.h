#pragma once
#include <string>
#include <iostream>
#include <SDL.h>

using namespace std;

class GameScene
{
public:
	GameScene();
	~GameScene();

	//abstract functions
	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual string getStateID() = 0;
};

