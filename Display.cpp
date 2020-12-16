#include "Display.h"
#include "Color.h"
#include <iostream>
#include <vector>

void displayBlank() {
	std::cout << "| ";
};

void displayBall(Color color) { // TODO reference map of Color -> struct
	std::cout << "|\033[1m\033[";
	switch(color) {
		case ORANGE:
			std::cout << "31" << "m" << "O";
			break;
		case BLUE:
			std::cout << "34" << "m" << "B";
			break;
		case RED:
			std::cout << "91" << "m" << "R";
			break;
		case PINK:
			std::cout << "95" << "m" << "P";
			break;
		case LIME:
			std::cout << "92" << "m" << "L";
			break;
		case GRAY:
			std::cout << "37" << "m" << "A";
			break;
		case CYAN:
			std::cout << "96" << "m" << "C";
			break;
		case GREEN:
			std::cout << "33" << "m" << "G";
			break;
		case PURPLE:
			std::cout << "94" << "m" << "U";
			break;
		case FOREST:
			std::cout << "32" << "m" << "F";
			break;
		case BROWN:
			std::cout << "90" << "m" << "W";
			break;
		case YELLOW:
			std::cout << "93" << "m" << "Y";
			break;
	}
	std::cout << "\033[0m";
};

void displayHorizontalWall(int vialCount) {
	std::cout << "+";
	for (int i = 0; i < vialCount; i++) {
		std::cout << "--";
	}
	std::cout << "-+" << std::endl;
}

void displaySideWall() {
	std::cout << "|";
}

void displayBoard(const std::vector < std::vector < Color > > & position) {
	displayHorizontalWall(position.size());

	for(int j = 3; j >= 0; j--) {
		displaySideWall();
		for (int i = 0; i < position.size(); i++) {
			if (position[i].size() > j) {
				displayBall(position[i][j]);
			} else {
				displayBlank();
			}
		}
		displaySideWall();
		displaySideWall();
		std::cout << std::endl;
	}
	 displayHorizontalWall(position.size());
}