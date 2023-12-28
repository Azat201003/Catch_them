#include "ObjectsRain.h"
#include "setting.h"
#include <random>

ObjectsRain::ObjectsRain(vector<Texture> aTextures) {
	textures = aTextures;
	Object object(textures[int(rand()*textures.size())]);
	objects.push_back(object);
}

void ObjectsRain::update() {
	for (int i = 0; i < objects.size(); i++) {
		if (objects.at(i).getPos().y - objects.at(i).getTexture().getSize().y / 2 > HEIGHT) {
			Object object(textures[int(rand() * textures.size())]);
			delete &objects.at(i);
			objects.push_back(object);
		}
	}
	Object endObject = objects.at(objects.size() - 1);
	if (endObject.getPos().y * endObject.getSpeed() > SPAWN_LINE)
}
