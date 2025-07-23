#include "Scene.h"
#include "../Framework/Actor.h"
#include "../Renderer/Renderer.h"
#include "Actor.h"
#include "../Core/StringHelper.h"
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
		actor->scene = this; // Set the scene pointer for the actor
		actors.push_back(std::move(actor));

	}
	Actor* Scene::getActorByName(const std::string& name){
		for (auto& actor : actors) {
			if (toLower(actor->name) == toLower(name)) {
				return actor.get();
			}
		}
		return nullptr;
	}
}