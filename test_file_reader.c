#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_reader.h"
#include "writer.h"


int main()
{
	char* dane_testowe= "dane_testowe";
	int height =10;
	int width=10;
	int **grid  = (int**) malloc(height*sizeof(int*));
	for(int j=0;j<width;j++)
            {
                grid[j]=malloc(width*sizeof(int*));
            }

	for(int i=0;i<height;i++)
		{
    	    for(int j=0;j<width;j++)
    	    {
                grid[i][j]=0;
    	    }
	}

        read_file(height,width,grid,dane_testowe);
	printf ("Znak %d", grid[5][5]);
        write(height,width,grid);
}

