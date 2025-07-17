#include "Scene.h"
#include "../Framework/Actor.h"
#include "../Renderer/Renderer.h"
namespace bonzai {
	void Scene::update(float deltaTime) {
		for (auto& actor : actors) {
			actor->update(deltaTime);
		}

	}
	void Scene::draw(class Renderer& renderer) {
		for (auto& actor : actors) {
			actor->draw(renderer);
		}
	}
	void Scene::AddActor(std::unique_ptr<class Actor> actor)	{
		actors.push_back(std::move(actor));

	}
}