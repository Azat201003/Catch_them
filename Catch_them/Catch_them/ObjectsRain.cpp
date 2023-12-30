#include "ObjectsRain.h"
#include "setting.h"
#include <random>

ObjectsRain::ObjectsRain(vector<Sprite> aSprites) {
	sprites = aSprites;
	addObject();
}

void ObjectsRain::update() {
	for (int i = 0; i < objects.size(); i++) {
		objects.at(i).move(objects.at(i).getSpeed());
		if (objects.at(i).getSprite().getPosition().y - objects.at(i).getSprite().getTextureRect().height / 2 > HEIGHT) {
			auto iter = objects.cbegin();
			objects.erase(iter+i);
			addObject();
		}
	}
	spawnLine();
}

vector<Object> ObjectsRain::getObjects() {
	return objects;
}

void ObjectsRain::spawnLine() {
	Object endObject = objects.at(objects.size() - 1);
	Pos objectPos(rand() * WIDTH, 0);
	if (endObject.getSprite().getPosition().y * (SPEED / endObject.getSpeed()) > SPAWN_LINE && objects.size() < MAX_NUM_OF_PRICES) {
		addObject();
	}
}

void ObjectsRain::addObject() {
	Pos objectPos(random(0, WIDTH), 0);
	Object object(sprites[int(random(0, sprites.size()-1))], 
				  SPEED_FALLING * (instruments::random(-0.5, 0.5)), 
				  objectPos);
	objects.push_back(object);
}