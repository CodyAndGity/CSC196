#include "Math/Math.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Math/Vector2.h"
#include "Core/time.h"
#include "Input/InputSystem.h"

#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
int main(int argc, char* argv[]) {
	bonzai::Renderer renderer;
	bonzai::Time time;
	renderer.initialize();
	renderer.createWindow("Bonzai Engine", 1280, 1024);

	bonzai::InputSystem input;
	input.initialize();
    SDL_Init(SDL_INIT_VIDEO);

    
    SDL_Event e;
    bool quit = false;

	//create a vector of stars
    std::vector<bonzai::vec2> stars;
    std::vector<bonzai::vec2> speeds;
    for (int i = 0; i < 1000; i++) {
        stars.push_back(bonzai::vec2{ bonzai::random::getRandomFloat() * 1280,bonzai::random::getRandomFloat() * 1024 });
        speeds.push_back(bonzai::vec2 { (bonzai::random::getRandomFloat() * 128*2)-128,(bonzai::random::getRandomFloat() * 102*2)-102 });
        //speeds.push_back(bonzai::vec2 { 200,300});
    };

    // Define a rectangle
    //SDL_FRect greenSquare{ 270, 190, 200, 200 };
    

	//Main loop
    while (!quit) {
		time.tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
		input.update();

        if(input.getKeyDown(SDL_SCANCODE_ESCAPE)) {
            quit = true;
		}
        if(input.getKeyPressed(SDL_SCANCODE_LEFT)) {
            //std::cout << "Left key pressed" << std::endl;
            for (int i = 0; i < stars.size(); i++) {
                stars[i].x = bonzai::random::getRandomFloat() * 1280;
                stars[i].y = bonzai::random::getRandomFloat() * 1024;
				speeds[i].x = (bonzai::random::getRandomFloat() * 128 * 2) - 128;
				speeds[i].y = (bonzai::random::getRandomFloat() * 102 * 2) - 102;
            }
		}
        if (input.getMouseButtonPressed(0)) {
			std::cout << "Left mouse button pressed" << std::endl;
        }
		//bonzai::vec2 mouse=input.getMousePosition();
		//std::cout << "Mouse Position: (" << mouse.x << ", " << mouse.y << ")" << std::endl;
       // bonzai::vec2 speed{ 100.1f,-152.3f };

        renderer.setColor(0, 0, 0);
		renderer.clear();
        for (int i = 0; i < stars.size();i++) {
			stars[i] = stars[i] - speeds[i] * time.getDeltaTime();
            if(stars[i][0] > 1280) {
                stars[i][0] = 0;
			}
            if(stars[i].x < 0) {
                stars[i].x = 1280;
			}
            if (stars[i].y > 1024) {
                stars[i].y = 0;
            }
            if(stars[i].y < 0) {
                stars[i].y = 1024;
			}
           renderer.setColor( bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256), 255);
           renderer.drawPoint(stars[i].x, stars[i].y);
        }

		//renderer.setColor(bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256));
		//renderer.drawLine(bonzai::random::getRandomFloat() * 1280, bonzai::random::getRandomFloat() * 1024, bonzai::random::getRandomFloat() * 1280, bonzai::random::getRandomFloat() * 1024);
        //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set render draw color to green
        //SDL_RenderFillRect(renderer, &greenSquare); // Render the rectangle
   //     for (int i = 0; i < 10; ++i) {
   //        renderer.drawLine( bonzai::random::getRandomInt(1280), bonzai::random::getRandomInt(1024), bonzai::random::getRandomInt(1280), bonzai::random::getRandomInt(1024));
   //         
			////renderer.drawPoint(v.x, v.y);
   //         renderer.setColor( bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256), 255);
   //         for (int j = 0; j < 1; j++) {
   //             renderer.drawPoint( bonzai::random::getRandomInt(1280), bonzai::random::getRandomInt(1024));
   //             renderer.setColor( bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256), 255);
   //         }
   //     }

		renderer.present();
       
    }

	renderer.shutdown();

    return 0;
}