#include "MenuItem.h"

Button::Button(sf::Texture* aTexture, sf::Text aText, instruments::Pos texturePos, instruments::Pos textPos, sf::Image defaultCursorImage) {
	sprite.setTexture(*aTexture);
	sprite.setPosition(texturePos.x, texturePos.y);

	text	= aText   ;
	text.setPosition(textPos.x, textPos.y);
	defaultCursor.loadFromPixels(defaultCursorImage.getPixelsPtr(), defaultCursorImage.getSize(), {0, 0});
	handCursor.loadFromSystem(sf::Cursor::Hand);
}

void Button::setOnClickFunction(void(*aFoo)()) {
	onclick = aFoo;
}

void Button::setOnFocusFunction(void (*aFoo) (sf::Sprite*, sf::Text*)) {
	onFocus = aFoo;
}

void Button::setOutFocusFunction(void (*aFoo) (sf::Sprite*, sf::Text*)) {
	outFocus = aFoo;
}

void Button::update(sf::RenderWindow *window) {
	sf::FloatRect bounds = sprite.getGlobalBounds();
	instruments::Pos mouseCoords(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
	if (bounds.contains(mouseCoords.x, mouseCoords.y) && window->hasFocus()) {
		onFocus(&sprite, &text);
		window->setMouseCursor(handCursor);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			onclick();
		}
		return;
	}
	window->setMouseCursor(defaultCursor);
	outFocus(&sprite, &text);

}

void Button::draw(sf::RenderWindow* window) {
	window->draw(sprite);
	window->draw(text);
}