#pragma once
#include "GameScene.h"
#include <vector> //for our stack structure

using namespace std;

class GameSceneManager
{
public:
	//our stack of gamestates
	vector<GameScene*> gameScenes;

	GameSceneManager();
	~GameSceneManager();

	//state management
	void pushScene(GameScene* state);
	void changeScene(GameScene* state);
	void popScene();
	void clearAll();

	void update();
	void render();


};

