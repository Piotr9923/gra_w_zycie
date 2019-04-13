#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "file_reader.h"
#include "settings.h"
#include "game.h"

int main(int argc, char *argv[]) 
{

	/*ustawienie wartości domyślnych dla zmiennych odpowiedzialnych za ustawienia*/
	char* filename;   // nazwa pliku z danymi
	char name_graphic[]="image";
	char name_txt[]="cells";

	SET setting={20,20,name_graphic,name_txt,1,0,0,0,255,255,255,1000};

	SET* setting_pointer=&setting;


	//sprawdzenie czy użytkownik wybrał język.
	check_language(argv,argc);

	//sprawdzenie czy użytkownik podał ustawienia i wczytanie ich
	check_gridsize(setting_pointer,argv,argc);
	check_graphicsettings(setting_pointer,argv,argc);
	check_filenames(&filename,setting_pointer,argv,argc);

	
	GRID **grid;		//grid - tablica zawierająca informację czy komórka jest żywa czy martwa
	CHANGE **change;	//change - tablica zawierająca infrmację czy dana komórka zmienia swój stan
	
	//alokacja pamięci dla tablic
	grid=malloc(sizeof(GRID*)*setting.height);
	change=malloc(sizeof(CHANGE*)*setting.height);	

	for(int i=0;i<setting.height;++i)
	{
		grid[i]=malloc(sizeof(GRID)*setting.width);
		change[i]=malloc(sizeof(CHANGE)*setting.width);
	}
	//koniec alokacji pamięci

	//ustawienie wartości tablic grid i change na domyślne
	for(int i=0;i<setting.height;i++)
	{
    	    for(int j=0;j<setting.width;j++)
    	    {
                grid[i][j]=DEAD;
                change[i][j]=NO;
    	    }
	}


	//wczytywanie danych z pliku o nazwie podanej przez użytkownika
	read_file(setting,grid,filename);

	//tworzenie folderu do którego będą zapisywane pliki wynikowe
	system("mkdir results");
	
	
	game(setting,grid,change);
	
	//zwolnienie pamięci
	for(int i=0;i<setting.height;++i)
	{
		free(grid[i]);
		free(change[i]);
	}
	free(grid);
	free(change);

	return 0;
}
