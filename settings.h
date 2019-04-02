#ifndef _SET_
#define _SET_


void check_language(char*argv[],int*language,int argc);

void check_gridsize(int*x,int*y,char*argv[],int argc,int language);

void check_graphicsettings(int*pixel_size,int*lred,int*lblue,int*lgreen,int*dred,int*dblue,int*dgreen,char*argv[],int argc,int language);

void check_filenames(char**filename,char**graphicfile,char**txtfile,int*is_filename,int*is_graphicname,int*is_txtname,char*argv[],int argc,int language);


#endif
