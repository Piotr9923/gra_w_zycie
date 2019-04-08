#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>

#include "file_reader.h"
#include "settings.h"
#include "game.h"
#include"main.h"

enum GRID **grid1;

int main(int argc, char *argv[]) 
{

/*ustawienie warto�ci domy�lnych dla zmiennych odpowiedzialnych za ustawienia*/
int x=20, y=20, pixel_size=1;	//x-rozmiar planszy(wsp�rz�dna x)   y-rozmiar planszy (wsp�rz�dna y)  pixel_size-rozmiar z ilu pikseli ma si� sk�ada� bok kom�rki
char* filename;   // nazwa pliku z danymi
char name_graphic[]="image";
char* graphicfile=name_graphic;	// nazwa pliku do kt�rego zapisujemy grafik�
char name_txt[]="cells";
char* txtfile=name_txt;	//nazwa pliku do kt�rego zapisujemy uk�ad kom�rek

int lred=0,lgreen=0,lblue=0; //kolory �ywych kom�rek w modelu RGB
int dred=255,dgreen=255,dblue=255;//kolory martwych kom�rek w modelu RGB

int N=1000;//liczba generacji



//sprawdzenie czy u�ytkownik wybra� j�zyk. 
check_language(argv,argc);

//sprawdzenie czy u�ytkownik poda� ustawienia i wczytanie ich
check_gridsize(&x,&y,&N,argv,argc);
check_graphicsettings(&pixel_size,&lred,&lblue,&lgreen,&dred,&dblue,&dgreen,argv,argc);
check_filenames(&filename,&graphicfile,&txtfile,argv,argc);



int **grid,**change;			//grid- tablica zawieraj�ca liczby 0,1 kt�re oznaczaj� stan kom�rek (1-�ywa, 0-martwa)    chenge tablica w kt�rej b�dziemy oznacza� kom�rki do zmiany cyfr� 1

//alokacja pami�ci dla tablic
grid=malloc(sizeof(int*)*y);
change=malloc(sizeof(int*)*y);	

for(int i=0;i<y;++i)
{
grid[i]=malloc(sizeof(int)*x);
change[i]=malloc(sizeof(int)*x);

}
//koniec alokacji pami�ci

//ustawienie warto�ci tablic grid i change na 0
for(int i=0;i<y;i++)
{
        for(int j=0;j<x;j++)
        {
                grid[i][j]=0;
                change[i][j]=0;
        }
}


//wczytywanie danych z pliku o nazwie podanej przez u�ytkownika
read_file(x,y,grid,filename);

//funkcja op�niaj�ca, aby u�ytkownik m�g� przeczyta� informacj� o ewentualnych b��dach
Sleep(5.0);

system("mkdir results");

game(x,y,pixel_size,lred,lgreen,lblue,dred,dgreen,dblue,N,grid,change,txtfile,graphicfile);


free(grid);
free(change);


	return 0;
}
