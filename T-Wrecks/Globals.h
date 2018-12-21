#pragma once
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "GameSceneManager.h"

class Globals
{
public:
	Globals();
	~Globals();

	// Setup Basic stuffs
	static SDL_Renderer *renderer;
	static bool quitGame;
	static GameSceneManager gsm;

	// Setup inputHandlers

	// Setup Stuffs for the game
};

