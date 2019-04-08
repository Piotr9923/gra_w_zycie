#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "file_reader.h"
#include "settings.h"
#include "game.h"

int main(int argc, char *argv[]) 
{

	/*ustawienie wartoœci domyœlnych dla zmiennych odpowiedzialnych za ustawienia*/
	int width=20, height=20, pixel_size=1;	//width-rozmiar planszy(wspó³rzêdna x)   height-rozmiar planszy (wspó³rzêdna y)  pixel_size-rozmiar z ilu pikseli ma siê sk³adaæ bok komórki
	char* filename;   // nazwa pliku z danymi
	char name_graphic[]="image";
	char* graphicfile=name_graphic;	// nazwa pliku do którego zapisujemy grafikê
	char name_txt[]="cells";
	char* txtfile=name_txt;	//nazwa pliku do którego zapisujemy uk³ad komórek

	int is_graphicname=0; 	//zmienna pomocnicza sprawdzaj¹ca czy u¿ytkownik poda³ nazwê wyjœciowego pliku graficzengo
	int is_txtname=0;//zmienna pomocnicza sprawdzaj¹ca czy u¿ytkownik poda³ nazwê wyjœciowego pliku tekstowego

	int lred=0,lgreen=0,lblue=0; //kolory ¿ywych komórek w modelu RGB
	int dred=255,dgreen=255,dblue=255;//kolory martwych komórek w modelu RGB
	int N=1000;




	//sprawdzenie czy u¿ytkownik wybra³ jêzyk. Jeœli tak to zmiana zmiennej wskazuj¹cej na jêzyk(0-angielski,1-polski,2-niemiecki,3-francuski,4-w³oski,5-hiszpañski)
	check_language(argv,argc);

	//sprawdzenie czy u¿ytkownik poda³ ustawienia i wczytanie ich
	check_gridsize(&width,&height,&N,argv,argc);
	check_graphicsettings(&pixel_size,&lred,&lblue,&lgreen,&dred,&dblue,&dgreen,argv,argc);
	check_filenames(&filename,&graphicfile,&txtfile,argv,argc);



	int **grid,**change;			//grid- tablica zawieraj¹ca liczby 0,1 które oznaczaj¹ stan komórek (1-¿ywa, 0-martwa)    chenge tablica w której bêdziemy oznaczaæ komórki do zmiany cyfr¹ 1

	//alokacja pamiêci dla tablic
	grid=malloc(sizeof(int*)*height);
	change=malloc(sizeof(int*)*height);	

	for(int i=0;i<height;++i)
	{
		grid[i]=malloc(sizeof(int)*width);
		change[i]=malloc(sizeof(int)*width);
	}
	//koniec alokacji pamiêci

	//ustawienie wartoœci tablic grid i change na 0
	for(int i=0;i<height;i++)
		{
    	    for(int j=0;j<width;j++)
    	    {
                grid[i][j]=0;
                change[i][j]=0;
    	    }
	}


	//wczytywanie danych z pliku o nazwie podanej przez u¿ytkownika
	read_file(width,height,grid,filename);

	//tworzenie folderu do którego bêd¹ zapisywane pliki wynikowe
	system("mkdir results");
	
	
	game(width,height,pixel_size,lred,lgreen,lblue,dred,dgreen,dblue,N,grid,change,txtfile,graphicfile);

	return 0;
}
