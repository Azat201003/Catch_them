#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Object.h"
#include "MenuItem.h"

class Draw
{
public:
	void drawPlayer(Player player, sf::RenderWindow* window);
	void drawObjects(std::vector<Object> objects, sf::RenderWindow* window);
	void drawBackground(sf::Texture background, sf::RenderWindow* window);
	void drawMenu(std::vector<MenuItem> *menuObjects, sf::RenderWindow* window);
};

