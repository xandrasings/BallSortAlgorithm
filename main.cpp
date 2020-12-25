#include <iostream>
#include <vector>
#include "Move.h"

int main() {

	// // LEVEL 1
	// std::vector < std::vector < Color > > position {
	// 	{ORANGE, ORANGE, ORANGE},
	// 	{ORANGE}
	// };

	// // LEVEL 2
	// std::vector < std::vector < Color > > position {
	// 	{BLUE, ORANGE, BLUE, ORANGE},
	// 	{ORANGE, BLUE, ORANGE, BLUE},
	// 	{}
	// };

	// // LEVEL 3
	// std::vector < std::vector < Color > > position {
	// 	{BLUE, ORANGE, RED, BLUE},
	// 	{ORANGE, ORANGE, RED, BLUE},
	// 	{RED, BLUE, ORANGE, RED},
	// 	{},
	// 	{}
	// };

	// LEVEL 4
	std::vector < std::vector < Color > > position {
		{BLUE, RED, ORANGE, ORANGE},
		{BLUE, RED, BLUE, RED},
		{ORANGE, BLUE, RED, ORANGE},
		{},
		{}
	};

	Move startPosition = Move(position);
	Move* winningPosition = NULL;

	for (int timer = 0; timer < 12; timer++) {
		winningPosition = startPosition.explode();

		if (winningPosition != NULL) {
			break;
		}
	};

	startPosition.printExplosion();

	if (winningPosition != NULL) {
		std::cout << "winning position: " << std::endl;
		winningPosition->print();
	} else {
		std::cout << "winning position not found!!!" << std::endl;
	}

	return 0;
}