#ifndef _CHANGE_
#define _CHANGE_
#include "settings.h"

void check_cellstochange(int width,int height, GRID*grid[],CHANGE*change[],int*how_many_change);

void change_cells(int width,int height, GRID*grid[],CHANGE*change[],int*how_many_live,int*how_many_change);

#endif

