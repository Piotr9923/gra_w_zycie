#include"neighbourhood.h"

int check_neighbourhood(int x,int y ,int *grid[], int x1 ,int y1)
{
		int how_many_live_neighbourhood=0;
 
 		//kom�rka znajduje si� w g�rnym lewym rogu planszy
       if(x1==0&&y1==0)
        {
                if (grid[x1+1][y1+1]==1) how_many_live_neighbourhood++;
                if (grid[x1][y1+1]==1) how_many_live_neighbourhood++;
                if (grid[x1+1][y1]==1) how_many_live_neighbourhood++;
        }
        
		//kom�rka znajduje si� w dolnym lewym rogu planszy
        else if(x1==0&&y1==y-1)
        {
                if (grid[x1+1][y1-1]==1) how_many_live_neighbourhood++;
                if (grid[x1][y1-1]==1) how_many_live_neighbourhood++;
                if (grid[x1+1][y1]==1) how_many_live_neighbourhood++;

        }
         //kom�rka znajduje si� w g�rnym prawym rogu planszy
        else if(x1==x-1&&y1==0)
        {
                if (grid[x1][y1+1]==1) how_many_live_neighbourhood++;
                if (grid[x1-1][y1]==1) how_many_live_neighbourhood++;
                if (grid[x1-1][y1+1]==1) how_many_live_neighbourhood++;
        }
         //kom�rka znajduje si� w dolnym prawym rogu planszy
        else if(x1==x-1&&y1==y-1)
        {
                if (grid[x1-1][y1-1]==1) how_many_live_neighbourhood++;
                if (grid[x1-1][y1]==1) how_many_live_neighbourhood++;
                if (grid[x1][y1-1]==1) how_many_live_neighbourhood++;
        }
         //kom�rka znajduje przy lewej kraw�dzi planszy
        else if(x1==0&&y1!=0&&y1!=y-1)
        {
        if (grid[x1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1]==1) how_many_live_neighbourhood++;
        if (grid[x1][y1+1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1+1]==1) how_many_live_neighbourhood++;
        }
         //kom�rka znajduje przy prawej kraw�dzi planszy
 		else if(x1==x-1&&y1!=0&&y1!=y-1)
        {
        if (grid[x1-1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1-1][y1]==1) how_many_live_neighbourhood++;
        if (grid[x1-1][y1+1]==1) how_many_live_neighbourhood++;
        if (grid[x1][y1+1]==1) how_many_live_neighbourhood++;
        }
         //kom�rka znajduje przy g�rnej kraw�dzi planszy
        else if(y1==0&&x1!=0&&x1!=x-1)
        {
        if (grid[x1-1][y1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1]==1) how_many_live_neighbourhood++;
        if (grid[x1-1][y1+1]==1) how_many_live_neighbourhood++;
        if (grid[x1][y1+1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1+1]==1) how_many_live_neighbourhood++;
        }
         //kom�rka znajduje przy dolnej kraw�dzi planszy
        else if(y1==y-1&&x1!=0&&x1!=x-1)
        {
        if (grid[x1-1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1-1][y1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1]==1) how_many_live_neighbourhood++;
        }
         //kom�rka znajduje wewn�trz planszy
        else
        {
        if (grid[x1-1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1-1][y1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1]==1) how_many_live_neighbourhood++;
        if (grid[x1-1][y1+1]==1) how_many_live_neighbourhood++;
        if (grid[x1][y1+1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1+1]==1) how_many_live_neighbourhood++;
        }

  
        return how_many_live_neighbourhood;
}
