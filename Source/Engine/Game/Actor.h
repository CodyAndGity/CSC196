#pragma once
#include "../Math/Transform.h"
#include "../Renderer/Model.h"
namespace bonzai {
	class Actor {
	public:
		Actor() = default;
		Actor(const Transform& transform, Model* model) :
			transform{ transform },
			model{ model } {
		}

		virtual void update(float deltaTime);
		virtual void draw(class Renderer& renderer);

		Transform& getTransform() { return transform; }
	protected:
		Transform transform;
		Model* model;

	};
}