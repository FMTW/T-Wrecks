#include "CollisionHandler.h"

CollisionHandler::CollisionHandler() {}
CollisionHandler::~CollisionHandler() {}

bool CollisionHandler::checkCollision(GameObject obj1, GameObject obj2) {
	//cout << "  Object 1's parameter - " << obj1.pos.x << ", " << obj1.frameWidth << ", " << obj1.pos.y << ", " << obj1.frameHeight << endl;
	//cout << "  Object 2's parameter - " << obj2.pos.x << ", " << obj2.frameWidth << ", " << obj2.pos.y << ", " << obj2.frameHeight << endl;
	
	if ((obj1.pos.x < (obj2.pos.x + obj2.frameWidth) &&
		(obj1.pos.x + (obj1.frameWidth / 2)) > obj2.pos.x) &&
		obj1.pos.y < (obj2.pos.y + obj2.frameHeight) &&
		(obj1.pos.y + (obj1.frameHeight / 2)) > obj2.pos.y) {
		return false;
	}

}