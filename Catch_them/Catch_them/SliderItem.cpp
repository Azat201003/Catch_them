#include "MenuItem.h"


Slider::Slider(sf::Texture* aTexture, sf::Texture* thumbTexture, instruments::Pos texturePos, instruments::Pos thumbPos, float aLeftBorder, float aRightBorder) {
	sprite.setTexture(*aTexture);
	sprite.setPosition(texturePos.x, texturePos.y);
	leftBorder = aLeftBorder;
	rightBorder = aRightBorder;
}

void Slider::setOnFocusFunction(void (*aFoo) (sf::Sprite*)) {
	onFocus = aFoo;
}

void Slider::setOutFocusFunction(void (*aFoo) (sf::Sprite*)) {
	outFocus = aFoo;
}

void Slider::draw(sf::RenderWindow* window) {
	window->draw(sprite);
}


void Slider::update(sf::RenderWindow* window) {

	sf::FloatRect bounds = sprite.getGlobalBounds();
	instruments::Pos mouseCoords(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
	if (bounds.contains(mouseCoords.x, mouseCoords.y) && window->hasFocus()) {
		onFocus(&sprite);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			isChanging = true;
		}
		return;
	}
	outFocus(&sprite);
}
