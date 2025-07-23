#include "Enemy.h"
#include "Engine.h"
#include "Framework/Scene.h"


/// <summary>
/// Updates the enemy's state, moving it towards the player and handling screen wrapping.
/// </summary>
/// <param name="deltaTime">The time elapsed since the last update, used to ensure frame-rate independent movement.</param>
void Enemy::update(float deltaTime){
	

	Actor* player = scene->getActorByName("Player");

    
    if (player) {
      bonzai::vec2 direction{0,0 };
		direction = player->transform.position - transform.position; // Calculate direction towards the player
        
		//if the player is close to the edge, use the screen wrap to get to the player faster
        //left edge x
        if (bonzai::math::fabs(direction.x) > bonzai::math::fabs(player->transform.position.x + bonzai::getEngine().getRenderer().getWidth() - transform.position.x)) {
           
            direction.x = player->transform.position.x + bonzai::getEngine().getRenderer().getWidth() - transform.position.x;
        }
        //bottom edge y
        if (bonzai::math::fabs(direction.y) > bonzai::math::fabs(player->transform.position.y + bonzai::getEngine().getRenderer().getHeight() - transform.position.y)) {
            direction.y = player->transform.position.y + bonzai::getEngine().getRenderer().getHeight() - transform.position.y;
        }
        //right edge x
        if (bonzai::math::fabs(direction.x) > bonzai::math::fabs(player->transform.position.x - bonzai::getEngine().getRenderer().getWidth() - transform.position.x)) {
            direction.x = player->transform.position.x - bonzai::getEngine().getRenderer().getWidth() - transform.position.x;
        }
        //top edge y
        if (bonzai::math::fabs(direction.y) > bonzai::math::fabs(player->transform.position.y - bonzai::getEngine().getRenderer().getHeight() - transform.position.y)) {
            direction.y = player->transform.position.y - bonzai::getEngine().getRenderer().getHeight() - transform.position.y;
        }
		direction = direction.normalized(); // Normalize the direction vector
        transform.rotation = bonzai::math::radToDeg(direction.angle());
    }
    bonzai::vec2 velocity = bonzai::vec2{1,0}.rotate(bonzai::math::degToReg(transform.rotation)) * speed;
    this->velocity += velocity * deltaTime;

    transform.position.x = bonzai::math::wrap(transform.position.x, 0.0f, (float)bonzai::getEngine().getRenderer().getWidth());
    transform.position.y = bonzai::math::wrap(transform.position.y, 0.0f, (float)bonzai::getEngine().getRenderer().getHeight());
    
    Actor::update(deltaTime);
}
