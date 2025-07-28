#pragma once
#include "Framework/Actor.h"

class Enemy : public bonzai::Actor {
public:
	float speed{ 200 };
	Enemy() = default;
	Enemy(const bonzai::Transform& transform, std::shared_ptr<class bonzai::Model> model) :
		bonzai::Actor{ transform, model }
	{}

	void update(float deltaTime) override;



private:


};