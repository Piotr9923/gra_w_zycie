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

/*ustawienie warto�ci domy�lnych dla zmiennych odpowiedzialnych za ustawienia*/
int x=20, y=20, pixel_size=1;	//x-rozmiar planszy(wsp�rz�dna x)   y-rozmiar planszy (wsp�rz�dna y)  pixel_size-rozmiar z ilu pikseli ma si� sk�ada� bok kom�rki
char* filename;   // nazwa pliku z danymi
char name_graphic[]="image000.ppm";
char* graphicfile=name_graphic;	// nazwa pliku do kt�rego zapisujemy grafik�
char name_txt[]="dane000.txt";
char* txtfile=name_txt;	//nazwa pliku do kt�rego zapisujemy uk�ad kom�rek

int is_graphicname=0; 	//zmienna pomocnicza sprawdzaj�ca czy u�ytkownik poda� nazw� wyj�ciowego pliku graficzengo
int is_txtname=0;//zmienna pomocnicza sprawdzaj�ca czy u�ytkownik poda� nazw� wyj�ciowego pliku tekstowego

int lred=0,lgreen=0,lblue=0; //kolory �ywych kom�rek w modelu RGB
int dred=255,dgreen=255,dblue=255;//kolory martwych kom�rek w modelu RGB
int is_filename=0;//zmienna pomocnicza, kt�ra wskazuje czy zosta� podany plik
int language=0;//zmienna wskazuj�ca wybrany j�zyk domy�lanie angielski(warto�� 0)





//sprawdzenie czy u�ytkownik wybra� j�zyk. Je�li tak to zmiana zmiennej wskazuj�cej na j�zyk(0-angielski,1-polski,2-niemiecki,3-francuski,4-w�oski,5-hiszpa�ski)
check_language(argv,&language,argc);

//sprawdzenie czy u�ytkownik poda� ustawienia i wczytanie ich
check_gridsize(&x,&y,argv,argc,language);
check_graphicsettings(&pixel_size,&lred,&lblue,&lgreen,&dred,&dblue,&dgreen,argv,argc,language);
check_filenames(&filename,&graphicfile,&txtfile,&is_filename,&is_graphicname,&is_txtname,argv,argc,language);



if(is_filename==0) error_nofilename(language);//sprawdzenie czy u�ytkownik poda� plik z danymi

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
read_file(x,y,grid,filename,language);

//funkcja op�niaj�ca, aby u�ytkownik m�g� przeczyta� informacj� o ewentualnych b��dach
wait(5.0);

//wypisywanie pocz�tkowego uk�adu kom�rek
write(x,y,grid);

//funkcja op�niaj�ca dzi�ki kt�rej u�ytkownik b�dzie przez chwil� m�g� przyjrze� si� uk�adowi kom�rek
wait(0.25);

//zmienne pomocnicze oznaczaj�ce liczb� zmian oraz ilo�� �ywych kom�rek
        int how_many_change=0;
        int how_many_live=0;
    
    
    

//je�li zosta�a podana nazwa pliku graficznego to program dopisuje numer obrazu i rozszerzenie  
if(is_graphicname==1) strcat(graphicfile,"000.ppm");
//mierzenie d�ugo�ci nazwy pliku graficznego
int dl_grafika=strlen(graphicfile);

//je�li zosta�a podana nazwa pliku tekstowego to program dopisuje numer pliku i rozszerzenie  
if(is_txtname==1) strcat(txtfile,"000.txt");
//mierzenie d�ugo�ci nazwy pliku tekstowego
int dl_txt=strlen(txtfile);

    
//wypisanie pocz�tkowego uk�adu kom�rek do pliku o nazwie podanej przez u�ytkownika/domy�lnej
write_graphic(x,y,grid,pixel_size,graphicfile,lred,lgreen,lblue,dred,dgreen,dblue);
printf("\n");
write_txt(x,y,grid,txtfile);

//p�tla w kt�rej b�dziemy zmienia� stany kom�rek na podstawie ich stanu oraz ilo�ci s�siad�w
do{
	

	//zwi�kszenie numeru nazwy w pliku graficznym i tekstowym
	if(graphicfile[dl_grafika-6]=='9'&&graphicfile[dl_grafika-5]=='9'){graphicfile[dl_grafika-7]++;graphicfile[dl_grafika-6]='0';graphicfile[dl_grafika-5]='0'-1;}	
	if(graphicfile[dl_grafika-5]=='9'){graphicfile[dl_grafika-6]++;graphicfile[dl_grafika-5]='0'-1;}
	graphicfile[dl_grafika-5]++;

	if(txtfile[dl_txt-6]=='9'&&txtfile[dl_txt-5]=='9'){txtfile[dl_txt-7]++;txtfile[dl_txt-6]='0';txtfile[dl_txt-5]='0'-1;}	
	if(txtfile[dl_txt-5]=='9'){txtfile[dl_txt-6]++;txtfile[dl_txt-5]='0'-1;}
	txtfile[dl_txt-5]++;


        how_many_change=0;
        how_many_live=0;
    	
    	//oznaczenie kom�rek kt�rych stan si� zmienia
    	check_aimtochange(x,y,grid,change,&how_many_change);
    	
    	//zmiana stan�w kom�rek
    	change_aims(x,y,grid,change,&how_many_live);

    	
       

	//wypisanie uk�adu kom�rek na konsoli
    write(x,y,grid);

    //zapisanie uk�adu kom�rek do pliku graficznego i testowego
	write_graphic(x,y,grid,pixel_size,graphicfile,lred,lgreen,lblue,dred,dgreen,dblue);
	write_txt(x,y,grid,txtfile);
	
	//sprawdzenie czy zapisano maksymaln� mo�liw� liczb� plik�w
	error_size(graphicfile[dl_grafika-7],graphicfile[dl_grafika-6],graphicfile[dl_grafika-5],language);
	
	wait(0.25);
 	printf("\n\n\n\n");
    
} while(how_many_change>0&&how_many_live>0);


	return 0;
}
