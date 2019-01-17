#pragma once
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "GameSceneManager.h"
#include <time.h>
#include <stdlib.h>

class Globals
{
public:
	Globals();
	~Globals();

	static SDL_Renderer *renderer;
	static bool quitGame;
	static GameSceneManager gsm;
};

