#include "Draw.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace setting;
void Draw::drawPlayer(Player player, RenderWindow* window) {
	window->draw(player.getSprite());
	Font font;
	font.loadFromFile("res/fonts/Robotocondensed.ttf");
	Text text(to_string(player.getCoins()), font, 20);
	text.setPosition(WIDTH - LEN_COINS, 0);
	window->draw(text);
}

void Draw::drawObjects(vector<Object> objects, RenderWindow* window) {
	for (int i = 0; i < objects.size(); i++) {
		window->draw(objects.at(i).getSprite());
	}
}

void Draw::drawBackground(Texture background, RenderWindow* window) {
	Sprite sprite;
	sprite.setTexture(background);
	window->draw(sprite);
}

void Draw::drawMenu(vector<Texture> menuObjects, RenderWindow* window) {
	
}
