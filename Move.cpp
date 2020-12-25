#include "Move.h"
#include "Display.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>

int currentKey;

// generate a Move object from a starting position
Move::Move (std::vector < std::vector < Color > > startingPosition) {
	position = startingPosition;
	currentKey = 0;
	key = currentKey++;
	step = 0;
	setScore();

	lastMove = NULL;
	exploded = false;
}

// generate a Move based on last move with updated position
Move::Move (Move *prev) {
	key = currentKey++;
	step = prev->step + 1;

	lastMove = prev;
	prev->nextMoves.push_back(this);
	exploded = false;

	position = prev->position;
	setScore();
}

Move::~Move() {
    for(int i = 0; i < nextMoves.size(); i++)
        delete nextMoves[i];
    return;
}

// TODO add logic for when more efficient path found
bool Move::compare (std::vector < std::vector < Color > >& newPosition) {
	std::vector<int> indicesToCompare(newPosition.size()) ;
	std::iota (std::begin(indicesToCompare), std::end(indicesToCompare), 0);

	for (int i = position.size() - 1; i >= 0; i--) {
		for (int j = 0; j < indicesToCompare.size(); j++) {
			if (position[i] == newPosition[indicesToCompare[j]]) {
				indicesToCompare.erase(indicesToCompare.begin() + j);
				break;
			}
		}
		if (indicesToCompare.size() != i) {
			return false;
		}
	}
	return true;
}

bool Move::scanForMatches () {
	std::queue<Move*> scanQueue;
	std::vector<int> queued = {key};

	for (int i = 0; i < nextMoves.size(); i++) {
		scanQueue.push(nextMoves[i]);
		queued.push_back(nextMoves[i]->key);
	}
	if (lastMove != NULL) {
		scanQueue.push(lastMove);
		queued.push_back(lastMove->key);
	}

	while (!scanQueue.empty()) {
		if (scanQueue.front()->compare(position)) {
			return true;
		} else {
			for (int i = 0; i < scanQueue.front()->nextMoves.size(); i++) {
				if (std::find(queued.begin(), queued.end(), scanQueue.front()->nextMoves[i]->key) == queued.end()) {
					scanQueue.push(scanQueue.front()->nextMoves[i]);
					queued.push_back(scanQueue.front()->nextMoves[i]->key);

				}
			}

			if (scanQueue.front()->lastMove != NULL && std::find(queued.begin(), queued.end(), scanQueue.front()->lastMove->key) == queued.end()) {
				scanQueue.push(scanQueue.front()->lastMove);
				queued.push_back(scanQueue.front()->lastMove->key);
			}
		}
		scanQueue.pop();
	}
	return false;
}

int Move::scanForMinimum () {
	int minimum = position.size() * 6;

	if (!exploded) {
		minimum = std::min(minimum, score);
	}

	for (int i = 0; i < nextMoves.size(); i++) {
		minimum = std::min(minimum, nextMoves[i]->scanForMinimum());
	}

	return minimum;
}

void Move::setScore () {
	score = 0;

	// local vars
	int volume = 0;
	int empties = 0;
	int multiplier;

	// add consecutives scoring component
	for(std::vector< std::vector < Color > >::const_iterator vial_it = position.begin(); vial_it != position.end(); ++vial_it) {
		multiplier = 0;
		for(std::vector < Color >::const_iterator ball_it = vial_it->begin(); ball_it != vial_it->end(); ++ball_it) { // this will skip empty vectors
			if (ball_it != vial_it->begin() && *ball_it != *std::prev(ball_it)) { // new ball color found
				multiplier += 1; // higher penalty for each level
			}
			score += multiplier;
		}

		// calculate values for empties scoring component
		volume += vial_it->size();
		if (vial_it->size() == 0) {
			empties++;
		}
	}

	// add empties scoring component
	score += (4 * position.size() - volume) - 4 * empties; // add single point for extra vials used
}

void Move::execute (int source, int destination) {
	position[destination].push_back(position[source].back());
	position[source].pop_back();
}

void Move::revert (int source, int destination) {
	position[source].push_back(position[destination].back());
	position[destination].pop_back();
}

Move* Move::explode () {
	if (key > 1000) { // TODO evaluate program limits
		return NULL;
	}

	Move* winningPosition = explode(scanForMinimum());

	if (winningPosition == NULL) {
		return explode();
	} else {
		return winningPosition;
	}
}

Move* Move::explode (int minimumScore) {
	// explode this move if it hasn't been done yet and minimum score is a match
	if (!exploded && score == minimumScore) {
		// loop through from source vials
		for (int source_it = 0; source_it < position.size(); source_it++) {
			// loop through destination vials
			for (int destination_it = 0; destination_it < position.size(); destination_it++) {
				// skip movements to self
				if (
					source_it != destination_it && // skip movements to self
					// TODO the below really should be comparing whether movement from source to dest vial creates an identical result vial
					(position[source_it].size() > 1 || position[destination_it].size() > 0) && // skip movements from single to empty vial
					position[source_it].size() > 0 && ( // skip movements from nothing
						position[destination_it].size() == 0 || ( // allow movement to empty vial
							position[destination_it].size() < 4 && // skip movements to full
							position[destination_it].back() == position[source_it].back() // skip movements to incorrect color
				))) {
					execute(source_it, destination_it);

					if (!scanForMatches()) {
						Move* nextMove = new Move(this);

						if (nextMove->score == 0) {
							revert(source_it, destination_it);
							return nextMove;
						}
					}
					revert(source_it, destination_it);
				}
			}
		}
		exploded = true;
	}

	for (int i = 0; i < nextMoves.size(); i++) {
		Move* winningMove = nextMoves[i]->explode(minimumScore);
		if (winningMove != NULL) {
			return winningMove;
		}
	}

	return NULL; // if no winner found, return NULL
}

void Move::populatePath(std::stack<Move*>& moves) {
	moves.push(this);
	if (lastMove != NULL) {
		lastMove->populatePath(moves);
	}
}

void Move::print (Move* nextMove) { // defaulted to NULL
	if (score == 0) {
		std::cout << "*** WINNER ***" << std::endl;
	}
	std::cout << "KEY: " << key << std::endl;
	if (step != 0) {
		std::cout << "LAST MOVE KEY: " << lastMove->key << std::endl;
	}
	std::cout << "MOVE: " << step << std::endl;
	std::cout << "SCORE: " << score << std::endl;
	std::cout << "EXPLODED: " << exploded << std::endl;
	std::cout << "POSITION: " << std::endl;
	if (nextMove == NULL) {
		displayBoard(position);
	} else {
		displayFlashyBoard(position, nextMove->position);
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void Move::print (std::stack<Move*>& moves) {
	Move* thisMove = moves.top();
	moves.pop();

	if (moves.empty()) {
		thisMove->print();
	} else {
		thisMove->print(moves.top());
	}
}

void Move::printPath () {
	std::stack<Move*> moves;

	populatePath(moves);

	while (!moves.empty()) {
		print(moves);
	}
}

void Move::printExplosion () {
	print();
	for (int i = 0; i < nextMoves.size(); i++) {
		nextMoves[i]->printExplosion();
	}
}