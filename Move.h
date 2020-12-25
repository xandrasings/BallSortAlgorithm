#ifndef __MOVE_H__
#define __MOVE_H__
#include "Color.h"
#include <stack>
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

		bool compare(std::vector < std::vector < Color > >&);
		bool scanForMatches();

		void execute(int, int);
		void revert(int, int);
		void setScore();

		Move* explode ();
		void populatePath(std::stack<Move*>&);

		// void print ();
		void print (Move* = NULL);
		void print (std::stack<Move*>&);
		void printPath ();
		void printExplosion ();
};

#endif