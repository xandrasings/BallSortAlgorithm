#include "Move.h"
#include "Display.h"
#include <iostream>
#include <vector>

// generate a Move object from a starting position
Move::Move (std::vector < std::vector < Color > > startingPosition) {
	position = startingPosition;
	key = 0;
	step = 0;
	setScore();

	lastMove = NULL;
	exploded = false;
}

// generate a Move based on last move and execution coordinates
Move::Move (Move *prev, int moveSource, int moveDestination) {
	key = 0; // TODO 
	step = prev->step + 1;

	lastMove = prev;
	exploded = false;

	position = prev->position;
	source = moveSource;
	destination = moveDestination;
	execute();
}

void Move::setScore () {
	score = 0;

	// local vars
	int volume = 0;
	int empties = 0;


	// add consecutives scoring component
	for(std::vector< std::vector < Color > >::const_iterator vial_it = position.begin(); vial_it != position.end(); ++vial_it) {
		for(std::vector < Color >::const_iterator ball_it = vial_it->begin(); ball_it != vial_it->end(); ++ball_it) { // this will skip empty vectors
			if (ball_it != vial_it->begin() && *ball_it != *std::prev(ball_it)) { // this will skip first element logic
				score += 1; // add a point for each nonconsecutive color streak
			}
		}

		// calculate values for empties scoring component
		volume += vial_it->size();
		if (vial_it->size() == 0) {
			empties++;
		}
	}

	// add empties scoring component
	score += ((4 * position.size() - volume) / 4) - empties; // add a point for extra vials used
}

void Move::execute () {
	position[destination].push_back(position[source].back());
	position[source].pop_back();
	setScore(); // score should always be recalculated after move is executed
}

void Move::explode () {
	// loop through from source vials
	for (int source_it = 0; source_it < position.size(); source_it++) {
		// loop through destination vials
		for (int destination_it = 0; destination_it < position.size(); destination_it++) {
			// skip movements to self
			if (
				source_it != destination_it && // skip movements to self
				position[source_it].size() > 0 && ( // skip movements from nothing
					position[destination_it].size() == 0 || ( // allow movement to empty vial
						position[destination_it].size() < 4 && // skip movements to full
						position[destination_it].back() == position[source_it].back() // skip movements to incorrect color
			))) {
				nextMoves.push_back(new Move(this, source_it, destination_it));
			}
		}
	}
	exploded = true;
}

void Move::print () {
	if (step > 0) {
		std::cout << "ACTION: " << convertToVialLabel(source) << " -> " << convertToVialLabel(destination) << std::endl;
	}

	if (score == 0) {
		std::cout << "*** WINNER ***" << std::endl;
	}
	std::cout << "MOVE: " << step << std::endl;
	std::cout << "SCORE: " << score << std::endl;
	std::cout << "EXPLODED: " << exploded << std::endl;
	std::cout << "POSITION: " << std::endl;
	displayBoard(position);
}