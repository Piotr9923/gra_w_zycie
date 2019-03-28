#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//funkcja zg³aszaj¹ca b³¹d, gdy plik wyjœciowy koñczy siê cyframi"999", co jest maksymaln¹ liczb¹ plików wyjœciowych
void error_size(char a, char b,char c)
{
	if(a=='9'&&b=='9'&&c=='9')
	{
		printf("Program nie moze zapisac wiecej ukladow komorek wiec konczy swoje dzialanie!!");
		exit(0);
	}
}

//funkcja zg³aszaj¹ca b³¹d, gdy podana wartoœæ powinna byæ liczb¹, a ni¹ nie jest
void error_number(char*flagname,char*number)
{
	int dl=strlen(number);
	int ile=0;
	
	for(int i=0;i<dl;i++)
	if(isdigit(number[i])!=0) ile++;
	
	
	if(ile!=dl)
	{
		printf("Po argumencie %s podales wartosc %s, ktora nie jest liczba!!!!",flagname,number);
		exit(0);
	}
}


//funkcja zg³aszaj¹ca b³¹d, gdy nie podano nazwy z plikiem danych
void error_nofilename()
{
	
	printf("Nie podales nazwy pliku z danymi!!!!  Zrob to przy uzyciu --filename ");
	exit(0);
	
}
//funkcja zg³aszaj¹ca b³¹d, gdy nie mo¿na otworzyæ pliku z danymi
void error_nofoundfile(char*name)
{
	
	printf("Nie moge otworzyc pliku o nazwie: %s",name);
	exit(0);
	
}
//funkcja sprawdzaj¹ca czy wspó³rzêdne punktu s¹ poprawne
int error_point(int number,char* a,char* b)
{
	int dl1=strlen(a);
	int dl2=strlen(b);
	int ile1=0,ile2=0;
	
	for(int i=0;i<dl1;i++) if(isdigit(a[i])!=0) ile1++;
	for(int i=0;i<dl2;i++) if(isdigit(b[i])!=0) ile2++;

	if(ile1!=dl1||ile2!=dl2)
	{
		printf("Punkt numer %d posiada bledne wsporzedne: (%s,%s), wiec zostal pominiety!!!\n",number,a,b);
		return 1;
	}
	return 0;	
}

//funkcja zg³aszaj¹ca b³¹d, gdy podana liczba nie nale¿y do mo¿liwego przedzia³u
void error_number_size(char*name,int number,int min, int mak)
{
	if(number<min||number>mak)
	{
		printf("W %s podana liczba nie nalezy do przedzia³u <%d,%d>!!",name,min,mak);
	}	
}

//funkcja zg³aszaj¹ca b³¹d, gdy któraœ ze wspó³rzêdnych punktu jest mniejsza ni¿ 1 lub wiêksza ni¿ wysokoœæ/szerokoœæ planszy
int error_point_size(int number,int maxx,int maxy,int x,int y)
{
	
	if(x<1||y<1||x>maxx||y>maxy)
	{
			printf("Punkt numer %d posiada wsporzedne (%d,%d), ktore nie naleza do przdzialu x=<1,%d>, y=<1,%d>,wiec zostal pominiety!!!\n",number,x,y,maxx,maxy);
		return 1;
	}
		return 0;
}


