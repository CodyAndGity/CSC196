



#include "Framework/Actor.h"
#include "Framework/Scene.h"

#include "Game/SpaceGame.h"
#include "Engine.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Core/Random.h"

#include <iostream>
#include <vector>
#include <memory>





int main(int argc, char* argv[]) {

    // Test getInt() variants
    std::cout << "Integer Functions:\n";
    std::cout << "getInt(): " << bonzai::random::getInt() << "\n";
    std::cout << "getInt(): " << bonzai::random::getInt() << "\n";
    std::cout << "getInt(10): " << bonzai::random::getInt(10) << "\n";
    std::cout << "getInt(10): " << bonzai::random::getInt(10) << "\n";
    std::cout << "getInt(5, 15): " << bonzai::random::getInt(5, 15) << "\n";
    std::cout << "getInt(5, 15): " << bonzai::random::getInt(5, 15) << "\n";
    std::cout << "getInt(-10, 10): " << bonzai::random::getInt(-10, 10) << "\n\n";

    // Test getReal() variants with float
    std::cout << "Float Functions:\n";
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "getReal<float>(): " << bonzai::random::getReal<float>() << "\n";
    std::cout << "getReal<float>(): " << bonzai::random::getReal<float>() << "\n";
    std::cout << "getReal<float>(5.0f): " << bonzai::random::getReal<float>(5.0f) << "\n";
    std::cout << "getReal<float>(2.5f, 7.5f): " << bonzai::random::getReal<float>(2.5f, 7.5f) << "\n";
    std::cout << "getReal<float>(-1.0f, 1.0f): " << bonzai::random::getReal<float>(-1.0f, 1.0f) << "\n\n";

    // Test getReal() variants with double
    std::cout << "Double Functions:\n";
    std::cout << std::setprecision(10);
    std::cout << "getReal<double>(): " << bonzai::random::getReal<double>() << "\n";
    std::cout << "getReal<double>(100.0): " << bonzai::random::getReal<double>(100.0) << "\n";
    std::cout << "getReal<double>(0.0, 2.0): " << bonzai::random::getReal<double>(0.0, 2.0) << "\n\n";

    // Test getBool()
    std::cout << "Boolean Functions:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "getBool(): " << std::boolalpha << bonzai::random::getBool() << "\n";
    }
    std::cout << "\n";
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