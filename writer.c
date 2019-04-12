#include<stdio.h>
#include "writer.h"
 
void write(int width,int height,GRID *grid[])
{
	printf("\n");
    printf(" ");
	for(int i=0;i<width*2;i++) printf("-");
	printf("\n");
	
	for(int i=0;i<height;i++)
	{
        for(int j=0;j<width;j++)
        {
        
            if(j==0) printf("|");
            if(grid[i][j]==YES)printf("X ");
        	else printf("  ");
            if(j==width-1) printf("|");
        }
        printf("\n");
	}
	
	printf(" ");
	for(int i=0;i<width*2;i++) printf("-");
    for(int i1=0;i1<10;i1++) printf("\n");
}
