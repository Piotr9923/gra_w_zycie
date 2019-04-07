#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include"errors.h"
#include"file_reader.h"

void read_file(int x,int y,int *grid[],char* name,int language)
{

FILE *fp=fopen(name,"r");

if( fp == NULL ) error_nofoundfile(name,language);
char x1[100],y1[100];
int point_number=1;


while(fscanf(fp,"%s",x1)!=EOF&&fscanf(fp,"%s",y1)!=EOF)
{
if(error_point(point_number,x1,y1,language)==1) goto next;
if(error_point_size(point_number, x, y, atoi(x1), atoi(y1),language)==1) goto next;

grid[y-atoi(y1)][atoi(x1)-1]=1;

next:
point_number++;
}
}
