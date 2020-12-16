#include <iostream>
#include <vector>
#include "Move.h"

int main() {

	// std::vector < std::vector < Color > > position {
	// 	{RED, RED, RED},
	// 	{BLUE, BLUE, BLUE},
	// 	{RED, BLUE}
	// };

	// std::vector < std::vector < Color > > position {
	// 	{},
	// 	{ORANGE},
	// 	{BLUE, BLUE, BLUE, BLUE},
	// 	{RED, RED, RED, RED},
	// 	{PINK},
	// 	{GREEN, GREEN, LIME, GREEN},
	// 	{GRAY, GRAY},
	// 	{CYAN, CYAN, CYAN, CYAN},
	// 	{GREEN, GREEN, GREEN, GREEN},
	// 	{PURPLE, PURPLE, PURPLE, PURPLE},
	// 	{FOREST, FOREST, FOREST, FOREST},
	// 	{BROWN, BROWN, BROWN, BROWN},
	// 	{YELLOW, YELLOW, YELLOW, YELLOW},
	// 	{}
	// };

	std::vector < std::vector < Color > > position {
		{},
		{ORANGE, ORANGE, ORANGE, ORANGE},
		{BLUE, BLUE, BLUE, BLUE},
		{RED, RED, RED, RED},
		{PINK, PINK, PINK, PINK},
		{GREEN, GREEN, GREEN, GREEN},
		{GRAY, GRAY, GRAY, GRAY},
		{CYAN, CYAN, CYAN, CYAN},
		{GREEN, GREEN, GREEN, GREEN},
		{PURPLE, PURPLE, PURPLE, PURPLE},
		{FOREST, FOREST, FOREST, FOREST},
		{BROWN, BROWN, BROWN, BROWN},
		{YELLOW, YELLOW, YELLOW, YELLOW},
		{}
	};

	Move startPosition(position);
	startPosition.print();

	return 0;
}