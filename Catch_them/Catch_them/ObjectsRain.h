#pragma once
#include "Object.h"
#include "setting.h"
#include "player.h"
#include <vector>
#include <chrono>

class ObjectsRain
{
public:
	ObjectsRain(std::vector<sf::Sprite> aTextures);
	std::vector<Object> getObjects();
	void update(Player *player);
	void spawnLine(int i);
	void addObject();
	void isCollisionPlayer(int indexObject, Player *player);
private:
	std::vector<Object> objects;
	std::vector<sf::Sprite> sprites;
};

