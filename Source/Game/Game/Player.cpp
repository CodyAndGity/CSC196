#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "GameData.h"
#include "Framework/Scene.h"
#include "Projectile.h"
#include "Renderer/Model.h"
#include "SpaceGame.h"
#include "Renderer/ParticleSystem.h"
#include "Core/Random.h"
void Player::update(float deltaTime){
    bonzai::Particle particle;
    particle.position = transform.position;
    particle.velocity = { bonzai::random::getReal(-400.0f, 400.0f),bonzai::random::getReal(-400.0f, 400.0f) };
	particle.color = { 1,1,0 };
    particle.lifespan = 1.0f;
	bonzai::getEngine().getParticlesSystem().addParticle(particle);
        
	bool slowDown = false;
    float rotate = 0;
    if (bonzai::getEngine().getInput().getKeyDown(SDL_SCANCODE_A)) {
        rotate = -1;
    }
    if (bonzai::getEngine().getInput().getKeyDown(SDL_SCANCODE_D)) {
        rotate = 1;
    }
    transform.rotation += (rotate *rotateSpeed)* deltaTime;

    float thrust = 0;
    if (bonzai::getEngine().getInput().getKeyDown(SDL_SCANCODE_W)) {
		thrust = 1;
    }
    if (bonzai::getEngine().getInput().getKeyDown(SDL_SCANCODE_S)) {
		slowDown = true;
    }
    bonzai::vec2 direction{ 1,0 };
	bonzai::vec2 velocity = direction.rotate(bonzai::math::degToReg( transform.rotation)) *thrust * speed;
    this->velocity += velocity * deltaTime;

    transform.position.x=bonzai::math::wrap(transform.position.x, 0.0f, (float)bonzai::getEngine().getRenderer().getWidth());
	transform.position.y = bonzai::math::wrap(transform.position.y, 0.0f, (float)bonzai::getEngine().getRenderer().getHeight());
    if (slowDown) {
        this->damping += 0.0005f;
    }
    Actor::update(deltaTime);
    if (slowDown) {
        this->damping -= 0.0005f;
    }
	shootTimer -= deltaTime;
    if (bonzai::getEngine().getInput().getKeyDown(SDL_SCANCODE_SPACE)&& shootTimer <=0) {
		shootTimer = shootCooldown; // Reset the shoot timer
        
        std::shared_ptr<bonzai::Model> model = std::make_shared <bonzai::Model>(GameData::projectilePoints, bonzai::vec3{ 1.0f,1.0f,1.0f });
        bonzai::Transform transform{ this->transform.position,this->transform.rotation, 2 };//size
        std::unique_ptr<Projectile> projectile = std::make_unique<Projectile>(transform, model);
        projectile->damping = 0.0f; 
        projectile->speed = 510.0f; // Set speed to a higher value for faster movement
		projectile->lifespan = 4.0f; // seconds
        projectile->name = "projectile"; // Set the name of the player actor
        projectile->tag = "Player"; // Set the name of the player actor

        scene->addActor(std::move(projectile));

    }
    

}

void Player::onCollision(Actor* other){
    
    if (other->tag == "Enemy") {
        this->destroyed = true;
		dynamic_cast<SpaceGame*>(scene->getGame())->onDeath();
    }
}
