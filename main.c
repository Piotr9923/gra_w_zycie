/*do zrobienia:
- doda� obs�ug� b��d�w;
- doda� liczenie wczytanych punkt�w (np. b��d:   punkt nr x  (,) znajduj�cy si� w pliku z danymi jest nie poprawny);
- doda� instrukcj� goto, aby nie zapisywa� b��dnych plik�w do tablicy;
- doda� b��d ko�czenia programu gdy plik wyj�ciowy b�dzie mia� nazw� z numerami 999
*/


/*W programie zmienne, na kr�te wp�yw ma u�ytkownik zosta�y zapisane za pomoc� angielskich s��w, 
co pomaga programi�cie w odr�nieniu zmiennych odpowiedzialnych za ustawienia od pozosta�ych zmiennych */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[]) 
{


//ustawienie warto�ci domy�lnych dla zmiennych
int x=20, y=20, pixel_size=1;	//x-rozmiar planszy(wsp�rz�dna x)   y-rozmiar planszy (wsp�rz�dna y)  pixel_size-rozmiar z ilu pikseli ma si� sk�ada� bok kom�rki
char* filename;   // nazwa pliku z danymi
char nazwa_grafika[]="obraz000.ppm";
char* graphicfile=nazwa_grafika;	// nazwa pliku do kt�rego zapisujemy grafik�
char nazwa_tekst[]="dane000.txt";
char* txtfile=nazwa_tekst;	//nazwa pliku do kt�rego zapisujemy uk�ad kom�rek

int czy_nazwa=0; 	//zmienna pomocnicza sprawdzaj�ca czy u�ytkownik poda� nazw� wyj�ciowego pliku graficzengo
int czy_nazwa1=0;//zmienna pomocnicza sprawdzaj�ca czy u�ytkownik poda� nazw� wyj�ciowego pliku tekstowego


int lred=0,lgreen=0,lblue=0;
int dred=255,dgreen=255,dblue=255;


//sprawdzanie czy u�ytkownik poda� warto�ci. Je�li poda� to zostan� zmienione z domy�lnych na takie jakie �yczy sobie u�ytkownik
for(int i=1;i<argc;i++)
{
	if(strcmp(argv[i],"--filename")==0) filename=argv[i+1];
	if(strcmp(argv[i],"--pixelsize")==0) pixel_size=atoi(argv[i+1]);
	if(strcmp(argv[i],"--x")==0) x=atoi(argv[i+1]);
	if(strcmp(argv[i],"--y")==0) y=atoi(argv[i+1]);
	if(strcmp(argv[i],"--graphicfile")==0) {graphicfile=argv[i+1];czy_nazwa=1;}
	if(strcmp(argv[i],"--txtfile")==0){txtfile=argv[i+1];czy_nazwa1=1;}	
	if(strcmp(argv[i],"--livecolor")==0){lred=atoi(argv[i+1]);lblue=atoi(argv[i+2]);lgreen=atoi(argv[i+3]);}
	if(strcmp(argv[i],"--deadcolor")==0){dred=atoi(argv[i+1]);dblue=atoi(argv[i+2]);dgreen=atoi(argv[i+3]);}	
}

int **tab,**zmiana;			//tab- tablica zawieraj�ca liczby 0,1 kt�re oznaczaj� stan kom�rek (1-�ywa, 0-martwa)    zmiana tablica w kt�rej b�dziemy oznacza� kom�rki do zmiany cyfr� 1

//alokacja pami�ci dla tablic
tab=malloc(sizeof(int*)*y);
zmiana=malloc(sizeof(int*)*y);	

for(int i=0;i<y;++i)
{
tab[i]=malloc(sizeof(int)*x);
zmiana[i]=malloc(sizeof(int)*x);

}
//koniec alokacji pami�ci

//ustawienie warto�ci tablica tab i zmiana jako 0
for(int i=0;i<y;i++)
{
        for(int j=0;j<x;j++)
        {
                tab[i][j]=0;
                zmiana[i][j]=0;
              
        }
}
//wczytywanie danych z pliku o nazwie podanej przez u�ytkownika
wczytaj_dane(x,y,tab,filename);

//wypisywanie stanu pocz�tkowego tabliy
wypisz(x,y,tab);

//funkcja op�niaj�ca dzi�ki kt�rej u�ytkownik b�dzie przez chwil� m�g� przyjrze� si� uk�adowi kom�rek
czekaj(0.5);

//zmienne pomocnicze oznaczaj�ce liczb� zmian oraz ilo�� �ywych kom�rek
        int liczbazmian=0;
        int ile_zywych=0;
    
    
    

	//je�li zosta�a podana nazwa pliku graficznego to program dopisuje numer obrazu i rozszerzenie  
if(czy_nazwa==1) strcat(graphicfile,"000.ppm");
int dl_grafika=strlen(graphicfile);

	//je�li zosta�a podana nazwa pliku tekstowego to program dopisuje numer pliku i rozszerzenie  
if(czy_nazwa1==1) strcat(txtfile,"000.txt");
int dl_txt=strlen(txtfile);

    
//wypisanie pocz�tkowego uk�adu kom�rek do pliku o nazwie podanej przez u�ytkownika/domy�lnej
 grafika(x,y,tab,pixel_size,graphicfile,lred,lgreen,lblue,dred,dgreen,dblue);
 printf("\n");
tekst(x,y,tab,txtfile);

//p�tla w kt�rej b�dziemy zmienia� stany kom�rek na podstawie ich stany oraz ilo�ci s�siad�w
do{
	

	//zwi�kszenie numeru grafiki i pliku tekstowego
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

	//wypisanie uk�adu kom�rek na konsoli
    wypisz(x,y,tab);
        
    printf("\nTwoja nazwa to: %s, %s\n",graphicfile,txtfile);
	grafika(x,y,tab,pixel_size,graphicfile,lred,lgreen,lblue,dred,dgreen,dblue);
	tekst(x,y,tab,txtfile);
	

	czekaj(0.25);
 	printf("\n\n\n\n");
    
} while(liczbazmian>0&&ile_zywych>0);


	return 0;
}
