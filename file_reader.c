#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "errors.h"
#include "file_reader.h"
#include "settings.h"

void read_file(SET setting,GRID *grid[],char* name)
{
	//otworzenie pliku z danymi
	FILE *fp=fopen(name,"r");
	//wywołanie funkcji zwracającej błąd gdy nie udało się otworzyć pliku
	if( fp == NULL ) error_nofoundfile(name);
	
	char x[30],y[30];
	//zmienna wskazująca numer wczytywanego punktu
	int point_number=1;


	while(fscanf(fp,"%s",x)!=EOF&&fscanf(fp,"%s",y)!=EOF)
	{
		/*sprawdzenie czy punkt jest liczbą oraz czy jego wartości należą do rozmiarów planszy.
		**Jeśli któryś błędny warunek zostanie spełniony, to omijamy wczytywanie za pomocą "goto"*/
		if(error_point(point_number,x,y)==1) goto next;
		if(error_point_size(point_number, setting.width, setting.height, atoi(x), atoi(y))==1) goto next;
		
		//wczytywanie punktu do planszy
		grid[setting.height-atoi(y)][atoi(x)-1]=ALIVE;

		next:
		point_number++;
	}
	fclose(fp);
}
