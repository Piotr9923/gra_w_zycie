#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "errors.h"
#include "file_reader.h"
#include "settings.h"

void read_file(SET setting,int *grid[],char* name)
{
	//otworzenie pliku z danymi
	FILE *fp=fopen(name,"r");
	//wywo³anie funkcji zwracaj¹cej b³¹d gdy nie uda³o siê otworzyæ pliku
	if( fp == NULL ) error_nofoundfile(name);
	
	char x[30],y[30];
	//zmienna wskazuj¹ca numer wczytywanego punktu
	int point_number=1;


	while(fscanf(fp,"%s",x)!=EOF&&fscanf(fp,"%s",y)!=EOF)
	{
		//sprawdzenie czy punkt jest liczb¹ oraz czy jego wartoœci nale¿¹ do rozmiarów planszy. Jeœli któryœ b³êdny warunek zostanie spe³niony, to omijamy wczytywanie za pomoc¹ "goto"
		if(error_point(point_number,x,y)==1) goto next;
		if(error_point_size(point_number, setting.width, setting.height, atoi(x), atoi(y))==1) goto next;
		
		//wczytywanie punktu do planszy
		grid[setting.height-atoi(y)][atoi(x)-1]=1;

		next:
		point_number++;
	}
}
