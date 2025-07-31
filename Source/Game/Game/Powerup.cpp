#include "Powerup.h"

void Powerup::update(float deltaTime){
}

void Powerup::onCollision(Actor* other){
	if (other->name == "Player") {
		destroyed = true;
	}
}
