#pragma once
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include <vector>
namespace bonzai {
	class Model {
	public:
		Model() = default;
		Model(const std::vector<vec2>& points, const vec3& color) :
			points(points), 
			color(color) {}

		void draw(class Renderer& renderer,const vec2& position,float rotation, float scale);
	private:
		std::vector<vec2> points;
		vec3 color{ 1,1,1 };

	};

}