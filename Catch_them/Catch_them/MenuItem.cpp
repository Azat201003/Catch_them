#include "MenuItem.h"

Button::Button(sf::Texture* aTexture, sf::Text aText, instruments::Pos texturePos, instruments::Pos textPos) {
	sprite.setTexture(*aTexture);
	sprite.setPosition(texturePos.x, texturePos.y);

	text	= aText   ;
	text.setPosition(textPos.x, textPos.y);
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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			onclick();
		}
		return;
	}
	outFocus(&sprite, &text);
}

void Button::draw(sf::RenderWindow* window) {
	window->draw(sprite);
	window->draw(text);
}

Slider::Slider(sf::Texture* aTexture, sf::Texture* thumbTexture, instruments::Pos texturePos, instruments::Pos range, float thumbPos) {
	sprite.setTexture(*aTexture);
	sprite.setPosition(texturePos.x, texturePos.y);
	thumbSprite.setTexture(*thumbTexture);
	thumbSprite.setPosition(texturePos.x + thumbPos * ((sprite.getTextureRect().width - thumbSprite.getTextureRect().width) / (range.y - range.x)), sprite.getPosition().y);
	this->range = range;
	this->thumbPos = thumbPos;
}

void Slider::setOnFocusFunction(void(*aFoo)(sf::Sprite*)) {
	onFocus = aFoo;
}

void Slider::setOutFocusFunction(void(*aFoo)(sf::Sprite*)) {
	outFocus = aFoo;
}

void Slider::setOnChangeFunction(void(*aFoo)(float value)) {
	onChange = aFoo;
}

void Slider::update(sf::RenderWindow* window) {
	sf::FloatRect bounds = sprite.getGlobalBounds();
	instruments::Pos mouseCoords(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
	if (bounds.contains(mouseCoords.x, mouseCoords.y) && window->hasFocus()) {
		onFocus(&sprite);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			thumbPos = (mouseCoords.x - sprite.getPosition().x) * (((sprite.getTextureRect().width - thumbSprite.getTextureRect().width) / (range.y - range.x) + range.x));
			thumbSprite.setPosition(mouseCoords.x, sprite.getPosition().y);
			onChange(thumbPos);
		}
		return;
	}
	outFocus(&sprite);
}

void Slider::draw(sf::RenderWindow* window) {
	window->draw(sprite);
	window->draw(thumbSprite);
}
