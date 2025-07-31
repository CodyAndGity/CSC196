#include "GameData.h"

namespace GameData{
    std::vector<bonzai::vec2> shipPoints = {
           {-10,-5},
           {-5,0},
           {-10,5},
           {10,0 }
    };

    std::vector<bonzai::vec2> enemyPoints = {
        { 10, 0 },
        { -10, -1 },
        { -10, 2 }
    };

    std::vector<bonzai::vec2> projectilePoints = {
        { 3, 0 },
        { 2, -1 },
        { -3, -1 },
        { -2, 0 },
        { -3, 1 },
        { 2, 1 }
	};
    std::vector<bonzai::vec2> starPowerupPoints = {
        { 0, -10 },
        { 2, -2 },
        { 10, 0 },
        { 3, 2 },
        { 6, 10 },
        { 0, 5 },
        { -6, 10 },
        { -3, 2 },
        { -10, 0 },
        { -2, -2 }
	};
}