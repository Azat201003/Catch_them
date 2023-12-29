#include "ObjectsRain.h"
#include "setting.h"
#include <random>

ObjectsRain::ObjectsRain(vector<Texture> aTextures) {
	textures = aTextures;
	Pos objectPos(rand() * WIDTH, 0);
	Object object(textures[int(rand()*textures.size())], SPEED * (rand() + 0.5),  objectPos);
	objects.push_back(object);
}

void ObjectsRain::update() {
	for (int i = 0; i < objects.size(); i++) {
		if (objects.at(i).getPos().y - objects.at(i).getTexture().getSize().y / 2 > HEIGHT) {
			delete& objects.at(i);
			Pos objectPos(rand() * WIDTH, 0);
			Object object(textures[int(rand() * textures.size())], SPEED * (rand() + 0.5), objectPos);
			objects.push_back(object);
		}
	}
	Object endObject = objects.at(objects.size() - 1);
	Pos objectPos(rand() * WIDTH, 0);
	if (endObject.getPos().y * endObject.getSpeed() > SPAWN_LINE && objects.size() < MAX_NUM_OF_PRICES) {
		Pos objectPos(rand() * WIDTH, 0);
		Object object(textures[int(rand() * textures.size())], SPEED * (rand() + 0.5), objectPos);
		objects.push_back(object);
	}
}
