#include "Move.h"
#include "Display.h"
#include <iostream>
#include <vector>

Move::Move (std::vector < std::vector < Color > > startingPosition) {
   position = startingPosition;
	index = 0;
	setScore();
	lastMove = NULL;
}

void Move::setScore () {
	score = 0;
	int volume = 0;
	int empties = 0;


	// add consecutives scoring component
	for(std::vector< std::vector < Color > >::const_iterator it = position.begin(); it != position.end(); ++it) {
		for(std::vector < Color >::const_iterator jt = it->begin(); jt != it->end(); ++jt) { // this will skip empty vectors
			if (jt != it->begin() && *jt != *std::prev(jt)) { // this will skip first element logic
				score += 1; // add a point for each nonconsecutive color streak
			}
		}

		// calculate values for empties scoring component
		volume += it->size();
		if (it->size() == 0) {
			empties++;
		}
	}

	// add empties scoring component
	score += ((4 * position.size() - volume) / 4) - empties; // add a point for extra vials used
}

void Move::print () {
	std::cout << "MOVE: " << index << std::endl;
	std::cout << "SCORE: " << score << std::endl;
	std::cout << "POSITION: " << std::endl;
	displayBoard(position);
}