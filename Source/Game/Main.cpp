#include "Math/Math.h"
#include "Core/Random.h"
#include <iostream>
#include "Renderer/Renderer.h"
#include <SDL3/SDL.h>
#include <Math/Vector2.h>

int main(int argc, char* argv[]) {
	bonzai::Renderer renderer;
	renderer.initialize();
	renderer.createWindow("Bonzai Engine", 1280, 1024);
    SDL_Init(SDL_INIT_VIDEO);

    
    SDL_Event e;
    bool quit = false;
    vec2 v(30, 40);
    // Define a rectangle
    //SDL_FRect greenSquare{ 270, 190, 200, 200 };
    


    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        renderer.setColor(0, 0, 0);
		renderer.clear();

		//renderer.setColor(bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256));
		//renderer.drawLine(bonzai::random::getRandomFloat() * 1280, bonzai::random::getRandomFloat() * 1024, bonzai::random::getRandomFloat() * 1280, bonzai::random::getRandomFloat() * 1024);
        //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set render draw color to green
        //SDL_RenderFillRect(renderer, &greenSquare); // Render the rectangle
        for (int i = 0; i < 10; ++i) {
           renderer.drawLine( bonzai::random::getRandomInt(1280), bonzai::random::getRandomInt(1024), bonzai::random::getRandomInt(1280), bonzai::random::getRandomInt(1024));
            
			//renderer.drawPoint(v.x, v.y);
            renderer.setColor( bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256), 255);
            for (int j = 0; j < 1; j++) {
                renderer.drawPoint( bonzai::random::getRandomInt(1280), bonzai::random::getRandomInt(1024));
                renderer.setColor( bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256), bonzai::random::getRandomInt(256), 255);
            }

        }
		renderer.present();
       
    }

	renderer.shutdown();

    return 0;
}