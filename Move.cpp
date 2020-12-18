#include "Move.h"
#include "Display.h"
#include <iostream>
#include <vector>

int currentKey;

// generate a Move object from a starting position
Move::Move (std::vector < std::vector < Color > > startingPosition) {
	position = startingPosition;
	currentKey = 0;
	key = currentKey++;
	step = 0;
	setScore();

	lastMove = NULL;
}

// generate a Move based on last move and execution coordinates
Move::Move (Move *prev, int moveSource, int moveDestination) {
	key = currentKey++;
	step = prev->step + 1;

	lastMove = prev;

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

Move* Move::explode () {
	// explode this move if it hasn't been done yet
	if (nextMoves.size() == 0) {
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
					Move* nextMove = new Move(this, source_it, destination_it);
					nextMoves.push_back(nextMove);

					// TODO remove
					std::cout << "ADDED A NEW MOVE" << std::endl;
					nextMove->print();

					if (nextMove->score == 0) {
						return nextMove;
					}
				}
			}
		}
	} else { // otherwise check the next level of moves
		for (int i = 0; i < nextMoves.size(); i++) {
			Move* winningMove = nextMoves[i]->explode();
			if (winningMove != NULL) {
				return winningMove;
			}
		}
	}
	return NULL; // if no winner found on this depth, return NULL
}

void Move::print () {
	if (step > 0) {
		std::cout << "ACTION: " << convertToVialLabel(source) << " -> " << convertToVialLabel(destination) << std::endl;
	}

	if (score == 0) {
		std::cout << "*** WINNER ***" << std::endl;
	}
	std::cout << "MOVE: " << step << std::endl;
	std::cout << "KEY: " << key << std::endl;
	std::cout << "LAST MOVE KEY: " << lastMove->key << std::endl;
	std::cout << "SCORE: " << score << std::endl;
	std::cout << "POSITION: " << std::endl;
	displayBoard(position);
	std::cout << std::endl;
	std::cout << std::endl;
}