#include "Enemy.h"
#include "Engine.h"
#include "Framework/Scene.h"
void Enemy::update(float deltaTime){
	

	Actor* player = scene->getActorByName("Player");
    if (player) {
      bonzai::vec2 direction{0,0 };
		direction = player->transform.position - transform.position; // Calculate direction towards the player
		direction = direction.normalized(); // Normalize the direction vector
        transform.rotation = bonzai::math::radToDeg(direction.angle());
    }
    bonzai::vec2 velocity = bonzai::vec2{1,0}.rotate(bonzai::math::degToReg(transform.rotation)) * speed;
    this->velocity += velocity * deltaTime;

    transform.position.x = bonzai::math::wrap(transform.position.x, 0.0f, (float)bonzai::getEngine().getRenderer().getWidth());
    transform.position.y = bonzai::math::wrap(transform.position.y, 0.0f, (float)bonzai::getEngine().getRenderer().getHeight());
    
    Actor::update(deltaTime);
}
