#pragma once
#include <vector>
#include <memory>
#include <string>
namespace bonzai {
	class Actor;


	class Scene {
	public:
		Scene() = default;

		void update(float deltaTime);
		void draw(class Renderer& renderer);

		void AddActor(std::unique_ptr< Actor> actor);

		 Actor* getActorByName(const std::string& name);
	private:
		std::vector<std::unique_ptr<  Actor>> actors;


	};
}