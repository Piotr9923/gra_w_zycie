#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

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
if(strcmp(argv[1],"--language")==0) 
{
	if(strcmp(argv[2],"pl")==0) language=1;
	else if(strcmp(argv[2],"de")==0) language=2;
	else if(strcmp(argv[2],"fr")==0) language=3;
	else if(strcmp(argv[2],"it")==0) language=4;
	else if(strcmp(argv[2],"es")==0) language=5;
	else printf("I do not understand: %s. I select default language - English\n",argv[2]);
}

/*sprawdzanie czy u�ytkownik poda� warto�ci dla zmiennych odpowiedzialnych za ustawienia. Je�li poda� to zostan� zmienione z domy�lnych na takie jakie �yczy sobie u�ytkownik*/
for(int i=1;i<argc;i++)
{
	if(strcmp(argv[i],"--filename")==0) {filename=argv[i+1];is_filename=1;}
	if(strcmp(argv[i],"--pixelsize")==0) {error_number("--pixelsize",argv[i+1],language);pixel_size=atoi(argv[i+1]);}
	if(strcmp(argv[i],"--x")==0) {error_number("--x",argv[i+1],language);error_number_size("--x",atoi(argv[i+1]),1,100,language);x=atoi(argv[i+1]);}
	if(strcmp(argv[i],"--y")==0) {error_number("--y",argv[i+1]);error_number_size("--y",atoi(argv[i+1]),1,100);y=atoi(argv[i+1]);}
	if(strcmp(argv[i],"--graphicfile")==0) {graphicfile=argv[i+1];is_graphicname=1;}
	if(strcmp(argv[i],"--txtfile")==0){txtfile=argv[i+1];is_txtname=1;}	
	if(strcmp(argv[i],"--livecolor")==0)
	{
		error_number("--livecolor",argv[i+1],language);error_number("--livecolor",argv[i+2],language);error_number("--livecolor",argv[i+3],language);
		error_number_size("--livecolor",atoi(argv[i+1]),0,255,language);error_number_size("--livecolor",atoi(argv[i+2]),0,255,language);error_number_size("--livecolor",atoi(argv[i+3]),0,255,language);
		lred=atoi(argv[i+1]);lblue=atoi(argv[i+2]);lgreen=atoi(argv[i+3]);
	}
	
	if(strcmp(argv[i],"--deadcolor")==0)
	{
		error_number("--deadcolor",argv[i+1],language);error_number("--deadcolor",argv[i+2],language);error_number("--deadcolor",argv[i+3],language);
		error_number_size("--deadcolor",atoi(argv[i+1]),0,255,language);error_number_size("--deadcolor",atoi(argv[i+2]),0,255,language);error_number_size("--deadcolor",atoi(argv[i+3]),0,255,language);
		dred=atoi(argv[i+1]);dblue=atoi(argv[i+2]);dgreen=atoi(argv[i+3]);
	}	
}


if(is_filename==0) error_nofilename(language);//sprawdzenie czy u�ytkownik poda� plik z danymi

int **grid,**change;			//grid- tablica zawieraj�ca liczby 0,1 kt�re oznaczaj� stan kom�rek (1-�ywa, 0-martwa)    zmiana tablica w kt�rej b�dziemy oznacza� kom�rki do zmiany cyfr� 1

//alokacja pami�ci dla tablic
grid=malloc(sizeof(int*)*y);
change=malloc(sizeof(int*)*y);	

for(int i=0;i<y;++i)
{
grid[i]=malloc(sizeof(int)*x);
change[i]=malloc(sizeof(int)*x);

}
//koniec alokacji pami�ci

//ustawienie warto�ci tablica tab i zmiana jako 0
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

//wypisywanie stanu pocz�tkowego tabliy
write(x,y,grid);
exit(0);
//funkcja op�niaj�ca dzi�ki kt�rej u�ytkownik b�dzie przez chwil� m�g� przyjrze� si� uk�adowi kom�rek
wait(0.5);

//zmienne pomocnicze oznaczaj�ce liczb� zmian oraz ilo�� �ywych kom�rek
        int how_many_change=0;
        int how_many_live=0;
    
    
    

	//je�li zosta�a podana nazwa pliku graficznego to program dopisuje numer obrazu i rozszerzenie  
if(is_graphicname==1) strcat(graphicfile,"000.ppm");
int dl_grafika=strlen(graphicfile);

	//je�li zosta�a podana nazwa pliku tekstowego to program dopisuje numer pliku i rozszerzenie  
if(is_txtname==1) strcat(txtfile,"000.txt");
int dl_txt=strlen(txtfile);

    
//wypisanie pocz�tkowego uk�adu kom�rek do pliku o nazwie podanej przez u�ytkownika/domy�lnej
 write_graphic(x,y,grid,pixel_size,graphicfile,lred,lgreen,lblue,dred,dgreen,dblue);
 printf("\n");
write_txt(x,y,grid,txtfile);

//p�tla w kt�rej b�dziemy zmienia� stany kom�rek na podstawie ich stany oraz ilo�ci s�siad�w
do{
	

	//zwi�kszenie numeru nqawy w pliku graficznym i tekstowym
	if(graphicfile[dl_grafika-6]=='9'&&graphicfile[dl_grafika-5]=='9'){graphicfile[dl_grafika-7]++;graphicfile[dl_grafika-6]='0';graphicfile[dl_grafika-5]='0'-1;}	
	if(graphicfile[dl_grafika-5]=='9'){graphicfile[dl_grafika-6]++;graphicfile[dl_grafika-5]='0'-1;}
	graphicfile[dl_grafika-5]++;

	if(txtfile[dl_txt-6]=='9'&&txtfile[dl_txt-5]=='9'){txtfile[dl_txt-7]++;txtfile[dl_txt-6]='0';txtfile[dl_txt-5]='0'-1;}	
	if(txtfile[dl_txt-5]=='9'){txtfile[dl_txt-6]++;txtfile[dl_txt-5]='0'-1;}
	txtfile[dl_txt-5]++;





        how_many_change=0;
        how_many_live=0;
    
        for(int i=0;i<y;i++)
        {
                for(int j=0;j<x;j++)
                {
                      int how_many_neighbourhood=check_neighbourhood(x,y,grid,i,j);
                                           
                        if(grid[i][j]==0&&how_many_neighbourhood==3) {change[i][j]=1;how_many_change++;};
                        if(grid[i][j]==1&&(how_many_neighbourhood<2||how_many_neighbourhood>3)){change[i][j]=1;how_many_change++;}
                }
        }


        for(int i=0;i<y;i++)
        {
                for(int j=0;j<x;j++)
                {

                        if(change[i][j]==1&&grid[i][j]==0) {grid[i][j]=1;change[i][j]=0;}
                        if(change[i][j]==1&&grid[i][j]==1) {grid[i][j]=0;change[i][j]=0;}
                        if(grid[i][j]==1) how_many_live++;
                }
        }

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
