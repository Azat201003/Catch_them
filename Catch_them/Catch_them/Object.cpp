#include "Object.h"

Object::Object(Texture aTexture, int aSpeed, Pos aPos) {
	texture = aTexture;
}

Pos Object::getPos() {
	return pos;
}

Texture Object::getTexture() {
	return texture;
}

int Object::getSpeed() {
	return speed;
}