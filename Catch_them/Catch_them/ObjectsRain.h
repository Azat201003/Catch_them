#pragma once
#include "Object.h"
#include "setting.h"
#include "player.h"
#include <vector>
#include <chrono>
#include <SFML/Audio.hpp>

class ObjectsRain
{
public:
	ObjectsRain(std::vector<sf::Sprite> aTextures);
	std::vector<Object> getObjects();
	void update(Player *player, float wasTime, instruments::window &s_window);
	void spawnLine(int i, float wasTime);
	void addObject();
	void isCollisionPlayer(int indexObject, Player* player, instruments::window s_window);
	void setSoundBuffer(sf::SoundBuffer &buff) { 
		soundBuffer = buff;
		sound.setBuffer(soundBuffer);
	};
private:
	std::vector<Object> objects;
	std::vector<sf::Sprite> sprites;
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
};

