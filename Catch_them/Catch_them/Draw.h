#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Object.h"
#include "MenuItem.h"

using namespace sf;
using namespace std;
class Draw
{
public:
	void drawPlayer(Player player, sf::RenderWindow* window);
	void drawObjects(vector<Object> objects, sf::RenderWindow* window);
	void drawBackground(Texture background, sf::RenderWindow* window);
	void drawMenu(vector<MenuItem> *menuObjects, sf::RenderWindow* window);
};

