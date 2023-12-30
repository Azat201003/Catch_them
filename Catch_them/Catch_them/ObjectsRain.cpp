#include "ObjectsRain.h"
#include "Collision.h"
#include "setting.h"
#include <random>

ObjectsRain::ObjectsRain(vector<Sprite> aSprites) {
	sprites = aSprites;
	addObject();
}

void ObjectsRain::update(Player *player) {
	for (int i = 0; i < objects.size(); i++) {
		objects.at(i).move(objects.at(i).getSpeed());
		if (objects.at(i).getSprite().getPosition().y - objects.at(i).getSprite().getTextureRect().height / 2 > HEIGHT) {
			auto iter = objects.cbegin();
			objects.erase(iter+i);
			addObject();
		}
		isCollisionPlayer(i, player);
	}
	spawnLine();
}

vector<Object> ObjectsRain::getObjects() {
	return objects;
}

void ObjectsRain::spawnLine() {
	Object endObject = objects.at(objects.size() - 1);
	Pos objectPos(rand() * WIDTH, 0);
	if (endObject.getSprite().getPosition().y > SPAWN_LINE && objects.size() < MAX_NUM_OF_PRICES) {
		addObject();
	}
}

void ObjectsRain::addObject() {
	Sprite sprite = sprites[int(random(0, sprites.size() - 1))];
	Pos objectPos(random(0, WIDTH - sprite.getTextureRect().width), -sprite.getScale().x);
	Object object(sprite, 
				  SPEED_FALLING * (random(0, 100) / 100 + 0.5),
				  objectPos);
	objects.push_back(object);
}

void ObjectsRain::isCollisionPlayer(int indexObject, Player *player) {
	Pos objectPos(objects.at(indexObject).getSprite().getPosition().x,
				  objects.at(indexObject).getSprite().getPosition().y);
	Pos objectSize(objects.at(indexObject).getSprite().getTextureRect().width,
				   objects.at(indexObject).getSprite().getTextureRect().height);

	Pos playerSize(player->getSprite().getTextureRect().width, 
				   player->getSprite().getTextureRect().height);

	Collision objectCol(objectPos, objectSize);
	Collision playerCol(player->getPos(), playerSize);

	if (objectCol.collisionDetect(playerCol)) {
		player->addCoins(1);
		auto iter = objects.cbegin();
		objects.erase(iter + indexObject);
		addObject();
	}
}