#include "Math/Math.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Math/Vector2.h"
#include "Core/time.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Math/Vector3.h"
#include "Math/Transform.h"
#include "Framework/Actor.h"
#include "Game/Player.h"
#include "Framework/Scene.h"

#include <iostream>
#include <vector>
#include <memory>
int main(int argc, char* argv[]) {
    // Initialize engine systems
     // create audio system
	std::unique_ptr< bonzai::AudioSystem> audio= std::make_unique<bonzai::AudioSystem>() ;

	audio->initialize();

	// creating renderer system and time system
	std::unique_ptr<bonzai::Renderer> renderer = std::make_unique<bonzai::Renderer>();
	bonzai::Time time;
	//initialize renderer and create window
	renderer->initialize();
	renderer->createWindow("Bonzai Engine", 1280, 1024);
	//creating and initializing input system
	std::unique_ptr< bonzai::InputSystem> input=std::make_unique<bonzai::InputSystem>();
	input->initialize();
    SDL_Init(SDL_INIT_VIDEO);

    std::vector<bonzai::vec2> points = {
        {-10,-5},
        {-5,0},
        {-10,5},
        {10,0 }
    };

	bonzai::Scene scene;
    std::shared_ptr<bonzai::Model> model = std::make_shared <bonzai::Model>(points, bonzai::vec3{ 0,0,1 });
   //bonzai::Model* model=new bonzai::Model{ points, {0,0,1} };
	std::vector<std::unique_ptr< bonzai::Actor>> actors;
    for (int i = 0; i < 1; i++) {

		bonzai::Transform transform{ { 1280/2,//position
                                         1024/2}
        ,0,//rotation
            1};//size

        std::unique_ptr<Player> player= std::make_unique<Player>( transform, model );
		scene.AddActor(std::move(player));

    }
    SDL_Event e;
    bool quit = false;

    //test sound
    FMOD::Sound* sound = nullptr;
  
    
   

    

	//Main loop
    while (!quit) {
		time.tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        if(input->getKeyDown(SDL_SCANCODE_ESCAPE)) {
            quit = true;
		}

        //update engine systems
		input->update();
        audio->update();



        bonzai::vec2 direction{ 0,0 };
        for (auto& actor : actors) {
            actor->getTransform().rotation += bonzai::math::degToReg(time.getTime() * 2) * time.getDeltaTime();

            int speed =  510;
            if (input->getKeyDown(SDL_SCANCODE_W)) {
                direction.y = -1;// speed* time.getDeltaTime();
            }
            if (input->getKeyDown(SDL_SCANCODE_S)) {
                direction.y = 1;// speed* time.getDeltaTime();
            }
            if (input->getKeyDown(SDL_SCANCODE_A)) {
                direction.x = -1;// speed* time.getDeltaTime();
            }
            if (input->getKeyDown(SDL_SCANCODE_D)) {
                direction.x = 1;// speed* time.getDeltaTime();
            }
            if (direction.lengthSquared() > 0) {
                direction = direction.normalized();
            }
            actor->getTransform().position += (direction * speed) * time.getDeltaTime();
        }

        //draw
        bonzai::vec3 color{0,0,0};

        renderer->setColor(color.r,color.g,color.b);
		renderer->clear();
       

		
		scene.draw(*renderer);
        
		

		renderer->present();
       
    }
	
	renderer->shutdown();
	audio->shutdown();
	input->shutdown();

    return 0;
}