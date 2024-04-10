#include "ObjectsRain.h"
#include "Collision.h"
#include "setting.h"
#include <random>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

ObjectsRain::ObjectsRain(std::vector<sf::Sprite> aSprites) {
	sprites = aSprites;
	addObject();
}

void ObjectsRain::update(Player *player, float wasTime, instruments::window& s_window) {
	for (int i = 0; i < objects.size(); i++) {
		objects.at(i).move(objects.at(i).getSpeed() * wasTime);
		if (objects.at(i).getSprite().getPosition().y - objects.at(i).getSprite().getTextureRect().height / 2 > setting::HEIGHT) {
			sf::Sprite sprite = objects.at(i).getSprite();
			instruments::Pos objectPos(instruments::random(0, setting::WIDTH - sprite.getTextureRect().width), -sprite.getTextureRect().height);
			objects.at(i).setPosition(objectPos);
			objects.at(i).setSpeed(setting::SPEED_FALLING * (instruments::random(0, 100) / 100 + 0.5));

			player->kick(1, s_window);
		}
		spawnLine(i, wasTime);
		isCollisionPlayer(i, player, s_window);
	}
}

std::vector<Object> ObjectsRain::getObjects() {
	return objects;
}

void ObjectsRain::spawnLine(int i, float wasTime) {
	Object object = objects.at(i);
	if (object.getSprite().getPosition().y > setting::SPAWN_LINE && objects.size() < setting::MAX_NUM_OF_PRICES) {
		addObject(); 
	}
}

void ObjectsRain::addObject() {
	sf::Sprite sprite = sprites[int(instruments::random(0, sprites.size() - 1))];
	instruments::Pos objectPos(instruments::random(0, setting::WIDTH - sprite.getTextureRect().width), -sprite.getTextureRect().height);
	Object object(sprite,
				  setting::SPEED_FALLING * (instruments::random(0, 100) / 100 + 0.5),
				  objectPos);
	objects.push_back(object);
}

void ObjectsRain::isCollisionPlayer(int indexObject, Player *player, instruments::window s_window) {
	if (s_window == instruments::window::game) {
		instruments::Pos objectPos(objects.at(indexObject).getSprite().getPosition().x,
			objects.at(indexObject).getSprite().getPosition().y);
		instruments::Pos objectSize(objects.at(indexObject).getSprite().getTextureRect().width,
			objects.at(indexObject).getSprite().getTextureRect().height);

		instruments::Pos playerSize(player->getSprite().getTextureRect().width,
			player->getSprite().getTextureRect().height);

		Collision objectCol(objectPos, objectSize);
		Collision playerCol(player->getPos(), playerSize);

		if (objectCol.collisionDetect(playerCol)) {
			player->addCoins(1, s_window);
			sound.play();
			auto iter = objects.cbegin();
			objects.erase(iter + indexObject);
			addObject();
		}
	}
}