#include "Engine.h"
#include "Renderer/Renderer.h"
#include "Audio/AudioSystem.h"
#include "Input/InputSystem.h"
namespace bonzai {
	Engine& getEngine(){
		static Engine engine;
		return engine;
	}
	bool Engine::initialize() {
		renderer = std::make_unique<bonzai::Renderer>();
		//initialize renderer and create window
		renderer->initialize();
		renderer->createWindow("Bonzai Engine", 1280, 1024);

		input = std::make_unique<bonzai::InputSystem>();
		input->initialize();

		audio = std::make_unique<bonzai::AudioSystem>();
		audio->initialize();
		return true;
	}
	void Engine::update() {
		time.tick();
		input->update();
		audio->update();
	}
	void Engine::shutdown() {
		audio->shutdown();
		input->shutdown();
		renderer->shutdown();
	}

	void Engine::draw(){

	}




}