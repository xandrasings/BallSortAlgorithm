#ifndef __MOVE_H__
#define __MOVE_H__
#include "Color.h"
#include <vector>

class Move {
public:
	// protected:
		std::vector < std::vector < Color > > position;
		int key;
		int step;
		int score;

		Move* lastMove;
		std::vector < Move* > nextMoves;

		int source;
		int destination;
	public:
		Move (std::vector < std::vector < Color > >);
		Move (Move*, int, int);

		void execute();
		void setScore();

		Move* explode ();

		void print ();
};

#endif