#include"neighbourhood.h"

int check_neighbourhood(int x,int y ,int *grid[], int x1 ,int y1)
{
		int how_many_live_neighbourhood=0;
 
 		//komórka znajduje siê w górnym lewym rogu planszy
       if(x1==0&&y1==0)
        {
                if (grid[x1+1][y1+1]==1) how_many_live_neighbourhood++;
                if (grid[x1][y1+1]==1) how_many_live_neighbourhood++;
                if (grid[x1+1][y1]==1) how_many_live_neighbourhood++;
        }
        
		//komórka znajduje siê w dolnym lewym rogu planszy
        else if(x1==0&&y1==y-1)
        {
                if (grid[x1+1][y1-1]==1) how_many_live_neighbourhood++;
                if (grid[x1][y1-1]==1) how_many_live_neighbourhood++;
                if (grid[x1+1][y1]==1) how_many_live_neighbourhood++;

        }
         //komórka znajduje siê w górnym prawym rogu planszy
        else if(x1==x-1&&y1==0)
        {
                if (grid[x1][y1+1]==1) how_many_live_neighbourhood++;
                if (grid[x1-1][y1]==1) how_many_live_neighbourhood++;
                if (grid[x1-1][y1+1]==1) how_many_live_neighbourhood++;
        }
         //komórka znajduje siê w dolnym prawym rogu planszy
        else if(x1==x-1&&y1==y-1)
        {
                if (grid[x1-1][y1-1]==1) how_many_live_neighbourhood++;
                if (grid[x1-1][y1]==1) how_many_live_neighbourhood++;
                if (grid[x1][y1-1]==1) how_many_live_neighbourhood++;
        }
         //komórka znajduje przy lewej krawêdzi planszy
        else if(x1==0&&y1!=0&&y1!=y-1)
        {
        if (grid[x1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1]==1) how_many_live_neighbourhood++;
        if (grid[x1][y1+1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1+1]==1) how_many_live_neighbourhood++;
        }
         //komórka znajduje przy prawej krawêdzi planszy
 		else if(x1==x-1&&y1!=0&&y1!=y-1)
        {
        if (grid[x1-1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1-1][y1]==1) how_many_live_neighbourhood++;
        if (grid[x1-1][y1+1]==1) how_many_live_neighbourhood++;
        if (grid[x1][y1+1]==1) how_many_live_neighbourhood++;
        }
         //komórka znajduje przy górnej krawêdzi planszy
        else if(y1==0&&x1!=0&&x1!=x-1)
        {
        if (grid[x1-1][y1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1]==1) how_many_live_neighbourhood++;
        if (grid[x1-1][y1+1]==1) how_many_live_neighbourhood++;
        if (grid[x1][y1+1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1+1]==1) how_many_live_neighbourhood++;
        }
         //komórka znajduje przy dolnej krawêdzi planszy
        else if(y1==y-1&&x1!=0&&x1!=x-1)
        {
        if (grid[x1-1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1-1]==1) how_many_live_neighbourhood++;
        if (grid[x1-1][y1]==1) how_many_live_neighbourhood++;
        if (grid[x1+1][y1]==1) how_many_live_neighbourhood++;
        }
         //komórka znajduje wewn¹trz planszy
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
