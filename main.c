#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"errors.h"
#include"file_reader.h"
#include"file_writer.h"
#include"neighbourhood.h"
#include"write.h"
#include"wait.h"
#include"settings.h"
#include"change.h"

int main(int argc, char *argv[]) 
{

/*ustawienie wartoœci domyœlnych dla zmiennych odpowiedzialnych za ustawienia*/
int x=20, y=20, pixel_size=1;	//x-rozmiar planszy(wspó³rzêdna x)   y-rozmiar planszy (wspó³rzêdna y)  pixel_size-rozmiar z ilu pikseli ma siê sk³adaæ bok komórki
char* filename;   // nazwa pliku z danymi
char name_graphic[]="image000.ppm";
char* graphicfile=name_graphic;	// nazwa pliku do którego zapisujemy grafikê
char name_txt[]="dane000.txt";
char* txtfile=name_txt;	//nazwa pliku do którego zapisujemy uk³ad komórek

int is_graphicname=0; 	//zmienna pomocnicza sprawdzaj¹ca czy u¿ytkownik poda³ nazwê wyjœciowego pliku graficzengo
int is_txtname=0;//zmienna pomocnicza sprawdzaj¹ca czy u¿ytkownik poda³ nazwê wyjœciowego pliku tekstowego

int lred=0,lgreen=0,lblue=0; //kolory ¿ywych komórek w modelu RGB
int dred=255,dgreen=255,dblue=255;//kolory martwych komórek w modelu RGB
int is_filename=0;//zmienna pomocnicza, która wskazuje czy zosta³ podany plik
int language=0;//zmienna wskazuj¹ca wybrany jêzyk domyœlanie angielski(wartoœæ 0)





//sprawdzenie czy u¿ytkownik wybra³ jêzyk. Jeœli tak to zmiana zmiennej wskazuj¹cej na jêzyk(0-angielski,1-polski,2-niemiecki,3-francuski,4-w³oski,5-hiszpañski)
check_language(argv,&language,argc);

//sprawdzenie czy u¿ytkownik poda³ ustawienia i wczytanie ich
check_gridsize(&x,&y,argv,argc,language);
check_graphicsettings(&pixel_size,&lred,&lblue,&lgreen,&dred,&dblue,&dgreen,argv,argc,language);
check_filenames(&filename,&graphicfile,&txtfile,&is_filename,&is_graphicname,&is_txtname,argv,argc,language);



if(is_filename==0) error_nofilename(language);//sprawdzenie czy u¿ytkownik poda³ plik z danymi

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
read_file(x,y,grid,filename,language);

//funkcja opóŸniaj¹ca, aby u¿ytkownik móg³ przeczytaæ informacjê o ewentualnych b³êdach
wait(5.0);

//wypisywanie pocz¹tkowego uk³adu komórek
write(x,y,grid);

//funkcja opóŸniaj¹ca dziêki której u¿ytkownik bêdzie przez chwilê móg³ przyjrzeæ siê uk³adowi komórek
wait(0.25);

//zmienne pomocnicze oznaczaj¹ce liczbê zmian oraz iloœæ ¿ywych komórek
        int how_many_change=0;
        int how_many_live=0;
    
    
    

//jeœli zosta³a podana nazwa pliku graficznego to program dopisuje numer obrazu i rozszerzenie  
if(is_graphicname==1) strcat(graphicfile,"000.ppm");
//mierzenie d³ugoœci nazwy pliku graficznego
int dl_grafika=strlen(graphicfile);

//jeœli zosta³a podana nazwa pliku tekstowego to program dopisuje numer pliku i rozszerzenie  
if(is_txtname==1) strcat(txtfile,"000.txt");
//mierzenie d³ugoœci nazwy pliku tekstowego
int dl_txt=strlen(txtfile);

    
//wypisanie pocz¹tkowego uk³adu komórek do pliku o nazwie podanej przez u¿ytkownika/domyœlnej
write_graphic(x,y,grid,pixel_size,graphicfile,lred,lgreen,lblue,dred,dgreen,dblue);
printf("\n");
write_txt(x,y,grid,txtfile);

//pêtla w której bêdziemy zmieniaæ stany komórek na podstawie ich stanu oraz iloœci s¹siadów
do{
	

	//zwiêkszenie numeru nazwy w pliku graficznym i tekstowym
	if(graphicfile[dl_grafika-6]=='9'&&graphicfile[dl_grafika-5]=='9'){graphicfile[dl_grafika-7]++;graphicfile[dl_grafika-6]='0';graphicfile[dl_grafika-5]='0'-1;}	
	if(graphicfile[dl_grafika-5]=='9'){graphicfile[dl_grafika-6]++;graphicfile[dl_grafika-5]='0'-1;}
	graphicfile[dl_grafika-5]++;

	if(txtfile[dl_txt-6]=='9'&&txtfile[dl_txt-5]=='9'){txtfile[dl_txt-7]++;txtfile[dl_txt-6]='0';txtfile[dl_txt-5]='0'-1;}	
	if(txtfile[dl_txt-5]=='9'){txtfile[dl_txt-6]++;txtfile[dl_txt-5]='0'-1;}
	txtfile[dl_txt-5]++;


        how_many_change=0;
        how_many_live=0;
    	
    	//oznaczenie komórek których stan siê zmienia
    	check_aimtochange(x,y,grid,change,&how_many_change);
    	
    	//zmiana stanów komórek
    	change_aims(x,y,grid,change,&how_many_live);

    	
       

	//wypisanie uk³adu komórek na konsoli
    write(x,y,grid);

    //zapisanie uk³adu komórek do pliku graficznego i testowego
	write_graphic(x,y,grid,pixel_size,graphicfile,lred,lgreen,lblue,dred,dgreen,dblue);
	write_txt(x,y,grid,txtfile);
	
	//sprawdzenie czy zapisano maksymaln¹ mo¿liw¹ liczbê plików
	error_size(graphicfile[dl_grafika-7],graphicfile[dl_grafika-6],graphicfile[dl_grafika-5],language);
	
	wait(0.25);
 	printf("\n\n\n\n");
    
} while(how_many_change>0&&how_many_live>0);


	return 0;
}
