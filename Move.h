#ifndef __MOVE_H__
#define __MOVE_H__
#include "Color.h"
#include <vector>

class Move {
	protected:
		std::vector < std::vector < Color > > position;
		int index;
		int score;
		Move* lastMove;
		int source;
		int destination;
		bool exploded;
	public:
		Move (std::vector < std::vector < Color > >);
		Move (Move&, int, int);

		void execute();
		void setScore();

		void explode(); // TODO this should eventually accept move list passed by reference which will be updated by the function.

		void print ();
};

#endif