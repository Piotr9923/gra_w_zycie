#include"change.h"
#include"neighbourhood.h"

void check_cellstochange(int x,int y, int*grid[],int*change[],int*how_many_change)
{
	int how_many_change1=0; 
	for(int i=0;i<y;i++)
        {
                for(int j=0;j<x;j++)
                {
                      	int how_many_neighbourhood=check_neighbourhood(x,y,grid,i,j);
                                          
                        if(grid[i][j]==0&&how_many_neighbourhood==3) {change[i][j]=1;how_many_change1++;};
                        if(grid[i][j]==1&&(how_many_neighbourhood<2||how_many_neighbourhood>3)){change[i][j]=1;how_many_change1;}
                      
                }
        }
           *how_many_change=how_many_change1;
	
}

void change_cells(int x,int y, int*grid[],int*change[],int*how_many_live)
{
	int how_many_live1=0;
	 for(int i=0;i<y;i++)
        {
                for(int j=0;j<x;j++)
                {
                        if(change[i][j]==1&&grid[i][j]==0) {grid[i][j]=1;change[i][j]=0;}
                        if(change[i][j]==1&&grid[i][j]==1) {grid[i][j]=0;change[i][j]=0;}
                        if(grid[i][j]==1) how_many_live1++;
                }
        }
        *how_many_live=how_many_live1;
}
