#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"neighbourhood.h"
#include "settings.h"
int main()
{
        char* dane_testowe= "dane_testowe";
        int height = 10;
        int width = 10;
        GRID** grid;
        grid  = malloc(height*sizeof(GRID*));
        for(int j=0;j<width;j++)
            {
                grid[j]=malloc(width*sizeof(GRID*));
            }

        for(int i=0;i<height;i++)
                {
            for(int j=0;j<width;j++)
            {
                grid[i][j]=DEAD;
            }
        }
        char name_graphic[]="image";
        char name_txt[]="cells";
        SET setting={height,width,name_graphic,name_txt,1,0,0,0,255,255,255,1000};
        
        grid[1][1]=ALIVE;
        grid[2][2]=ALIVE;
        grid[1][2]=ALIVE;
        grid[1][3]=ALIVE;
        grid[6][6]=ALIVE;
        grid[1][4]=ALIVE;
        int val_check;
        int val;
        val_check=0;
        val = check_neighbourhood(width,height,grid,6,6);        
        if (val != val_check) return 1;
        val_check=1;
        val = check_neighbourhood(width,height,grid,1,4);        
        if (val != val_check) return 1;
        val_check=2;
        val = check_neighbourhood(width,height,grid,1,1);        
        if (val != val_check) return 1;
        val_check=3;
        val = check_neighbourhood(width,height,grid,1,2);        
        if (val != val_check) return 1;
        return 0;
}
