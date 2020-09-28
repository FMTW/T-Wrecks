#include "TimeHandler.h"

TimeHandler::TimeHandler() {
	lastUpdate = SDL_GetTicks();
}

TimeHandler::~TimeHandler() {}

float TimeHandler::getDeltaTime() {
	Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
	dt = timeDiff / 1000.0;
	lastUpdate = SDL_GetTicks();
	return dt;
}