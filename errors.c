#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"errors.h"
//funkcja zg³aszaj¹ca b³¹d, gdy plik wyjœciowy koñczy siê cyframi"999", co jest maksymaln¹ liczb¹ plików wyjœciowych
void error_size(char a, char b,char c,int language)
{
	if(a=='9'&&b=='9'&&c=='9')
	{
		if(language==0)printf("The program can not write more cells, so ending its action!!");
		if(language==1)printf("Program nie moze zapisac wiecej ukladow komorek wiec konczy swoje dzialanie!!");
		if(language==2)printf("Das Programm kann nicht mehr Zellen schreiben und damit seine Aktion beenden!!");
		if(language==3)printf("Le programme ne peut pas ecrire plus de cellules, mettant ainsi fin a son action!!");
		if(language==4)printf("Il programma non puo scrivere piu celle, quindi termina la sua azione!!");
		if(language==5)printf("El programa no puede escribir mas celdas, por lo que finaliza su accion!!");
		exit(0);
	}
}

//funkcja zg³aszaj¹ca b³¹d, gdy podana wartoœæ powinna byæ liczb¹, a ni¹ nie jest
void error_number(char*flagname,char*number,int language)
{
	int dl=strlen(number);
	int ile=0;
	
	for(int i=0;i<dl;i++)
	if(isdigit(number[i])!=0) ile++;
	
	
	if(ile!=dl)
	{
		if(language==0)printf("After %s you wrote %s. It is not a number!!",flagname,number);
		if(language==1)printf("Po argumencie %s podales wartosc %s, ktora nie jest liczba!!",flagname,number);
		if(language==2)printf("Nach dem %s, du %s geschreiben. Es ist keine Nummer!!",flagname,number);
		if(language==3)printf("Apres %s tu as écrit %s. Ce n'est pas un chiffre!!",flagname,number);
		if(language==4)printf("After %s Hai scritto %s. Non e un numero!!",flagname,number);
		if(language==5)printf("Después de la %s que escribiste %s. No es un numero!!",flagname,number);
		
		exit(0);
	}
}


//funkcja zg³aszaj¹ca b³¹d, gdy nie podano nazwy z plikiem danych
void error_nofilename(int language)
{
	
	if(language==0)printf("You did not enter the data file name !! Do it using --filename!!");
	if(language==1)printf("Nie podales nazwy pliku z danymi!! Zrob to przy uzyciu --filename !!");
	if(language==2)printf("Sie haben den Dateinamen nicht eingegeben!! Du machst es mit --filename!!");
	if(language==3)printf("Vous n'avez pas saisi le nom du fichier de donnees!! Faites-le en utilisant --filename!!");
	if(language==4)printf("Non e stato immesso il nome del file di dati!! Farlo usando --filename!!");
	if(language==5)printf("No ha introducir el nombre del archivo de datos!! Hazlo usando --filename!!");

	
	exit(0);
	
}
//funkcja zg³aszaj¹ca b³¹d, gdy nie mo¿na otworzyæ pliku z danymi
void error_nofoundfile(char*name,int language)
{
	if(language==0)printf("I can not open the file: %s!!",name);
	if(language==1)printf("Nie moge otworzyc pliku o nazwie: %s!!",name);
	if(language==2)printf("Ich kann die Datei nicht offnen: %s!!",name);
	if(language==3)printf("Je ne peux pas ouvrir le fichier: %s!!",name);
	if(language==4)printf("Non riesco ad aprire il file: %s!!",name);
	if(language==5)printf("No puedo abrir el archivo: %s!!",name);
	
	exit(0);
	
}
//funkcja sprawdzaj¹ca czy wspó³rzêdne punktu s¹ poprawne
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
		if(language==3)printf("Le point %d. a des coordonnées incorrectes: (%s,%s). Il n'a pas ete charge!!\n",number,a,b);
		if(language==4)printf("Il punto %d. ha coordinate errate: (%s,%s). Non e stato caricato!!\n",number,a,b);
		if(language==5)printf("El punto %d. tiene coordenadas incorrectas: (%s,%s). No estaba cargada!!\n",number,a,b);
	
		return 1;
	}
	return 0;	
}

//funkcja zg³aszaj¹ca b³¹d, gdy podana liczba nie nale¿y do mo¿liwego przedzia³u
void error_number_size(char*name,int number,int min, int mak,int language)
{
	if(number<min||number>mak)
	{
		if(language==0)printf("In %s number is not an element of interval <%d,%d>!!",name,min,mak);
		if(language==1)printf("W %s podana liczba nie nalezy do przedzialu <%d,%d>!!",name,min,mak);
		if(language==2)printf("Im %s Zahl ist kein intervall Element <%d,%d>!!",name,min,mak);
		if(language==3)printf("En %s nombre n\'est pas un élément de l\'intervalle <%d,%d>!!",name,min,mak);
		if(language==4)printf("In %s numero non e un elemento di intervallo <%d,%d>!!",name,min,mak);
		if(language==5)printf("En %s numero no es un elemento de intervalo <%d,%d>!!",name,min,mak);
		exit(0);
	}	
}

//funkcja zg³aszaj¹ca b³¹d, gdy któraœ ze wspó³rzêdnych punktu jest mniejsza ni¿ 1 lub wiêksza ni¿ wysokoœæ/szerokoœæ planszy
int error_point_size(int number,int maxx,int maxy,int x,int y,int language)
{
	
	if(x<1||y<1||x>maxx||y>maxy)
	{
		if(language==0)printf("Point %d.: (%d,%d) is not an element of interval:  x=<1,%d>, y=<1,%d>. It was not loaded!!\n",number,x,y,maxx,maxy);
		if(language==1)printf("Punkt %d. posiada wsporzedne (%d,%d), ktore nie naleza do przdzialu: x=<1,%d>, y=<1,%d>. Nie zostal wczytany!!\n",number,x,y,maxx,maxy);
		if(language==2)printf("Punkt %d.: (%d,%d) ist kein intervall Element: x=<1,%d>, y=<1,%d>. Es war nicht geladen!! ",number,x,y,maxx,maxy);
		if(language==3)printf("Le point %d.: (%d,%d) n'est pas un élément de l'intervalle: x=<1,%d>, y=<1,%d>. Il n'a pas ete charge!!",number,x,y,maxx,maxy);
		if(language==4)printf("Il punto %d.: (%d,%d) non e un elemento di intervallo: x=<1,%d>, y=<1,%d>. Non e stato caricato!!",number,x,y,maxx,maxy);
		if(language==5)printf("El punto %d.: (%d,%d) numero no es un elemento de intervalo: x=<1,%d>, y=<1,%d>. No estaba cargada!!",number,x,y,maxx,maxy);
	
		return 1;
	}
		return 0;
}


void error_falgargument(char*flagname,int language)
{
		if(language==0)printf("After %s you did not enter the vlaue!!",flagname);
		if(language==1)printf("Po argumencie %s nie podales wartosci!!",flagname);
		if(language==2)printf("Nach dem %s Sie haben den Wert nicht eingegeben!!",flagname);
		if(language==3)printf("Apres %s vous n'avez pas entre de valeur!!",flagname);
		if(language==4)printf("After %s non hai inserito un valore!!",flagname);
		if(language==5)printf("Después de la %s No has introducido un valor!!",flagname);
		 	
		 	exit(0);
}

