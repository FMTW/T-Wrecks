#pragma once
#include "GameObject.h"
#include "MouseHandler.h"

class Button : public GameObject
{
public:
	Button(int, int);
	~Button();

	virtual void draw(bool);
	bool checkIfHover(Vector);

private:
	int w, h;

};

