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
	// 	{ORANGE, BLUE, ORANGE, BLUE}
	// };

	// LEVEL 3
	std::vector < std::vector < Color > > position {
		{BLUE, ORANGE, RED, BLUE},
		{ORANGE, ORANGE, RED, BLUE},
		{RED, BLUE, ORANGE, RED},
		{},
		{}
	};

	Move startPosition = Move(position);
	Move* winningPosition = NULL;

	for (int timer = 0; timer < 2; timer++) {
		winningPosition = startPosition.explode();

		if (winningPosition != NULL) {
			std::cout << "winning position: " << std::endl;
			winningPosition->print();
			break;
		} else {
			std::cout << "winning position not found!!!" << std::endl;
		}
	}

	// startPosition.print();
	// std::cout << startPosition.nextMoves.size() << std::endl;

	// for (int i = 0; i < startPosition.nextMoves.size(); i++) {
	// 	startPosition.nextMoves[i]->print();
	// }

	return 0;
}