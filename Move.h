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
	public:
		Move (std::vector < std::vector < Color > >);

		void setScore();
		void print ();
};

#endif