#pragma once
#include <vector>
#include <memory>
namespace bonzai {

	class Scene {
	public:
		Scene() = default;

		void update(float deltaTime);
		void draw(class Renderer& renderer);

		void AddActor(std::unique_ptr<class Actor> actor);
	private:
		std::vector<std::unique_ptr< class Actor>> actors;


	};
}