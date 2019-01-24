#include "CollisionHandler.h"

CollisionHandler::CollisionHandler() {}
CollisionHandler::~CollisionHandler() {}

bool CollisionHandler::checkCollision(GameObject obj1, GameObject obj2) {
	//cout << "  Object 1's parameter - " << obj1.pos.x << ", " << obj1.frameWidth << ", " << obj1.pos.y << ", " << obj1.frameHeight << endl;
	//cout << "  Object 2's parameter - " << obj2.pos.x << ", " << obj2.frameWidth << ", " << obj2.pos.y << ", " << obj2.frameHeight << endl;
	int colVelTwick = 5;
	return  !((obj1.pos.x + colVelTwick < (obj2.pos.x + obj2.frameWidth - colVelTwick) &&
		(obj1.pos.x + (obj1.frameWidth / 2) - colVelTwick) > obj2.pos.x + colVelTwick) &&
		obj1.pos.y + colVelTwick < (obj2.pos.y + obj2.frameHeight - colVelTwick) &&
		(obj1.pos.y + (obj1.frameHeight / 2) - colVelTwick) > obj2.pos.y + colVelTwick);
}