#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
void Player::update(float deltaTime){
    bonzai::vec2 direction{ 0,0 };
   
        transform.rotation += bonzai::math::degToReg(bonzai::getEngine().getTime().getTime() * 2) * bonzai::getEngine().getTime().getDeltaTime();

        int speed = 510;
        if (bonzai::getEngine().getInput().getKeyDown(SDL_SCANCODE_W)) {
            direction.y = -1;
        }
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
        }
        transform.position += (direction * (float)speed) * deltaTime;
    

}
