#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"settings.h"
#include"errors.h"

//stworzenie zmiennej globalnej wskazuj¹cej jêzyk i ustawienie jej jako wartoœæ domyœlna (j. angielski)
enum L language=en;

//sprawdzenie czy u¿ytkownik wybra³ jêzyk
void check_language(char*argv[],int argc)
{
	if(argc>1&&strcmp(argv[1],"--language")==0) 
	{
		if(argc==2)error_falgargument("--language");
		
		if(strcmp(argv[2],"en")==0) language=en;
		else if(strcmp(argv[2],"pl")==0) language=pl;
		else if(strcmp(argv[2],"de")==0) language=de;
		else if(strcmp(argv[2],"fr")==0) language=fr;
		else if(strcmp(argv[2],"it")==0) language=it;
		else if(strcmp(argv[2],"es")==0) language=es;
		else printf("I do not understand: %s. I select default language - English\n",argv[2]);
	}	
}


//sprawdzenie czy u¿ytkownik poda³ wymiary planszy oraz iloœæ generacji
void check_gridsize(int*x,int*y,int*N,char*argv[],int argc)
{
	for(int i=1;i<argc;i++)
	{
		if(strcmp(argv[i],"--width")==0) {if(i+1>=argc)error_falgargument("--x");error_number("--x",argv[i+1]);error_number_size("--x",atoi(argv[i+1]),1,100);*x=atoi(argv[i+1]);}
		if(strcmp(argv[i],"--height")==0) {if(i+1>=argc)error_falgargument("--y");error_number("--y",argv[i+1]);error_number_size("--y",atoi(argv[i+1]),1,100);*y=atoi(argv[i+1]);}
		if(strcmp(argv[i],"--N")==0) {if(i+1>=argc)error_falgargument("--N");error_number("--N",argv[i+1]);*N=atoi(argv[i+1]);}
	}
}


//sprawdzenie czy u¿ytkownik poda³ ustawienia grafiki: rozmiar pikseli, kolory ¿ywych i martwych komórek
void check_graphicsettings(int*pixel_size,int*lred,int*lblue,int*lgreen,int*dred,int*dblue,int*dgreen,char*argv[],int argc)
{
	for(int i=1;i<argc;i++)
	{
		if(strcmp(argv[i],"--pixelsize")==0) {if(i+1>=argc)error_falgargument("--pixelsize");error_number("--pixelsize",argv[i+1]);*pixel_size=atoi(argv[i+1]);}
		if(strcmp(argv[i],"--livecolor")==0)
		{
			if(i+3>=argc)error_falgargument("--livecolor");
			error_number("--livecolor",argv[i+1]);error_number("--livecolor",argv[i+2]);error_number("--livecolor",argv[i+3]);
			error_number_size("--livecolor",atoi(argv[i+1]),0,255);error_number_size("--livecolor",atoi(argv[i+2]),0,255);error_number_size("--livecolor",atoi(argv[i+3]),0,255);
			*lred=atoi(argv[i+1]);*lblue=atoi(argv[i+2]);*lgreen=atoi(argv[i+3]);
		}
	
		if(strcmp(argv[i],"--deadcolor")==0)
		{
			if(i+3>=argc)error_falgargument("--deadcolor");
			error_number("--deadcolor",argv[i+1]);error_number("--deadcolor",argv[i+2]);error_number("--deadcolor",argv[i+3]);
			error_number_size("--deadcolor",atoi(argv[i+1]),0,255);error_number_size("--deadcolor",atoi(argv[i+2]),0,255);error_number_size("--deadcolor",atoi(argv[i+3]),0,255);
			*dred=atoi(argv[i+1]);*dblue=atoi(argv[i+2]);*dgreen=atoi(argv[i+3]);
		}	
	}
}


//sprawdzenie czy u¿ytkownik poda³ nazwy plików: z danymi oraz wynikowych
void check_filenames(char**filename,char**graphicfile,char**txtfile,char*argv[],int argc)
{
	int is_filename=0;//zmienna pomocnicza, która wskazuje czy zosta³ podany plik

	for(int i=1;i<argc;i++)
	{
		if(strcmp(argv[i],"--filename")==0) {if(i+1>=argc)error_falgargument("--filename");*filename=argv[i+1];is_filename=1;}
		if(strcmp(argv[i],"--graphicfile")==0) {if(i+1>=argc)error_falgargument("--graphicfile");*graphicfile=argv[i+1];}
		if(strcmp(argv[i],"--txtfile")==0){if(i+1>=argc)error_falgargument("--txtfile");*txtfile=argv[i+1];}	
	}

	if(is_filename==0) error_nofilename();//sprawdzenie czy u¿ytkownik poda³ plik z danymi
}
