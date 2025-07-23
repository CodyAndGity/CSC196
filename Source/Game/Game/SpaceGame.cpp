#include "SpaceGame.h"
#include "Framework/Scene.h"
#include "Renderer/Model.h"
#include "Player.h"
#include "Engine.h"
#include "Enemy.h"
#include "Core/Random.h"

#include "Core/time.h"


bool SpaceGame::initialize(){

	scene = std::make_unique<bonzai::Scene>();
    std::vector<bonzai::vec2> points = {
        {-10,-5},
        {-5,0},
        {-10,5},
        {10,0 }
    };

    std::shared_ptr<bonzai::Model> model = std::make_shared <bonzai::Model>(points, bonzai::vec3{ 0,0,1 });
   
    std::vector<std::unique_ptr< bonzai::Actor>> actors;
    bonzai::Transform transform{ { (float)bonzai::getEngine().getRenderer().getWidth() *0.5f,
                                         (float)bonzai::getEngine().getRenderer().getHeight() * 0.5f}//position
        ,0,//rotation
            4 };//size

    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
	player->damping = 0.0001f; // Set damping to a very low value for more responsive movement
	player->speed = 510.0f; // Set speed to a higher value for faster movement
	player->rotateSpeed = 180.0f; // Set rotation speed 
	player->name = "Player"; // Set the name of the player actor

    scene->AddActor(std::move(player));
    points = {
        { 10, 0 },
{ -10, -1 },
{ -10, 2 }
	};

    for (int i = 0; i < 100; i++) {
    std::shared_ptr<bonzai::Model> enemyModel = std::make_shared <bonzai::Model>(points, 
        bonzai::vec3{ bonzai::random::getRandomFloat(),bonzai::random::getRandomFloat(),bonzai::random::getRandomFloat() });
        bonzai::Transform transform{ bonzai::vec2{ bonzai::random::getRandomFloat() * bonzai::getEngine().getRenderer().getWidth()
            , bonzai::random::getRandomFloat() * bonzai::getEngine().getRenderer().getHeight() }, 0, 3 };
        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
		enemy->speed = 100.0f + bonzai::random::getRandomFloat() * 100.0f; // Random speed between 100 and 200
		enemy->damping = 0.0001f; 
        scene->AddActor(std::move(enemy));
    }
    

    return true;
}

void SpaceGame::update(){
    scene->update(bonzai::getEngine().getTime().getDeltaTime());

}

void SpaceGame::shutdown(){
}

void SpaceGame::draw(){
    scene->draw(bonzai::getEngine().getRenderer());

}
