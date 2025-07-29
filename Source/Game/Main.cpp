



#include "Framework/Actor.h"
#include "Framework/Scene.h"

#include "Game/SpaceGame.h"
#include "Engine.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

#include <iostream>
#include <vector>
#include <memory>





int main(int argc, char* argv[]) {
  
    // Initialize engine systems
	bonzai::getEngine().initialize();
   
    //initailize game
	std::unique_ptr<bonzai::Game> game = std::make_unique<SpaceGame>();
	game->initialize();
	

    
    SDL_Event e;
    bool quit = false;

    //test sound
    
	std::shared_ptr<bonzai::Font> font = std::make_shared<bonzai::Font>();
    font->load("radiospacebitmap.ttf", 20);
   
    bonzai::Text* text = new bonzai:: Text(font);
    text->create(bonzai::getEngine().getRenderer(), "Press space to start", bonzai::vec3{ 1, 1, 1 });

	//Main loop
    while (!quit) {
		
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        //update engine systems
        bonzai::getEngine().update();
        //update game
        game->update(bonzai::getEngine().getTime().getDeltaTime());
        
        if(bonzai::getEngine().getInput().getKeyDown(SDL_SCANCODE_ESCAPE)) {
            quit = true;
		}



       
        //draw
        bonzai::vec3 color{0,0,0};
        bonzai::getEngine().getRenderer().setColor(color.r,color.g,color.b);
        bonzai::getEngine().getRenderer().clear();
       

		
		
		game->draw();
        text->draw(bonzai::getEngine().getRenderer(), 40.0f, 40.0f);
        bonzai::getEngine().getRenderer().present();
       
    }
	
    bonzai::getEngine().shutdown();
    game->shutdown();
	game.release();

    return 0;
}