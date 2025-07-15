#include "Math/Math.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Math/Vector2.h"
#include "Core/time.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Math/Vector3.h"


#include <iostream>
#include <vector>
int main(int argc, char* argv[]) {
    // Initialize engine systems
     // create audio system
    bonzai::AudioSystem audio;
	audio.initialize();
   


	// creating renderer system and time system
	bonzai::Renderer renderer;
	bonzai::Time time;
	//initialize renderer and create window
	renderer.initialize();
	renderer.createWindow("Bonzai Engine", 1280, 1024);
	//creating and initializing input system
	bonzai::InputSystem input;
	input.initialize();
    SDL_Init(SDL_INIT_VIDEO);

    std::vector<bonzai::vec2> points = {
        {10,10},
        {-10,10},
        {-10,-10},
        {10,-10 }
    };
    bonzai::Model model{ points, {0,0,1} };
    
    SDL_Event e;
    bool quit = false;

    //test sound
    FMOD::Sound* sound = nullptr;
   // audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);

   // audio->playSound(sound, 0, false, nullptr);
   
   
   //creating sounds

    audio.addSound("bass.wav", "bass");
    audio.addSound("clap.wav", "clap");
    audio.addSound("close-hat.wav", "close-hat");
    audio.addSound("cowbell.wav", "cowbell");
    audio.addSound("open-hat.wav", "open-hat");
    audio.addSound("snare.wav", "snare");
   

    

    


	
    

	//Main loop
    while (!quit) {
		time.tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        //update engine systems
		input.update();
        audio.update();


        if(input.getKeyDown(SDL_SCANCODE_ESCAPE)) {
            quit = true;
		}

       
		

        //draw
        bonzai::vec3 color{0,0,0};

        renderer.setColor(color.r,color.g,color.b);
		renderer.clear();
       

		
		model.draw(renderer,input.getMousePosition(), time.getTime(), 5);
		

		renderer.present();
       
    }

	renderer.shutdown();
	audio.shutdown();

    return 0;
}