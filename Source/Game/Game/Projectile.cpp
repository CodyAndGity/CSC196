#include "Projectile.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include "Player.h"

void Projectile::update(float deltaTime) {


    Player* player = scene->getActorByName<Player>("Player");


    
    bonzai::vec2 velocity = bonzai::vec2{ 1,0 }.rotate(bonzai::math::degToReg(transform.rotation)) * speed;
    this->velocity = velocity;

    transform.position.x = bonzai::math::wrap(transform.position.x, 0.0f, (float)bonzai::getEngine().getRenderer().getWidth());
    transform.position.y = bonzai::math::wrap(transform.position.y, 0.0f, (float)bonzai::getEngine().getRenderer().getHeight());

    Actor::update(deltaTime);
}

void Projectile::onCollision(Actor* other){
    if (other->tag == "Enemy") {
        this->destroyed = true;
        
	}
}
