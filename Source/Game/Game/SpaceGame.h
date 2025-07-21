#pragma once
#include "../../Engine/Framework/Game.h"
class SpaceGame :  public bonzai::Game {

public:
	SpaceGame() = default;

	// Inherited via Game
	bool initialize() override;

	void update() override;

	void shutdown() override;

	void draw() override;

private:



};