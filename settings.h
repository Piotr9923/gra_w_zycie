#ifndef _SET_
#define _SET_

enum L{en,pl,de,fr,it,es};
extern enum L language;

void check_language(char*argv[],int argc);

void check_gridsize(int*x,int*y,int*N,char*argv[],int argc);

void check_graphicsettings(int*pixel_size,int*lred,int*lblue,int*lgreen,int*dred,int*dblue,int*dgreen,char*argv[],int argc);

void check_filenames(char**filename,char**graphicfile,char**txtfile,char*argv[],int argc);


#endif
