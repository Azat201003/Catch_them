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
	float posRange = sprite.getTextureRect().width - thumbSprite.getTextureRect().width;
	float valueWidth = range.y - range.x;
	float pixelsByValue = posRange / valueWidth;
	float thumbPixelPos = texturePos.x + thumbPos * pixelsByValue;
	thumbSprite.setPosition(thumbPixelPos, sprite.getPosition().y);
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
			isChanging = true;
		}
	} else { outFocus(&sprite); }
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		isChanging = false;
	}
	if (isChanging) {
		float posRange = sprite.getTextureRect().width - thumbSprite.getTextureRect().width;
		float valueWidth = range.y - range.x;
		float pixelsByValue = posRange / valueWidth;
		thumbPos = std::max(range.x, std::min(range.y, (mouseCoords.x - sprite.getPosition().x) / pixelsByValue + range.x));
		float thumbPixelPos = sprite.getPosition().x + thumbPos * pixelsByValue;
		thumbSprite.setPosition(std::max(std::min(thumbPixelPos, posRange + sprite.getPosition().x), sprite.getPosition().x), sprite.getPosition().y);
		onChange(thumbPos);
	}
}

void Slider::draw(sf::RenderWindow* window) {
	window->draw(sprite);
	window->draw(thumbSprite);
}
