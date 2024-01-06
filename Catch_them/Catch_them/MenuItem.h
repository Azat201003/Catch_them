#pragma once
#include <SFML/Graphics.hpp>

class Button {
public:
	Button(sf::Texture aTexture, sf::Text aText);
	void onClick(void (*foo)());
private:
	sf::Texture texture;
	sf::Text	text;
};

