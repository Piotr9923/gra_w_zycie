#ifndef _SET_
#define _SET_

typedef enum L{en,pl,de,fr,it,es} L;
extern L language;

typedef struct SET{
	int width, height;
	char* graphicfile;
	char* txtfile;
	int pixel_size;
	int lred,lgreen,lblue;
	int dred,dgreen,dblue;
	int N;
}SET;

typedef enum GRID{DEAD,ALIVE}GRID;

typedef enum CHANGE{NO,YES} CHANGE;

void check_language(char*argv[],int argc);

void check_gridsize(SET*setting_pointer,char*argv[],int argc);

void check_graphicsettings(SET*setting_pointer,char*argv[],int argc);

void check_filenames(char**filename,SET*setting_pointer,char*argv[],int argc);


#endif
