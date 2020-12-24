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
		bool exploded;
	public:
		Move (std::vector < std::vector < Color > >);
		Move (Move*);
		~Move();

		bool compare(Move*);
		bool compare(std::vector < std::vector < Color > >&);

		void execute(int, int);
		void revert(int, int);
		void setScore();

		Move* explode ();

		void print ();
};

#endif