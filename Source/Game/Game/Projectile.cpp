#include "Projectile.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include "Player.h"
#include "Core/Random.h"

void Projectile::update(float deltaTime) {


    


    
    bonzai::vec2 velocity = bonzai::vec2{ 1,0 }.rotate(bonzai::math::degToRad(transform.rotation)) * speed;
	this->velocity = velocity ;

    transform.position.x = bonzai::math::wrap(transform.position.x, 0.0f, (float)bonzai::getEngine().getRenderer().getWidth());
    transform.position.y = bonzai::math::wrap(transform.position.y, 0.0f, (float)bonzai::getEngine().getRenderer().getHeight());
    
    float angle = transform.rotation + bonzai::random::getReal(-30.0f, 30.0f);
    bonzai::vec2 pVelocity=bonzai::vec2{ 1,0 }.rotate(bonzai::math::degToRad(angle));
    pVelocity *= bonzai::random::getReal(80.0f, 150.0f);
    bonzai::Particle particle;
    particle.position = transform.position;
    particle.velocity = pVelocity;
    particle.color = { 1,1,1 };
    particle.lifespan = bonzai::random::getReal(0.3f,0.6f);
    bonzai::getEngine().getParticlesSystem().addParticle(particle);
    Actor::update(deltaTime);
}

void Projectile::onCollision(Actor* other){
    if (other->tag !=tag) {
        this->destroyed = true;
        
	}
}
