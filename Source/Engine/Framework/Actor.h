#pragma once

#include "../Math/Transform.h"
#include "../Renderer/Model.h"
#include <string>
#include <memory>
namespace bonzai {
	class Actor {
	public:
		std::string name;
		std::string tag;
		Transform transform;
		std::shared_ptr<Model> model;
		vec2 velocity{ 0,0 };

	public:
		Actor() = default;
		Actor(const Transform& transform, std::shared_ptr<class Model> model) :
			transform{ transform },
			model{ model } {
		}

		virtual void update(float deltaTime);
		virtual void draw(class Renderer& renderer);

		Transform& getTransform() { return transform; }
	protected:
		


	};
}