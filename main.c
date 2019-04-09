#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "file_reader.h"
#include "settings.h"
#include "game.h"

int main(int argc, char *argv[]) 
{

	/*ustawienie wartoœci domyœlnych dla zmiennych odpowiedzialnych za ustawienia*/
	char* filename;   // nazwa pliku z danymi
	char name_graphic[]="image";
	char name_txt[]="cells";

	SET setting={20,20,name_graphic,name_txt,1,0,0,0,255,255,255,1000};

	SET* setting_pointer=&setting;


	//sprawdzenie czy u¿ytkownik wybra³ jêzyk. Jeœli tak to zmiana zmiennej wskazuj¹cej na jêzyk(0-angielski,1-polski,2-niemiecki,3-francuski,4-w³oski,5-hiszpañski)
	check_language(argv,argc);

	//sprawdzenie czy u¿ytkownik poda³ ustawienia i wczytanie ich
	check_gridsize(setting_pointer,argv,argc);
	check_graphicsettings(setting_pointer,argv,argc);
	check_filenames(&filename,setting_pointer,argv,argc);



	int **grid,**change;			//grid- tablica zawieraj¹ca liczby 0,1 które oznaczaj¹ stan komórek (1-¿ywa, 0-martwa)    chenge tablica w której bêdziemy oznaczaæ komórki do zmiany cyfr¹ 1

	//alokacja pamiêci dla tablic
	grid=malloc(sizeof(int*)*setting.height);
	change=malloc(sizeof(int*)*setting.height);	

	for(int i=0;i<setting.height;++i)
	{
		grid[i]=malloc(sizeof(int)*setting.width);
		change[i]=malloc(sizeof(int)*setting.width);
	}
	//koniec alokacji pamiêci

	//ustawienie wartoœci tablic grid i change na 0
	for(int i=0;i<setting.height;i++)
		{
    	    for(int j=0;j<setting.width;j++)
    	    {
                grid[i][j]=0;
                change[i][j]=0;
    	    }
	}


	//wczytywanie danych z pliku o nazwie podanej przez u¿ytkownika
	read_file(setting,grid,filename);

	//tworzenie folderu do którego bêd¹ zapisywane pliki wynikowe
	system("mkdir results");
	
	
	game(setting,grid,change);

	free(grid);
	free(change);

	return 0;
}
