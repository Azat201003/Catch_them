#pragma once
#include <SFML/Graphics.hpp>
#include "setting.h"

using namespace sf;
using namespace instruments;
class Object
{
public:
	Object(Sprite aSprite, float aSpeed, Pos aPos);
	Sprite getSprite();
	float getSpeed();
	void move(float y);
private:
	Sprite sprite;
	float speed;
};

