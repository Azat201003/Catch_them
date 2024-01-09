#include "Draw.h"
#include <SFML/Graphics.hpp>

void Draw::drawPlayer(Player player, sf::RenderWindow* window) {
	window->draw(player.getSprite());
	sf::Font font;
	font.loadFromFile("res/fonts/Robotocondensed.ttf");
	sf::Text text(std::to_string(player.getCoins()), font, 20);
	text.setPosition(setting::WIDTH - setting::LEN_COINS, 0);
	window->draw(text);
}

void Draw::drawObjects(std::vector<Object> objects, sf::RenderWindow* window) {
	for (int i = 0; i < objects.size(); i++) {
		window->draw(objects.at(i).getSprite());
	}
}

void Draw::drawBackground(sf::Texture background, sf::RenderWindow* window) {
	sf::Sprite sprite;
	sprite.setTexture(background);
	window->draw(sprite);
}
