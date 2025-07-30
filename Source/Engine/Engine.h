#pragma once
#include "Audio/AudioSystem.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include "Renderer/ParticleSystem.h"
#include "Core/time.h"
#include <memory>
namespace bonzai {
	class Renderer;
	class AudioSystem;
	class InputSystem;
	class Engine {
	public:
		Engine() = default;
		bool initialize();
		void update();
		void shutdown();
		void draw();

		Renderer& getRenderer() { return *renderer; }
		AudioSystem& getAudio() { return *audio; }
		InputSystem& getInput() { return *input; }
		ParticleSystem& getParticlesSystem() { return *particles; }
		Time& getTime() { return time; }
	private:
		bonzai::Time time;
		std::unique_ptr<Renderer> renderer;//std::make_unique<bonzai::Renderer>();
		std::unique_ptr<AudioSystem> audio;// = std::make_unique<bonzai::AudioSystem>();
		std::unique_ptr<InputSystem> input;// = std::make_unique<bonzai::InputSystem>();
		std::unique_ptr<ParticleSystem> particles;// = std::make_unique<bonzai::InputSystem>();


	};
	Engine& getEngine();
};