#pragma once
#include <vector>
#include "Object.h"
#include "setting.h"
#include <chrono>

using namespace setting;
using namespace std;
class ObjectsRain
{
public:
	ObjectsRain(vector<Sprite> aTextures);
	void update();
	void spawnLine();
	void addObject();
	vector<Object> getObjects();
private:
	vector<Object> objects;
	vector<Sprite> sprites;
};

