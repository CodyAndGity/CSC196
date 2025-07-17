#pragma once
#include "../../Engine/Framework/Actor.h"

class Player : public bonzai::Actor {
public:
	Player() = default;
	Player(const bonzai::Transform& transform, std::shared_ptr<class bonzai::Model> model) :
		bonzai::Actor{ transform, model }
	{}

	void update(float deltaTime) override;



private:


};