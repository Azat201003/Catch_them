#include "MenuItem.h"

Button::Button(sf::Texture* aTexture, sf::Text aText, instruments::Pos texturePos, instruments::Pos textPos) {
	sprite.setTexture(*aTexture);
	sprite.setPosition(texturePos.x, texturePos.y);

	text	= aText   ;
	text.setPosition(textPos.x, textPos.y);
}

void Button::onClick(void (*aFoo)()) {
	onclick = aFoo;
}

void Button::update(sf::RenderWindow *window) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		instruments::Pos mouseCoords(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);

		sf::FloatRect bounds = sprite.getGlobalBounds();

		if (bounds.contains(mouseCoords.x, mouseCoords.y))
		{
			onclick();
		}
	}
}

void Button::draw(sf::RenderWindow* window) {
	window->draw(sprite);
	window->draw(text);
}