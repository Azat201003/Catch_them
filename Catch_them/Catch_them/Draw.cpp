#include "Draw.h"
#include <SFML/Graphics.hpp>

using namespace sf;
void Draw::drawPlayer(Player player, RenderWindow* window) {
	window->draw(player.getSprite());
}
