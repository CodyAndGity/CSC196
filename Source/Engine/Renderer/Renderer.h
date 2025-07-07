#pragma once
#include <SDL3/SDL.h>
#include <iostream>

namespace bonzai {
	class Renderer {
	public:
		Renderer() = default;

		bool initialize();
		bool createWindow(const std::string& name, int width, int height);

		void clear();
		void present();
		void shutdown();

		void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
		void drawLine(float x1, float y1, float x2, float y2);
		void drawPoint(float x1, float y1);
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;

		
	};
}