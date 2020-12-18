#include <iostream>
#include <vector>
#include "Move.h"

int main() {

	// LEVEL 1
	// std::vector < std::vector < Color > > position {
	// 	{ORANGE, ORANGE, ORANGE},
	// 	{ORANGE}
	// };

	// LEVEL 1
	std::vector < std::vector < Color > > position {
		{ORANGE, BLUE, ORANGE},
		{BLUE, BLUE, ORANGE},
		{},
		{ORANGE, BLUE},
		{RED, RED, RED, RED}
	};

	// // LEVEL 2
	// std::vector < std::vector < Color > > position {
	// 	{BLUE, ORANGE, BLUE, ORANGE},
	// 	{ORANGE, BLUE, ORANGE, BLUE}
	// };


	Move startPosition = Move(position);
	startPosition.explode();

	startPosition.print();
	std::cout << startPosition.nextMoves.size() << std::endl;

	for (int i = 0; i < startPosition.nextMoves.size(); i++) {
		startPosition.nextMoves[i]->print();
	}


	return 0;
}