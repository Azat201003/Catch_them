#pragma once
#include <SFML/Graphics.hpp>
#include "setting.h"

using namespace sf;
using namespace instruments;
class Object
{
public:
	Object(Sprite aSprite, int aSpeed, Pos aPos);
	Sprite getSprite();
	int getSpeed();
	void move(int y);
private:
	Sprite sprite;
	int speed;
};

