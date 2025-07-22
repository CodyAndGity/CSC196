#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
void Player::update(float deltaTime){
   
        float speed = 510;
		float rotateSpeed = 180.0f;
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
    bonzai::vec2 direction{ 1,0 };
	bonzai::vec2 velocity = direction.rotate(bonzai::math::degToReg( transform.rotation)) *thrust * speed;
    this->velocity += velocity * deltaTime;

	Actor::update(deltaTime);
        /*
        if (bonzai::getEngine().getInput().getKeyDown(SDL_SCANCODE_S)) {
            direction.y = 1;
        }
        if (bonzai::getEngine().getInput().getKeyDown(SDL_SCANCODE_A)) {
            direction.x = -1;
        }
        if (bonzai::getEngine().getInput().getKeyDown(SDL_SCANCODE_D)) {
            direction.x = 1;
        }
        if (direction.lengthSquared() > 0) {
            direction = direction.normalized();
        }*/
    

}
