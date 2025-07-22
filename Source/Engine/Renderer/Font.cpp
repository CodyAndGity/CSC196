#include "Font.h"
#include "SDL3_ttf/SDL_ttf.h"
#include <iostream>
namespace bonzai {
	Font::~Font() {
		if (ttfFont != nullptr) {
			TTF_CloseFont(ttfFont);
		}
	}

	bool Font::load(const std::string& name, float fontSize) {
		ttfFont = TTF_OpenFont(name.c_str(), fontSize);
		if (ttfFont == nullptr) {
			std::cerr << "Could not load font: " << name << std::endl;
			return false;
		}

		return true;
	}
}