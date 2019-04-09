#ifndef _SET_
#define _SET_

enum L{en,pl,de,fr,it,es};
extern enum L language;

typedef struct SET{
	int width, height;
	char* graphicfile;
	char* txtfile;
	int pixel_size;
	int lred,lgreen,lblue;
	int dred,dgreen,dblue;
	int N;
}SET;


void check_language(char*argv[],int argc);

void check_gridsize(SET*setting_pointer,char*argv[],int argc);

void check_graphicsettings(SET*setting_pointer,char*argv[],int argc);

void check_filenames(char**filename,SET*setting_pointer,char*argv[],int argc);


#endif
