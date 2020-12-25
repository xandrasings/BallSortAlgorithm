#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include "Color.h"

char convertToVialLabel(int index);
void displayBoard(const std::vector < std::vector < Color > > &);
void displayFlashyBoard(const std::vector < std::vector < Color > > &, const std::vector < std::vector < Color > > &);

#endif