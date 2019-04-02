#ifndef _ERRORS_
#define _ERRORS_


void error_size(char a, char b,char c,int language);

void error_number(char*flagname,char*number,int language);

void error_nofilename(int language);

void error_nofoundfile(char*name,int language);

int error_point(int number,char* a,char* b,int language);

void error_number_size(char*name,int number,int min, int mak,int language);

int error_point_size(int number,int maxx,int maxy,int x,int y,int language);

void error_falgargument(char*flagname,int language);

#endif
