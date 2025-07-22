#pragma once
#include <SDL3/SDL.h>
#include "Font.h"
#include "Renderer.h"
#include <string>
#include "../Math/Vector3.h"
namespace bonzai {
	class Text {
	public:
		Text() = default;
		Text(Font* font) : font{ font } {}
		~Text();

		bool create(Renderer& renderer, const std::string& text, const vec3& color);
		void draw(Renderer& renderer, float x, float y);

	private:
		Font* font{ nullptr };
		SDL_Texture* texture{ nullptr };
	};


}