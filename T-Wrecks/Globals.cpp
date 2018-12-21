#include "Globals.h"


Globals::Globals() {}
Globals::~Globals() {}

SDL_Renderer *Globals::renderer = NULL;
bool Globals::quitGame = false;
GameSceneManager Globals::gsm;