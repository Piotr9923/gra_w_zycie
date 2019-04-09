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
	//wywo�anie funkcji zwracaj�cej b��d gdy nie uda�o si� otworzy� pliku
	if( fp == NULL ) error_nofoundfile(name);
	
	char x[30],y[30];
	//zmienna wskazuj�ca numer wczytywanego punktu
	int point_number=1;


	while(fscanf(fp,"%s",x)!=EOF&&fscanf(fp,"%s",y)!=EOF)
	{
		//sprawdzenie czy punkt jest liczb� oraz czy jego warto�ci nale�� do rozmiar�w planszy. Je�li kt�ry� b��dny warunek zostanie spe�niony, to omijamy wczytywanie za pomoc� "goto"
		if(error_point(point_number,x,y)==1) goto next;
		if(error_point_size(point_number, setting.width, setting.height, atoi(x), atoi(y))==1) goto next;
		
		//wczytywanie punktu do planszy
		grid[setting.height-atoi(y)][atoi(x)-1]=1;

		next:
		point_number++;
	}
}
