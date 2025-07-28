#pragma once
#include <memory>
namespace bonzai {

	class Game {
	public:
		Game() = default;

		virtual bool initialize()=0;
		virtual void update( float deltaTime)=0;
		virtual void shutdown()=0;
		virtual void draw() = 0;

	protected:
		int score{ 0 };
		int lives{ 3 };
		std::unique_ptr<class Scene> scene;
	};
}