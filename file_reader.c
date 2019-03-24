#include<stdio.h>
#include <stdlib.h>

void wczytaj_dane(int x,int y,int *tab[],char* nazwa)
{

FILE *fp=fopen(nazwa,"r");
int x1,y1;

while(fscanf(fp,"%d",&x1)!=EOF)
{
fscanf(fp,"%d",&y1);
        tab[y-y1][x1-1]=1;
        
        
}

}
