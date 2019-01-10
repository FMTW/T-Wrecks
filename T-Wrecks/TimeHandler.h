#pragma once
#include <SDL.h>
#include <iostream>

using namespace std;

class TimeHandler
{
public:
	TimeHandler();
	~TimeHandler();

	float getDeltaTime();
	
private:
	float dt;
	Uint32 lastUpdate;
};

