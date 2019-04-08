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

/*ustawienie wartoœci domyœlnych dla zmiennych odpowiedzialnych za ustawienia*/
int x=20, y=20, pixel_size=1;	//x-rozmiar planszy(wspó³rzêdna x)   y-rozmiar planszy (wspó³rzêdna y)  pixel_size-rozmiar z ilu pikseli ma siê sk³adaæ bok komórki
char* filename;   // nazwa pliku z danymi
char name_graphic[]="image";
char* graphicfile=name_graphic;	// nazwa pliku do którego zapisujemy grafikê
char name_txt[]="cells";
char* txtfile=name_txt;	//nazwa pliku do którego zapisujemy uk³ad komórek

int lred=0,lgreen=0,lblue=0; //kolory ¿ywych komórek w modelu RGB
int dred=255,dgreen=255,dblue=255;//kolory martwych komórek w modelu RGB

int N=1000;//liczba generacji



//sprawdzenie czy u¿ytkownik wybra³ jêzyk. 
check_language(argv,argc);

//sprawdzenie czy u¿ytkownik poda³ ustawienia i wczytanie ich
check_gridsize(&x,&y,&N,argv,argc);
check_graphicsettings(&pixel_size,&lred,&lblue,&lgreen,&dred,&dblue,&dgreen,argv,argc);
check_filenames(&filename,&graphicfile,&txtfile,argv,argc);



int **grid,**change;			//grid- tablica zawieraj¹ca liczby 0,1 które oznaczaj¹ stan komórek (1-¿ywa, 0-martwa)    chenge tablica w której bêdziemy oznaczaæ komórki do zmiany cyfr¹ 1

//alokacja pamiêci dla tablic
grid=malloc(sizeof(int*)*y);
change=malloc(sizeof(int*)*y);	

for(int i=0;i<y;++i)
{
grid[i]=malloc(sizeof(int)*x);
change[i]=malloc(sizeof(int)*x);

}
//koniec alokacji pamiêci

//ustawienie wartoœci tablic grid i change na 0
for(int i=0;i<y;i++)
{
        for(int j=0;j<x;j++)
        {
                grid[i][j]=0;
                change[i][j]=0;
        }
}


//wczytywanie danych z pliku o nazwie podanej przez u¿ytkownika
read_file(x,y,grid,filename);

//funkcja opóŸniaj¹ca, aby u¿ytkownik móg³ przeczytaæ informacjê o ewentualnych b³êdach
Sleep(5.0);

system("mkdir results");

game(x,y,pixel_size,lred,lgreen,lblue,dred,dgreen,dblue,N,grid,change,txtfile,graphicfile);


free(grid);
free(change);


	return 0;
}
