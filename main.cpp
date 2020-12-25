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
	// std::vector < std::vector < Color > > position {
	// 	{BLUE, RED, ORANGE, ORANGE},
	// 	{BLUE, RED, BLUE, RED},
	// 	{ORANGE, BLUE, RED, ORANGE},
	// 	{},
	// 	{}
	// };

	// // LEVEL 10
	// std::vector < std::vector < Color > > position {
	// 	{PINK, BLUE, LIME, BLUE},
	// 	{ORANGE, GRAY, PINK, RED},
	// 	{BLUE, CYAN, CYAN, LIME},
	// 	{PINK, ORANGE, ORANGE, LIME},
	// 	{GRAY, GRAY, LIME, RED},
	// 	{BLUE, RED, CYAN, CYAN},
	// 	{RED, PINK, ORANGE, GRAY},
	// 	{},
	// 	{}
	// };

	// LEVEL 1341
	std::vector < std::vector < Color > > position {
		{CYAN, LIME, FOREST, GRAY},
		{ORANGE, FOREST, YELLOW, BLUE},
		{LIME, BLUE, PINK, YELLOW},
		{ORANGE, FOREST, GRAY, RED},
		{PINK, GREEN, BROWN, BLUE},
		{ORANGE, RED, BROWN, CYAN},
		{BROWN, LIME, RED, ORANGE},
		{BLUE, GRAY, FOREST, PURPLE},
		{PURPLE, CYAN, LIME, LIME},
		{PURPLE, PINK, LIME, CYAN},
		{RED, YELLOW, PINK, PURPLE},
		{BROWN, YELLOW, LIME, GRAY},
		{},
		{}
	};

	Move startPosition = Move(position);
	Move* winningPosition = startPosition.explode();
	// startPosition.printExplosion();
	winningPosition->printPath();

	return 0;
}