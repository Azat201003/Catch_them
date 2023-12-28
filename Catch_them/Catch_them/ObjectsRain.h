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
	ObjectsRain(vector<Texture> aTextures);
	void update();
private:
	vector<Object> objects;
	vector<Texture> textures;
};

