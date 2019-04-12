#include"change.h"
#include"neighbourhood.h"

//oznaczenie komórek do zmiany na podstawie ich stanu oraz iloœci s¹siadów
void check_cellstochange(int width,int height, GRID*grid[],CHANGE*change[],int*how_many_change)
{
	int how_many_change1=0; 
	for(int y=0;y<height;y++)
    {
        for(int x=0;x<width;x++)
        {
            int how_many_neighbourhood=check_neighbourhood(width,height,grid,y,x);
                                          
        	if(grid[y][x]==0&&how_many_neighbourhood==3) {change[y][x]=YES;how_many_change1++;};
            if(grid[y][x]==1&&(how_many_neighbourhood<2||how_many_neighbourhood>3)){change[y][x]=YES;how_many_change1++;}
        }
    }
        *how_many_change=how_many_change1;
}



void change_cells(int width,int height, GRID*grid[],CHANGE*change[],int*how_many_live,int*how_many_change)
{
	int how_many_live1=0;
	int how_many_change1=0;
	for(int y=0;y<height;y++)
    {
        for(int x=0;x<width;x++)
        {
            if(change[y][x]==YES&&grid[y][x]==DEAD) {grid[y][x]=ALIVE;change[y][x]=NO;how_many_change1++;}
            if(change[y][x]==YES&&grid[y][x]==ALIVE) {grid[y][x]=DEAD;change[y][x]=NO;how_many_change1++;}
            if(grid[y][x]==ALIVE) how_many_live1++;
        }
    }
        *how_many_live=how_many_live1;
		*how_many_change=how_many_change1;
}
