#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"errors.h"
//funkcja zg�aszaj�ca b��d, gdy plik wyj�ciowy ko�czy si� cyframi"999", co jest maksymaln� liczb� plik�w wyj�ciowych
void error_size(char a, char b,char c,int language)
{
	if(a=='9'&&b=='9'&&c=='9')
	{
		if(language==0)printf("The program can not write more cells, so ending its action!!\n");
		if(language==1)printf("Program nie moze zapisac wiecej ukladow komorek wiec konczy swoje dzialanie!!\n");
		if(language==2)printf("Das Programm kann nicht mehr Zellen schreiben und damit seine Aktion beenden!!\n");
		if(language==3)printf("Le programme ne peut pas ecrire plus de cellules, mettant ainsi fin a son action!!\n");
		if(language==4)printf("Il programma non puo scrivere piu celle, quindi termina la sua azione!!\n");
		if(language==5)printf("El programa no puede escribir mas celdas, por lo que finaliza su accion!!\n");
		exit(0);
	}
}

//funkcja zg�aszaj�ca b��d, gdy podana warto�� powinna by� liczb�, a ni� nie jest
void error_number(char*flagname,char*number,int language)
{
	int dl=strlen(number);
	int ile=0;
	
	for(int i=0;i<dl;i++)
	if(isdigit(number[i])!=0) ile++;
	
	
	if(ile!=dl)
	{
		if(language==0)printf("After %s you wrote %s. It is not a number!!\n",flagname,number);
		if(language==1)printf("Po argumencie %s podales wartosc %s, ktora nie jest liczba!!\n",flagname,number);
		if(language==2)printf("Nach dem %s, du %s geschreiben. Es ist keine Nummer!!\n",flagname,number);
		if(language==3)printf("Apres %s tu as �crit %s. Ce n'est pas un chiffre!!\n",flagname,number);
		if(language==4)printf("After %s Hai scritto %s. Non e un numero!!\n",flagname,number);
		if(language==5)printf("Despu�s de la %s que escribiste %s. No es un numero!!\n",flagname,number);
		
		exit(0);
	}
}


//funkcja zg�aszaj�ca b��d, gdy nie podano nazwy z plikiem danych
void error_nofilename(int language)
{
	
	if(language==0)printf("You did not enter the data file name !! Do it using --filename!!\n");
	if(language==1)printf("Nie podales nazwy pliku z danymi!! Zrob to przy uzyciu --filename !!\n");
	if(language==2)printf("Sie haben den Dateinamen nicht eingegeben!! Du machst es mit --filename!!\n");
	if(language==3)printf("Vous n'avez pas saisi le nom du fichier de donnees!! Faites-le en utilisant --filename!!\n");
	if(language==4)printf("Non e stato immesso il nome del file di dati!! Farlo usando --filename!!\n");
	if(language==5)printf("No ha introducir el nombre del archivo de datos!! Hazlo usando --filename!!\n");

	
	exit(0);
	
}
//funkcja zg�aszaj�ca b��d, gdy nie mo�na otworzy� pliku z danymi
void error_nofoundfile(char*name,int language)
{
	if(language==0)printf("I can not open the file: %s!!",name);
	if(language==1)printf("Nie moge otworzyc pliku o nazwie: %s!\n!",name);
	if(language==2)printf("Ich kann die Datei nicht offnen: %s!!\n",name);
	if(language==3)printf("Je ne peux pas ouvrir le fichier: %s!!\n",name);
	if(language==4)printf("Non riesco ad aprire il file: %s!!\n",name);
	if(language==5)printf("No puedo abrir el archivo: %s!!\n",name);
	
	exit(0);
	
}
//funkcja sprawdzaj�ca czy wsp�rz�dne punktu s� poprawne
int error_point(int number,char* a,char* b,int language)
{
	int dl1=strlen(a);
	int dl2=strlen(b);
	int ile1=0,ile2=0;
	
	for(int i=0;i<dl1;i++) if(isdigit(a[i])!=0) ile1++;
	for(int i=0;i<dl2;i++) if(isdigit(b[i])!=0) ile2++;

	if(ile1!=dl1||ile2!=dl2)
	{
		if(language==0)printf("Point %d. has incorrect coordinates: (%s,%s). It was not loaded!!\n",number,a,b);
		if(language==1)printf("Punkt %d. posiada bledne wsporzedne: (%s,%s), wiec nie zostal wczytany!!\n",number,a,b);
		if(language==2)printf("Punkt %d. hat falsche Koordinaten: (%s,%s). Es war nicht geladen!!\n",number,a,b);
		if(language==3)printf("Le point %d. a des coordonn�es incorrectes: (%s,%s). Il n'a pas ete charge!!\n",number,a,b);
		if(language==4)printf("Il punto %d. ha coordinate errate: (%s,%s). Non e stato caricato!!\n",number,a,b);
		if(language==5)printf("El punto %d. tiene coordenadas incorrectas: (%s,%s). No estaba cargada!!\n",number,a,b);
	
		return 1;
	}
	return 0;	
}

