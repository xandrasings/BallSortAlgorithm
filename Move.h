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
		bool exploded;
	public:
		Move (std::vector < std::vector < Color > >);
		Move (int, std::vector < std::vector < Color > >, int, int);


		void execute();
		void setScore();

		void explode ();

		void print ();
};

#endif