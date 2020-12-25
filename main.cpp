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
	Move* winningPosition = startPosition.explode();
	// startPosition.printExplosion();
	winningPosition->printPath();

	return 0;
}