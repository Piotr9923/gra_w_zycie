#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "errors.h"
#include "settings.h"

//funkcja zgłaszająca błąd, gdy podana wartość powinna być liczbą, a nią nie jest
void error_number(char*flagname,char*number)
{
	int dl=strlen(number);
	int ile=0;
	
	for(int i=0;i<dl;i++)
	if(isdigit(number[i])!=0) ile++;
	
	
	if(ile!=dl)
	{
		if(language==en)printf("After %s you wrote %s. It is not a number!!\n",flagname,number);
		if(language==pl)printf("Po argumencie %s podales wartosc %s, ktora nie jest liczba!!\n",flagname,number);
		if(language==de)printf("Nach dem %s, du %s geschreiben. Es ist keine Nummer!!\n",flagname,number);
		if(language==fr)printf("Apres %s tu as écrit %s. Ce n'est pas un chiffre!!\n",flagname,number);
		if(language==it)printf("After %s Hai scritto %s. Non e un numero!!\n",flagname,number);
		if(language==es)printf("Después de la %s que escribiste %s. No es un numero!!\n",flagname,number);
		
		exit(0);
	}
}


//funkcja zgłaszająca błąd, gdy nie podano nazwy z plikiem danych
void error_nofilename()
{
	
	if(language==en)printf("You did not enter the data file name !! Do it using --filename!!\n");
	if(language==pl)printf("Nie podales nazwy pliku z danymi!! Zrob to przy uzyciu --filename !!\n");
	if(language==de)printf("Sie haben den Dateinamen nicht eingegeben!! Du machst es mit --filename!!\n");
	if(language==fr)printf("Vous n'avez pas saisi le nom du fichier de donnees!! Faites-le en utilisant --filename!!\n");
	if(language==it)printf("Non e stato immesso il nome del file di dati!! Farlo usando --filename!!\n");
	if(language==es)printf("No ha introducir el nombre del archivo de datos!! Hazlo usando --filename!!\n");

	exit(0);
}


//funkcja zgłaszająca błąd, gdy nie można otworzyć pliku z danymi
void error_nofoundfile(char*name)
{
	if(language==en)printf("I can not open the file: %s!!\n",name);
	if(language==pl)printf("Nie moge otworzyc pliku o nazwie: %s!\n!",name);
	if(language==de)printf("Ich kann die Datei nicht offnen: %s!!\n",name);
	if(language==fr)printf("Je ne peux pas ouvrir le fichier: %s!!\n",name);
	if(language==it)printf("Non riesco ad aprire il file: %s!!\n",name);
	if(language==es)printf("No puedo abrir el archivo: %s!!\n",name);

	exit(0);
}


//funkcja sprawdzająca czy współrzędne punktu są poprawne
int error_point(int number,char* a,char* b)
{
	int dl1=strlen(a);
	int dl2=strlen(b);
	int ile1=0,ile2=0;
	
	for(int i=0;i<dl1;i++) if(isdigit(a[i])!=0) ile1++;
	for(int i=0;i<dl2;i++) if(isdigit(b[i])!=0) ile2++;

	if(ile1!=dl1||ile2!=dl2)
	{
		if(language==en)printf("Point %d. has incorrect coordinates: (%s,%s). It was not loaded!!\n",number,a,b);
		if(language==pl)printf("Punkt %d. posiada bledne wsporzedne: (%s,%s), wiec nie zostal wczytany!!\n",number,a,b);
		if(language==de)printf("Punkt %d. hat falsche Koordinaten: (%s,%s). Es war nicht geladen!!\n",number,a,b);
		if(language==fr)printf("Le point %d. a des coordonnées incorrectes: (%s,%s). Il n'a pas ete charge!!\n",number,a,b);
		if(language==it)printf("Il punto %d. ha coordinate errate: (%s,%s). Non e stato caricato!!\n",number,a,b);
		if(language==es)printf("El punto %d. tiene coordenadas incorrectas: (%s,%s). No estaba cargada!!\n",number,a,b);
	
		return 1;
	}
	return 0;	
}


//funkcja zgłaszająca błąd, gdy podana liczba nie należy do możliwego przedziału
void error_number_size(char*name,int number,int min, int mak)
{
	if(number<min||number>mak)
	{
		if(language==en)printf("In %s number is not an element of interval <%d,%d>!!\n",name,min,mak);
		if(language==pl)printf("W %s podana liczba nie nalezy do przedzialu <%d,%d>!!\n",name,min,mak);
		if(language==de)printf("Im %s Zahl ist kein intervall Element <%d,%d>!!\n",name,min,mak);
		if(language==fr)printf("En %s nombre n\'est pas un élément de l\'intervalle <%d,%d>!!\n",name,min,mak);
		if(language==it)printf("In %s numero non e un elemento di intervallo <%d,%d>!!\n",name,min,mak);
		if(language==es)printf("En %s numero no es un elemento de intervalo <%d,%d>!!\n",name,min,mak);
	
		exit(0);
	}	
}


//funkcja zgłaszająca błąd, gdy któraś ze współrzędnych punktu jest mniejsza niż 1 lub większa niż wysokość/szerokość planszy
int error_point_size(int number,int maxx,int maxy,int x,int y)
{
	if(x<1||y<1||x>maxx||y>maxy)
	{
	if(language==en)printf("Point %d.: (%d,%d) is not an element of interval:  x=<1,%d>, y=<1,%d>. It was not loaded!!\n",number,x,y,maxx,maxy);
	if(language==pl)printf("Punkt %d. posiada wsporzedne (%d,%d), ktore nie naleza do przdzialu: x=<1,%d>, y=<1,%d>. Nie zostal wczytany!!\n",number,x,y,maxx,maxy);
	if(language==de)printf("Punkt %d.: (%d,%d) ist kein intervall Element: x=<1,%d>, y=<1,%d>. Es war nicht geladen!!\n",number,x,y,maxx,maxy);
	if(language==fr)printf("Le point %d.: (%d,%d) n'est pas un élément de l'intervalle: x=<1,%d>, y=<1,%d>. Il n'a pas ete charge!!\n",number,x,y,maxx,maxy);
	if(language==it)printf("Il punto %d.: (%d,%d) non e un elemento di intervallo: x=<1,%d>, y=<1,%d>. Non e stato caricato!!\n",number,x,y,maxx,maxy);
	if(language==es)printf("El punto %d.: (%d,%d) numero no es un elemento de intervalo: x=<1,%d>, y=<1,%d>. No estaba cargada!!\n",number,x,y,maxx,maxy);
	
	return 1;
	}
	return 0;
}

//funkcja zgłaszająca błąd, gdy po fladze sterującej nie podamy argumentu
void error_falgargument(char*flagname)
{
	if(language==en)printf("After %s you did not enter the vlaue!!\n",flagname);
	if(language==pl)printf("Po argumencie %s nie podales wartosci!!\n",flagname);
	if(language==de)printf("Nach dem %s Sie haben den Wert nicht eingegeben!!\n",flagname);
	if(language==fr)printf("Apres %s vous n'avez pas entre de valeur!!\n",flagname);
	if(language==it)printf("After %s non hai inserito un valore!!\n",flagname);
	if(language==es)printf("Después de la %s No has introducido un valor!!\n",flagname);
		 	
	exit(0);
}

