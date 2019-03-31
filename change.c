#include"change.h"
#include"neighbourhood.h"

void check_aimtochange(int x,int y, int*grid[],int*change[],int*how_many_change)
{
	
	for(int i=0;i<y;i++)
        {
                for(int j=0;j<x;j++)
                {
                      int how_many_neighbourhood=check_neighbourhood(x,y,grid,i,j);
                                          
                        if(grid[i][j]==0&&how_many_neighbourhood==3) {change[i][j]=1;*how_many_change++;};
                        if(grid[i][j]==1&&(how_many_neighbourhood<2||how_many_neighbourhood>3)){change[i][j]=1;*how_many_change++;}
                      
                }
        }
	
}

void change_aims(int x,int y, int*grid[],int*change[],int*how_many_live)
{
	 for(int i=0;i<y;i++)
        {
                for(int j=0;j<x;j++)
                {
                        if(change[i][j]==1&&grid[i][j]==0) {grid[i][j]=1;change[i][j]=0;}
                        if(change[i][j]==1&&grid[i][j]==1) {grid[i][j]=0;change[i][j]=0;}
                        if(grid[i][j]==1) *how_many_live++;
                }
        }
}
