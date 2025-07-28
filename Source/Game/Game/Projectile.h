#pragma once
//copy over enemy but make it projectile

#include "Framework/Actor.h"

class Projectile : public bonzai::Actor {
public:
	float speed{ 200 };
	Projectile() = default;
	Projectile(const bonzai::Transform& transform, std::shared_ptr<class bonzai::Model> model) :
		bonzai::Actor{ transform, model }
	{}

	void update(float deltaTime) override;



private:


};