//funkcja zg�aszaj�ca b��d, gdy podana liczba nie nale�y do mo�liwego przedzia�u
void error_number_size(char*name,int number,int min, int mak,int language)
{
	if(number<min||number>mak)
	{
		if(language==0)printf("In %s number is not an element of interval <%d,%d>!!\n",name,min,mak);
		if(language==1)printf("W %s podana liczba nie nalezy do przedzialu <%d,%d>!!\n",name,min,mak);
		if(language==2)printf("Im %s Zahl ist kein intervall Element <%d,%d>!!\n",name,min,mak);
		if(language==3)printf("En %s nombre n\'est pas un �l�ment de l\'intervalle <%d,%d>!!\n",name,min,mak);
		if(language==4)printf("In %s numero non e un elemento di intervallo <%d,%d>!!\n",name,min,mak);
		if(language==5)printf("En %s numero no es un elemento de intervalo <%d,%d>!!\n",name,min,mak);
		exit(0);
	}	
}

//funkcja zg�aszaj�ca b��d, gdy kt�ra� ze wsp�rz�dnych punktu jest mniejsza ni� 1 lub wi�ksza ni� wysoko��/szeroko�� planszy
int error_point_size(int number,int maxx,int maxy,int x,int y,int language)
{
	
	if(x<1||y<1||x>maxx||y>maxy)
	{
		if(language==0)printf("Point %d.: (%d,%d) is not an element of interval:  x=<1,%d>, y=<1,%d>. It was not loaded!!\n",number,x,y,maxx,maxy);
		if(language==1)printf("Punkt %d. posiada wsporzedne (%d,%d), ktore nie naleza do przdzialu: x=<1,%d>, y=<1,%d>. Nie zostal wczytany!!\n",number,x,y,maxx,maxy);
		if(language==2)printf("Punkt %d.: (%d,%d) ist kein intervall Element: x=<1,%d>, y=<1,%d>. Es war nicht geladen!!\n",number,x,y,maxx,maxy);
		if(language==3)printf("Le point %d.: (%d,%d) n'est pas un �l�ment de l'intervalle: x=<1,%d>, y=<1,%d>. Il n'a pas ete charge!!\n",number,x,y,maxx,maxy);
		if(language==4)printf("Il punto %d.: (%d,%d) non e un elemento di intervallo: x=<1,%d>, y=<1,%d>. Non e stato caricato!!\n",number,x,y,maxx,maxy);
		if(language==5)printf("El punto %d.: (%d,%d) numero no es un elemento de intervalo: x=<1,%d>, y=<1,%d>. No estaba cargada!!\n",number,x,y,maxx,maxy);
	
		return 1;
	}
		return 0;
}


void error_falgargument(char*flagname,int language)
{
		if(language==0)printf("After %s you did not enter the vlaue!!\n",flagname);
		if(language==1)printf("Po argumencie %s nie podales wartosci!!\n",flagname);
		if(language==2)printf("Nach dem %s Sie haben den Wert nicht eingegeben!!\n",flagname);
		if(language==3)printf("Apres %s vous n'avez pas entre de valeur!!\n",flagname);
		if(language==4)printf("After %s non hai inserito un valore!!\n",flagname);
		if(language==5)printf("Despu�s de la %s No has introducido un valor!!\n",flagname);
		 	
		 	exit(0);
}

