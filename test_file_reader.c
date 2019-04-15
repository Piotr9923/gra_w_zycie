#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_reader.h"
#include "settings.h"
int main()
{
        char* dane_testowe= "dane_testowe";
        int height =20;
        int width=20;
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
        read_file(setting,grid,dane_testowe);
        if(grid[19][0]==YES||grid[17][2]==YES||grid[15][4]==YES||grid[13][6]==YES) return 1;
                else
                {
                        for(int i=0;i<setting.height;++i)
                        {
                                free(grid[i]);
                        }
                        free(grid);
                }
                return 0;
}
