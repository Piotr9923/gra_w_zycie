#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[]) 
{


//ustawienie wartoœci domyœlnych dla zmiennych
int x=20, y=20, pixel_size=1;	//x-rozmiar planszy(wspó³rzêdna x)   y-rozmiar planszy (wspó³rzêdna y)  pixel_size-rozmiar z ilu pikseli ma siê sk³adaæ bok komórki
char* filename;   // nazwa pliku z danymi
char nazwa_grafika[]="obraz000.ppm";
char* graphicfile=nazwa_grafika;	// nazwa pliku do którego zapisujemy grafikê
char nazwa_tekst[]="dane000.txt";
char* txtfile=nazwa_tekst;	//nazwa pliku do którego zapisujemy uk³ad komórek

int czy_nazwa=0; 	//zmienna pomocnicza sprawdzaj¹ca czy u¿ytkownik poda³ nazwê wyjœciowego pliku graficzengo
int czy_nazwa1=0;//zmienna pomocnicza sprawdzaj¹ca czy u¿ytkownik poda³ nazwê wyjœciowego pliku tekstowego


int lred=0,lgreen=0,lblue=0;
int dred=255,dgreen=255,dblue=255;
int is_filename=0;

//sprawdzanie czy u¿ytkownik poda³ wartoœci. Jeœli poda³ to zostan¹ zmienione z domyœlnych na takie jakie ¿yczy sobie u¿ytkownik
for(int i=1;i<argc;i++)
{
	if(strcmp(argv[i],"--filename")==0) {filename=argv[i+1];is_filename=1;}
	if(strcmp(argv[i],"--pixelsize")==0) {error_number("--pixelsize",argv[i+1]);pixel_size=atoi(argv[i+1]);}
	if(strcmp(argv[i],"--x")==0) {error_number("--x",argv[i+1]);error_number_size("--x",atoi(argv[i+1]),1,100);x=atoi(argv[i+1]);}
	if(strcmp(argv[i],"--y")==0) {error_number("--y",argv[i+1]);error_number_size("--y",atoi(argv[i+1]),1,100);y=atoi(argv[i+1]);}
	if(strcmp(argv[i],"--graphicfile")==0) {graphicfile=argv[i+1];czy_nazwa=1;}
	if(strcmp(argv[i],"--txtfile")==0){txtfile=argv[i+1];czy_nazwa1=1;}	
	if(strcmp(argv[i],"--livecolor")==0)
	{
		error_number("--livecolor",argv[i+1]);error_number("--livecolor",argv[i+2]);error_number("--livecolor",argv[i+3]);
		error_number_size("--livecolor",atoi(argv[i+1]),0,255);error_number_size("--livecolor",atoi(argv[i+2]),0,255);error_number_size("--livecolor",atoi(argv[i+3]),0,255);
		lred=atoi(argv[i+1]);lblue=atoi(argv[i+2]);lgreen=atoi(argv[i+3]);
	}
	
	if(strcmp(argv[i],"--deadcolor")==0)
	{
		error_number("--deadcolor",argv[i+1]);error_number("--deadcolor",argv[i+2]);error_number("--deadcolor",argv[i+3]);
		error_number_size("--deadcolor",atoi(argv[i+1]),0,255);error_number_size("--deadcolor",atoi(argv[i+2]),0,255);error_number_size("--deadcolor",atoi(argv[i+3]),0,255);
		dred=atoi(argv[i+1]);dblue=atoi(argv[i+2]);dgreen=atoi(argv[i+3]);
	}	
}
if(is_filename==0) error_nofilename();

int **tab,**zmiana;			//tab- tablica zawieraj¹ca liczby 0,1 które oznaczaj¹ stan komórek (1-¿ywa, 0-martwa)    zmiana tablica w której bêdziemy oznaczaæ komórki do zmiany cyfr¹ 1

//alokacja pamiêci dla tablic
tab=malloc(sizeof(int*)*y);
zmiana=malloc(sizeof(int*)*y);	

for(int i=0;i<y;++i)
{
tab[i]=malloc(sizeof(int)*x);
zmiana[i]=malloc(sizeof(int)*x);

}
//koniec alokacji pamiêci

//ustawienie wartoœci tablica tab i zmiana jako 0
for(int i=0;i<y;i++)
{
        for(int j=0;j<x;j++)
        {
                tab[i][j]=0;
                zmiana[i][j]=0;
              
        }
}


//wczytywanie danych z pliku o nazwie podanej przez u¿ytkownika
wczytaj_dane(x,y,tab,filename);

//wypisywanie stanu pocz¹tkowego tabliy
wypisz(x,y,tab);
exit(0);
//funkcja opóŸniaj¹ca dziêki której u¿ytkownik bêdzie przez chwilê móg³ przyjrzeæ siê uk³adowi komórek
czekaj(0.5);

//zmienne pomocnicze oznaczaj¹ce liczbê zmian oraz iloœæ ¿ywych komórek
        int liczbazmian=0;
        int ile_zywych=0;
    
    
    

	//jeœli zosta³a podana nazwa pliku graficznego to program dopisuje numer obrazu i rozszerzenie  
if(czy_nazwa==1) strcat(graphicfile,"000.ppm");
int dl_grafika=strlen(graphicfile);

	//jeœli zosta³a podana nazwa pliku tekstowego to program dopisuje numer pliku i rozszerzenie  
if(czy_nazwa1==1) strcat(txtfile,"000.txt");
int dl_txt=strlen(txtfile);

    
//wypisanie pocz¹tkowego uk³adu komórek do pliku o nazwie podanej przez u¿ytkownika/domyœlnej
 grafika(x,y,tab,pixel_size,graphicfile,lred,lgreen,lblue,dred,dgreen,dblue);
 printf("\n");
tekst(x,y,tab,txtfile);

//pêtla w której bêdziemy zmieniaæ stany komórek na podstawie ich stany oraz iloœci s¹siadów
do{
	

	//zwiêkszenie numeru grafiki i pliku tekstowego
	if(graphicfile[dl_grafika-6]=='9'&&graphicfile[dl_grafika-5]=='9'){graphicfile[dl_grafika-7]++;graphicfile[dl_grafika-6]='0';graphicfile[dl_grafika-5]='0'-1;}	
	if(graphicfile[dl_grafika-5]=='9'){graphicfile[dl_grafika-6]++;graphicfile[dl_grafika-5]='0'-1;}
	graphicfile[dl_grafika-5]++;

	if(txtfile[dl_txt-6]=='9'&&txtfile[dl_txt-5]=='9'){txtfile[dl_txt-7]++;txtfile[dl_txt-6]='0';txtfile[dl_txt-5]='0'-1;}	
	if(txtfile[dl_txt-5]=='9'){txtfile[dl_txt-6]++;txtfile[dl_txt-5]='0'-1;}
	txtfile[dl_txt-5]++;





        liczbazmian=0;
        ile_zywych=0;
    
        for(int i=0;i<y;i++)
        {
                for(int j=0;j<x;j++)
                {
        
                      int ile_s=ile_sasiadow(x,y,tab,i,j);
                                           
                        if(tab[i][j]==0&&ile_s==3) {zmiana[i][j]=1;liczbazmian++;};
                        if(tab[i][j]==1&&(ile_s<2||ile_s>3)){zmiana[i][j]=1;liczbazmian++;}
			
                }
        }


        for(int i=0;i<y;i++)
        {
                for(int j=0;j<x;j++)
                {

                        if(zmiana[i][j]==1&&tab[i][j]==0) {tab[i][j]=1;zmiana[i][j]=0;}
                        if(zmiana[i][j]==1&&tab[i][j]==1) {tab[i][j]=0;zmiana[i][j]=0;}
                        if(tab[i][j]==1) ile_zywych++;
                }
        }

	//wypisanie uk³adu komórek na konsoli
    wypisz(x,y,tab);
        
	grafika(x,y,tab,pixel_size,graphicfile,lred,lgreen,lblue,dred,dgreen,dblue);
	tekst(x,y,tab,txtfile);
	
	error_size(graphicfile[dl_grafika-7],graphicfile[dl_grafika-6],graphicfile[dl_grafika-5]);
	
	czekaj(0.25);
 	printf("\n\n\n\n");
    
} while(liczbazmian>0&&ile_zywych>0);


	return 0;
}
