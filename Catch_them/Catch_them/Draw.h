#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Object.h"

using namespace sf;
using namespace std;
class Draw
{
public:
	void drawPlayer(Player player, sf::RenderWindow* window);
	void drawObjects(vector<Object> objects, sf::RenderWindow* window);
};

