#include "Draw.h"
#include <SFML/Graphics.hpp>

using namespace sf;
void Draw::drawPlayer(Player player, RenderWindow* window) {
	window->draw(player.getSprite());
}
void Draw::drawObjects(vector<Object> objects, RenderWindow* window) {
	for (int i = 0; i < objects.size(); i++) {
		window->draw(objects.at(i).getSprite());
		Font font;
		font.loadFromFile("res/fonts/Robotocondensed.ttf");
		//Text text(to_string( objects.at(i).getSprite().getPosition().x) + ", " + to_string(objects.at(i).getSprite().getPosition().y), font, 20);
		//window->draw(text);
	}
}
