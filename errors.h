#ifndef _ERRORS_
#define _ERRORS_

void error_number(char*flagname,char*number);

void error_nofilename();

void error_nofoundfile(char*name);

int error_point(int number,char* a,char* b);

void error_number_size(char*name,int number,int min, int mak);

int error_point_size(int number,int maxx,int maxy,int x,int y);

void error_falgargument(char*flagname);

#endif
