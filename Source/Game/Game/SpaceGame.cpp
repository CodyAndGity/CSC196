#include "SpaceGame.h"
#include "Framework/Scene.h"
#include "Renderer/Model.h"
#include "Player.h"
#include "Engine.h"
#include "Enemy.h"
#include "Core/Random.h"
#include "Renderer/Font.h"
#include "Core/time.h"
#include "GameData.h"

bool SpaceGame::initialize(){

	scene = std::make_unique<bonzai::Scene>(this);
	titleFont = std::make_shared<bonzai::Font>();
	titleFont->load("SpaceFont.ttf", 128.0f);

	uiFont = std::make_shared<bonzai::Font>();
	uiFont->load("SpaceFont.ttf", 32.0f);

	//titleText = std::make_unique<bonzai::Text>(titleFont);
	
    std::vector<std::unique_ptr< bonzai::Actor>> actors;
    


    return true;
}

void SpaceGame::update(float deltaTime){
    switch (gameState) {

    case GameState::INITIALIZING:
        gameState = GameState::TITLE;
		break;
    case GameState::TITLE:
        if (bonzai::getEngine().getInput().getKeyPressed(SDL_SCANCODE_SPACE)) {
            gameState = GameState::STARTING_GAME;
        }
		break;
    case GameState::STARTING_GAME:
        score = 0;
        lives = 3;
        
        gameState = GameState::STARTING_LEVEL;
		break;

    case GameState::STARTING_LEVEL:
    {
        std::shared_ptr<bonzai::Model> model = std::make_shared <bonzai::Model>(GameData::shipPoints, bonzai::vec3{ 0,0,1 });
        bonzai::Transform transform{ { (float)bonzai::getEngine().getRenderer().getWidth() * 0.5f,
            (float)bonzai::getEngine().getRenderer().getHeight() * 0.5f}//position
            ,0,//rotation
            4 };//size
        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        player->damping = 0.0001f; // Set damping to a very low value for more responsive movement
        player->speed = 510.0f; // Set speed to a higher value for faster movement
        player->rotateSpeed = 180.0f; // Set rotation speed 
        player->tag = "Player"; // Set the name of the player actor
        player->name = "Player"; // Set the name of the player actor

        scene->addActor(std::move(player));
        gameState = GameState::PLAYING_GAME;
    }
        break;
    case GameState::PLAYING_GAME:
		enemySpawnTimer -= deltaTime;
        if (enemySpawnTimer <= 0.0f) {
            enemySpawnTimer = 4;
            std::shared_ptr<bonzai::Model> enemyModel = std::make_shared <bonzai::Model>(GameData::enemyPoints,
				//random color
                bonzai::vec3{ bonzai::random::getReal(),bonzai::random::getReal(),bonzai::random::getReal() });
            
            float maxX = (float)bonzai::getEngine().getRenderer().getWidth();
            float maxY = (float)bonzai::getEngine().getRenderer().getHeight();

			
            
            float xPos = bonzai::random::getReal(maxX);
            float yPos = bonzai::random::getReal(maxY);
            
            bonzai::vec2 position{ xPos,yPos };

            bonzai::Transform transform{ position, 0, 3 };
            std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
            enemy->speed = 100.0f + bonzai::random::getReal(100.0f,200.0f); // Random speed between 100 and 200

            enemy->damping = 0.0001f;
            enemy->tag = "Enemy";
            scene->addActor(std::move(enemy));
            
        }

        break;
	case GameState::PLAYER_DEAD:
        lives--;
        if(lives <= 0) {
            gameState = GameState::GAME_OVER;
        } else {
            gameState = GameState::STARTING_LEVEL;
		}
        break;
    case GameState::GAME_OVER:
        break;
    }
    scene->update(bonzai::getEngine().getTime().getDeltaTime());

}

void SpaceGame::shutdown(){
}

void SpaceGame::draw(){
    scene->draw(bonzai::getEngine().getRenderer());

}
