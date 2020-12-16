#include "Move.h"
#include "Display.h"
#include <iostream>
#include <vector>

Move::Move (int content) {

   std::vector<Color> vect1(3, ORANGE);
	std::vector<Color> vect2(3, BLUE);
	std::vector<Color> vect3(3, RED);
	std::vector<Color> vect4(3, PINK);
	std::vector<Color> vect5(4, LIME);
	std::vector<Color> vect6(2, GRAY);
	std::vector<Color> vect7(1, CYAN);
	std::vector<Color> vect8(3, GREEN);
	std::vector<Color> vect9(4, PURPLE);
	std::vector<Color> vect10(4, FOREST);
	std::vector<Color> vect11(3, BROWN);
	std::vector<Color> vect12(2, YELLOW);
	std::vector<Color> vect13;
	std::vector<Color> vect14;

	position.push_back(vect1);
	position.push_back(vect2);
	position.push_back(vect3);
	position.push_back(vect4);
	position.push_back(vect5);
	position.push_back(vect6);
	position.push_back(vect7);
	position.push_back(vect8);
	position.push_back(vect9);
	position.push_back(vect10);
	position.push_back(vect11);
	position.push_back(vect12);
	position.push_back(vect13);
	position.push_back(vect14);
}

void Move::print () {
	displayBoard(position);
}