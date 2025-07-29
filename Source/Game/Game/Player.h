#pragma once
#include "../../Engine/Framework/Actor.h"

class Player : public bonzai::Actor {
public:
	float speed{ 0 };
	float rotateSpeed{ 0 };
	float shootCooldown{ 0.2f }; // seconds between shots
	float shootTimer{ 0.0f }; // timer to track shooting cooldown
public:
	Player() = default;
	Player(const bonzai::Transform& transform, std::shared_ptr<class bonzai::Model> model) :
		bonzai::Actor{ transform, model }
	{}

	void update(float deltaTime) override;
	// Inherited via Actor
	void onCollision(Actor* other) override;



private:




};