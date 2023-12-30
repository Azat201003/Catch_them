#pragma once
#include "Object.h"
#include "setting.h"
#include "player.h"
#include <vector>
#include <chrono>

using namespace setting;
using namespace std;
class ObjectsRain
{
public:
	ObjectsRain(vector<Sprite> aTextures);
	vector<Object> getObjects();
	void update(Player *player);
	void spawnLine(int i);
	void addObject();
	void isCollisionPlayer(int indexObject, Player *player);
private:
	vector<Object> objects;
	vector<Sprite> sprites;
};

