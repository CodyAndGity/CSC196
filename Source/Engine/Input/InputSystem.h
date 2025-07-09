#pragma once
#include "../Math/Vector2.h"
#include <vector>
#include <array>
namespace bonzai {
	class InputSystem {
	public:
		InputSystem() = default;
		bool initialize();
		void shutdown();

		void update();

		//keyboard input
		bool getKeyDown(uint8_t key) const { return keyboardState[key]; }
		bool getPreviousKeyDown ( uint8_t key) const { return previousKeyboardState[key];}
		bool getKeyPressed(uint8_t key) const { return !previousKeyboardState[key] && keyboardState[key]; }
		bool getKeyReleased(uint8_t key) const { return previousKeyboardState[key] && !keyboardState[key]; }

		const vec2& getMousePosition() const { return mousePosition; }
		const vec2& getPreviousMousePosition() const { return previousMousePosition; }

		//Mouse input
		bool getMouseButtonDown(uint8_t button) const { assert (button < 3); return mouseButtonState[button]; }
		bool getPreviousMouseButtonDown(uint8_t button) const { assert (button < 3); return previousMouseButtonState[button]; }
		bool getMouseButtonPressed(uint8_t button) const { assert (button < 3); return mouseButtonState[button] &&!previousMouseButtonState[button]; }
		bool getMouseButtonReleased(uint8_t button) const { assert (button < 3); return !mouseButtonState[button] &&previousMouseButtonState[button]; }
	private:
		std::vector<bool> keyboardState;
		std::vector<bool> previousKeyboardState;

		vec2 mousePosition;
		vec2 previousMousePosition;

		std::array<bool,3> mouseButtonState = { false, false, false };
		std::array<bool, 3> previousMouseButtonState = { false, false, false };
	};

}