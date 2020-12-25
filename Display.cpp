#include "Display.h"
#include "Color.h"
#include <iostream>
#include <vector>

char convertToVialLabel(int index) {
	return (char)('a' + index);
}

void displayBlank(bool ghost = false) {
	if (ghost) {
		std::cout << "|\033[100m \033[49m";
	} else {
		std::cout << "| ";
	}
};

std::string getColorContent(Color color) {
	switch(color) {
		case ORANGE:
			return "31mO";
		case BLUE:
			return "34mB";
		case RED:
			return "91mR";
		case PINK:
			return "95mP";
		case LIME:
			return "92mL";
		case GRAY:
			return "37mA";
		case CYAN:
			return "96mC";
		case GREEN:
			return "33mG";
		case PURPLE:
			return "94mU";
		case FOREST:
			return "32mF";
		case BROWN:
			return "90mW";
		case YELLOW:
			return "93mY";
		default:
			return "30m?";
	}
}

void displayBall(Color color) { // TODO reference map of Color -> struct
	std::cout << "|\033[1m\033[" << getColorContent(color) << "\033[0m";
};

void displayFlashyBall(Color color) { // TODO reference map of Color -> struct
	std::cout << "|\033[5m\033[1m\033[" << getColorContent(color) << "\033[0m";
};

void displayHorizontalWall(int vialCount) {
	std::cout << "+";
	for (int i = 0; i < vialCount; i++) {
		std::cout << "--";
	}
	std::cout << "-+" << std::endl;
}

void displayVailLabels(int vialCount) {
	std::cout << "|";
	for (int i = 0; i < vialCount; i++) {
		std::cout << " " << convertToVialLabel(i);
	}
	std::cout << " |" << std::endl;
}

void displayBoard(const std::vector < std::vector < Color > > & position) {
	displayHorizontalWall(position.size());
	for(int j = 3; j >= 0; j--) {
		std::cout << "|";
		for (int i = 0; i < position.size(); i++) {
			if (position[i].size() > j) {
				displayBall(position[i][j]);
			} else {
				displayBlank();
			}
		}
		std::cout << "||" << std::endl;
	}
	displayVailLabels(position.size());
	displayHorizontalWall(position.size());
}

void displayFlashyBoard(const std::vector < std::vector < Color > > & position, const std::vector < std::vector < Color > > & nextPosition) {
	std::cout << position[0].size() << nextPosition[0].size() << std::endl;
	displayHorizontalWall(position.size());
	for(int j = 3; j >= 0; j--) {
		std::cout << "|";
		for (int i = 0; i < position.size(); i++) {
			if (position[i].size() > j) {
				if (nextPosition[i].size() < position[i].size() && nextPosition[i].size() == j) {
					displayFlashyBall(position[i][j]);
				} else {
					displayBall(position[i][j]);
				}
			} else {
				displayBlank(nextPosition[i].size() > position[i].size() && position[i].size() == j);
			}
		}
		std::cout << "||" << std::endl;
	}
	displayVailLabels(position.size());
	displayHorizontalWall(position.size());
}