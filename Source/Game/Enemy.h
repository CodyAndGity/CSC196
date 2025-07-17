#pragma once
#include "Framework/Actor.h"

class Enenmy : public bonzai::Actor {
public:
	Enenmy() = default;
	Enenmy(const bonzai::Transform& transform, std::shared_ptr<class bonzai::Model> model) :
		bonzai::Actor{ transform, model }
	{}

	void update(float deltaTime) override;



private:


};