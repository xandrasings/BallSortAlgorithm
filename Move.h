#ifndef __MOVE_H__
#define __MOVE_H__
#include "Color.h"
#include <vector>

class Move {
	protected:
		std::vector < std::vector < Color > > position;
	public:
		Move (int);
		void print ();
};

#endif