#include<stdio.h>
 #include"write.h"
 
void write(int x,int y,int *grid[])
{
	printf("\n");
        printf(" ");
for(int i=0;i<x*2;i++) printf("-");
printf("\n");
for(int i=0;i<y;i++)
{
        for(int j=0;j<x;j++)
        {
        
                if(j==0) printf("|");
                if(grid[i][j]==1)printf("X ");
                else printf("  ");
                if(j==x-1) printf("|");
        }
        printf("\n");
}
printf(" ");
for(int i=0;i<x*2;i++) printf("-");
     for(int i1=0;i1<10;i1++) printf("\n");

}
