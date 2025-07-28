#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
void Player::update(float deltaTime){
   
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
    
    if (bonzai::getEngine().getInput().getKeyDown(SDL_SCANCODE_SPACE)) {
        //get scene somehow to add a projectile

    }
    

}
