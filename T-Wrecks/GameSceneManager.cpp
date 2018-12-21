#include "GameSceneManager.h"

GameSceneManager::GameSceneManager() {}
GameSceneManager::~GameSceneManager() {}

void GameSceneManager::pushScene(GameScene* state) {
	//add to our vector ;)
	gameScenes.push_back(state);
	//call onEnter on newest state
	gameScenes.back()->onEnter();
}

void GameSceneManager::changeScene(GameScene* state) {
	if (!gameScenes.empty()) {
		//if state same as what we're trying to change to, then exit early
		if (gameScenes.back()->getStateID() == state->getStateID())
			return;

		//run onExit for top state in stack and then remove it
		if (gameScenes.back()->onExit()) {
			delete gameScenes.back(); //delete the dynamically allocated state in top position
			gameScenes.pop_back(); //remove the now useless state pointer from our stack
		}
		else
		{
			cout << "Error running onExit for state: " << gameScenes.back()->getStateID() << endl;
		}
	}
	//add the new state
	pushScene(state);

}
void GameSceneManager::popScene() {
	//remove top state
	if (!gameScenes.empty()) {
		//run onExit for top state in stack and then remove it
		if (gameScenes.back()->onExit()) {
			delete gameScenes.back(); //delete the dynamically allocated state in top position
			gameScenes.pop_back(); //remove the now useless state pointer from our stack
		}
		else
		{
			cout << "Error running onExit for state: " << gameScenes.back()->getStateID() << endl;
		}
	}
}
void GameSceneManager::clearAll() {
	//delete all the dynamic memory first
	for (auto gs : gameScenes) {
		delete gs;
	}
	//then clear stack
	gameScenes.clear();
}

void GameSceneManager::update() {
	if (!gameScenes.empty())
		gameScenes.back()->update();
}
void GameSceneManager::render() {
	if (!gameScenes.empty())
		gameScenes.back()->render();
}
