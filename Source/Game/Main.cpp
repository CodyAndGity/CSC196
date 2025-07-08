#include "Math/Math.h"
#include "Core/Random.h"
#include <iostream>
#include "Renderer/Renderer.h"
#include <SDL3/SDL.h>
#include <Math/Vector2.h>
#include <vector>
#include "Core/time.h"

int main(int argc, char* argv[]) {
	bonzai::Renderer renderer;
	bonzai::Time time;
	renderer.initialize();
	renderer.createWindow("Bonzai Engine", 1280, 1024);
    SDL_Init(SDL_INIT_VIDEO);

    
    SDL_Event e;
    bool quit = false;

	//create a vector of stars
    std::vector<bonzai::vec2> stars;
    std::vector<bonzai::vec2> speeds;
    for (int i = 0; i < 1000; i++) {
        stars.push_back(bonzai::vec2{ bonzai::random::getRandomFloat() * 1280,bonzai::random::getRandomFloat() * 1024 });
        speeds.push_back(bonzai::vec2 { (bonzai::random::getRandomFloat() * 128*2)-128,(bonzai::random::getRandomFloat() * 102*2)-102 });
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