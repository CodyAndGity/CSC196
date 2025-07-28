#pragma once
#include "../../Engine/Framework/Game.h"
class SpaceGame :  public bonzai::Game {
public:
	enum class GameState {
		INITIALIZING,
		TITLE,
		STARTING_GAME,
		STARTING_LEVEL,
		PLAYING_GAME,
		PLAYER_DEAD,
		GAME_OVER

	};
public:
	SpaceGame() = default;

	// Inherited via Game
	bool initialize() override;

	void update(float deltaTime) override;

	void shutdown() override;

	void draw() override;

private:

	GameState gameState = GameState::INITIALIZING;
	float enemySpawnTimer{ 0.0f };
};