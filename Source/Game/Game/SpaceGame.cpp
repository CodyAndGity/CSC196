#include "SpaceGame.h"
#include "Framework/Scene.h"
#include "Renderer/Model.h"
#include "Player.h"
#include "Engine.h"

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
    scene->AddActor(std::move(player));
    /*
    for (int i = 0; i < 1; i++) {

        bonzai::Transform transform{ { 1280 / 2,//position
                                         1024 / 2}
        ,0,//rotation
            10 };//size

        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        scene->AddActor(std::move(player));

    }
    */

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
