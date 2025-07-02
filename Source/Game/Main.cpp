#include "Math/Math.h"
#include "Core/Random.h"
#include <iostream>

#define NAME "Raymond"

int main() {
	//const float deg =bonzai::radToDeg(bonzai::pi);
	//bonzai::math::min(5, 3);
	//bonzai::math::clamp(2,3,5);
	std::cout << NAME;
	std::cout << "Hello, World!\n";
	std::cout << bonzai::math::pi << std::endl;
	for (int i = 0; i < 10; i++) {
		//std::cout << bonzai::random::getRandomInt(5) << std::endl;
		std::cout << bonzai::random::getRandomFloat() << std::endl;
	}
}