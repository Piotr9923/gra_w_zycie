#include<stdio.h>
#include <stdlib.h>
#include<string.h>

void wczytaj_dane(int x,int y,int *tab[],char* nazwa)
{

FILE *fp=fopen(nazwa,"r");

if( fp == NULL ) error_nofoundfile(nazwa);
char x1[100],y1[100];
int point_number=1;


while(fscanf(fp,"%s",&x1)!=EOF&&fscanf(fp,"%s",&y1)!=EOF)
{
if(error_point(point_number,x1,y1)==1) goto next;
if(error_point_size(point_number, x, y, atoi(x1), atoi(y1))==1) goto next;

tab[y-atoi(y1)][atoi(x1)-1]=1;

next:
point_number++;
}
}
