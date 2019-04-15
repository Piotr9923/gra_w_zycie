#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_reader.h"
#include "settings.h"
int main()
{
        char* dane_testowe= "dane_testowe";
        int height =5;
        int width=5;
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
        SET setting={20,20,name_graphic,name_txt,1,0,0,0,255,255,255,1000};
        grid[1][2]=ALIVE;
        grid[1][3]=ALIVE;
        grid[3][2]=ALIVE;
        grid[3][3]=ALIVE;
        grid[4][4]=ALIVE;
        grid[2][4]=ALIVE;
        grid[4][2]=ALIVE;
        grid[1][4]=ALIVE;
        grid[3][4]=ALIVE;

        write(height,width,grid);
        else return 0;
}
