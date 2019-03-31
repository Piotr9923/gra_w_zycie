#include"neighbourhood.h"

int check_neighbourhood(int x,int y ,int *grid[], int x1 ,int y1)
{

        int how_many=0;
       if(x1==0&&y1==0)
        {
                if (grid[x1+1][y1+1]==1) how_many++;
                if (grid[x1][y1+1]==1) how_many++;
                if (grid[x1+1][y1]==1) how_many++;
        }
        else if(x1==0&&y1==y-1)
        {
                if (grid[x1+1][y1-1]==1) how_many++;
                if (grid[x1][y1-1]==1) how_many++;
                if (grid[x1+1][y1]==1) how_many++;

        }
        else if(x1==y-1&&y1==0)
        {
                if (grid[x1][y1+1]==1) how_many++;
                if (grid[x1-1][y1]==1) how_many++;
                if (grid[x1-1][y1+1]==1) how_many++;
        }
        else if(x1==y-1&&y1==y-1)
        {
                if (grid[x1-1][y1-1]==1) how_many++;
                if (grid[x1-1][y1]==1) how_many++;
                if (grid[x1][y1-1]==1) how_many++;
        }
        else if(x1==0&&y1!=0&&y1!=y-1)
        {
        if (grid[x1][y1-1]==1) how_many++;
        if (grid[x1+1][y1-1]==1) how_many++;
        if (grid[x1+1][y1]==1) how_many++;
        if (grid[x1][y1+1]==1) how_many++;
        if (grid[x1+1][y1+1]==1) how_many++;
        }
 else if(x1==y-1&&y1!=0&&y1!=y-1)
        {
        if (grid[x1-1][y1-1]==1) how_many++;
        if (grid[x1][y1-1]==1) how_many++;
        if (grid[x1-1][y1]==1) how_many++;
        if (grid[x1-1][y1+1]==1) how_many++;
        if (grid[x1][y1+1]==1) how_many++;
        }
                else if(y1==0&&x1!=0&&x1!=y-1)
        {
        if (grid[x1-1][y1]==1) how_many++;
        if (grid[x1+1][y1]==1) how_many++;
        if (grid[x1-1][y1+1]==1) how_many++;
        if (grid[x1][y1+1]==1) how_many++;
        if (grid[x1+1][y1+1]==1) how_many++;
        }
        else if(y1==y-1&&x1!=0&&x1!=y-1)
        {
        if (grid[x1-1][y1-1]==1) how_many++;
        if (grid[x1][y1-1]==1) how_many++;
        if (grid[x1+1][y1-1]==1) how_many++;
        if (grid[x1-1][y1]==1) how_many++;
        if (grid[x1+1][y1]==1) how_many++;
        }
        else
        {
        if (grid[x1-1][y1-1]==1) how_many++;
        if (grid[x1][y1-1]==1) how_many++;
        if (grid[x1+1][y1-1]==1) how_many++;
        if (grid[x1-1][y1]==1) how_many++;
        if (grid[x1+1][y1]==1) how_many++;
        if (grid[x1-1][y1+1]==1) how_many++;
        if (grid[x1][y1+1]==1) how_many++;
        if (grid[x1+1][y1+1]==1) how_many++;
        }

  
        return how_many;
}
