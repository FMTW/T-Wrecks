
#include "GameObject.h"
class CollisionHandler :
	public GameObject
{
public:
	CollisionHandler();
	~CollisionHandler();
	static bool checkCollision(GameObject, GameObject);
};