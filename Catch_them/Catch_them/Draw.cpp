#include "Draw.h"
#include <SFML/Graphics.hpp>

using namespace sf;
void Draw::drawPlayer(Player player, RenderWindow* window, Shape* playerShape) {
	playerShape->setPosition(player.getPos().x, player.getPos().y);
	window->draw(*playerShape);
}
