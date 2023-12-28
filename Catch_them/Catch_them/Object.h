#pragma once
#include <SFML/Graphics.hpp>
#include "setting.h"

using namespace sf;
using namespace instruments;
class Object
{
public:
	Object(Texture aTexture, int aSpeed, Pos aPos);
	Texture getTexture();
	Pos getPos();
	int getSpeed();
private:
	Texture texture;
	Pos pos;
	int speed;
};

