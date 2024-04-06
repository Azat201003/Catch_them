#include "Draw.h"
#include <SFML/Graphics.hpp>

void Draw::drawPlayer(Player player, sf::RenderWindow* window) {
	window->draw(player.getSprite());
	sf::Font font;
	font.loadFromFile("res/fonts/Robotocondensed.ttf");
	sf::Text coinsText(std::to_string(player.getCoins()), font, 40);
	coinsText.setPosition(setting::WIDTH - setting::LEN_COINS, 0);
	window->draw(coinsText);
	sf::Text hpText(std::to_string(player.getHp()), font, 40);
	hpText.setPosition(setting::WIDTH - setting::LEN_HP, 0);
	hpText.setFillColor(sf::Color(200, 10, 10));
	window->draw(hpText);
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

void Draw::drawMenu(MenuItem *menuObjects[], int size, sf::RenderWindow* window) {
	for (int i = 0; i < size; i++) {
		menuObjects[i]->draw(window);
	}
}

