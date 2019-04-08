#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "file_reader.h"
#include "settings.h"
#include "game.h"

int main(int argc, char *argv[]) 
{

	/*ustawienie warto�ci domy�lnych dla zmiennych odpowiedzialnych za ustawienia*/
	int width=20, height=20, pixel_size=1;	//width-rozmiar planszy(wsp�rz�dna x)   height-rozmiar planszy (wsp�rz�dna y)  pixel_size-rozmiar z ilu pikseli ma si� sk�ada� bok kom�rki
	char* filename;   // nazwa pliku z danymi
	char name_graphic[]="image";
	char* graphicfile=name_graphic;	// nazwa pliku do kt�rego zapisujemy grafik�
	char name_txt[]="cells";
	char* txtfile=name_txt;	//nazwa pliku do kt�rego zapisujemy uk�ad kom�rek

	int is_graphicname=0; 	//zmienna pomocnicza sprawdzaj�ca czy u�ytkownik poda� nazw� wyj�ciowego pliku graficzengo
	int is_txtname=0;//zmienna pomocnicza sprawdzaj�ca czy u�ytkownik poda� nazw� wyj�ciowego pliku tekstowego

	int lred=0,lgreen=0,lblue=0; //kolory �ywych kom�rek w modelu RGB
	int dred=255,dgreen=255,dblue=255;//kolory martwych kom�rek w modelu RGB
	int N=1000;




	//sprawdzenie czy u�ytkownik wybra� j�zyk. Je�li tak to zmiana zmiennej wskazuj�cej na j�zyk(0-angielski,1-polski,2-niemiecki,3-francuski,4-w�oski,5-hiszpa�ski)
	check_language(argv,argc);

	//sprawdzenie czy u�ytkownik poda� ustawienia i wczytanie ich
	check_gridsize(&width,&height,&N,argv,argc);
	check_graphicsettings(&pixel_size,&lred,&lblue,&lgreen,&dred,&dblue,&dgreen,argv,argc);
	check_filenames(&filename,&graphicfile,&txtfile,argv,argc);



	int **grid,**change;			//grid- tablica zawieraj�ca liczby 0,1 kt�re oznaczaj� stan kom�rek (1-�ywa, 0-martwa)    chenge tablica w kt�rej b�dziemy oznacza� kom�rki do zmiany cyfr� 1

	//alokacja pami�ci dla tablic
	grid=malloc(sizeof(int*)*height);
	change=malloc(sizeof(int*)*height);	

	for(int i=0;i<height;++i)
	{
		grid[i]=malloc(sizeof(int)*width);
		change[i]=malloc(sizeof(int)*width);
	}
	//koniec alokacji pami�ci

	//ustawienie warto�ci tablic grid i change na 0
	for(int i=0;i<height;i++)
		{
    	    for(int j=0;j<width;j++)
    	    {
                grid[i][j]=0;
                change[i][j]=0;
    	    }
	}


	//wczytywanie danych z pliku o nazwie podanej przez u�ytkownika
	read_file(width,height,grid,filename);

	//tworzenie folderu do kt�rego b�d� zapisywane pliki wynikowe
	system("mkdir results");
	
	
	game(width,height,pixel_size,lred,lgreen,lblue,dred,dgreen,dblue,N,grid,change,txtfile,graphicfile);

	return 0;
}
