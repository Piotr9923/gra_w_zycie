#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"settings.h"
#include"errors.h"

void check_language(char*argv[],int*language,int argc)
{
	if(argc>1&&strcmp(argv[1],"--language")==0) 
	{
		if(argc==2)error_falgargument("--language",0);
		
		if(strcmp(argv[2],"pl")==0) *language=1;
		else if(strcmp(argv[2],"de")==0) *language=2;
		else if(strcmp(argv[2],"fr")==0) *language=3;
		else if(strcmp(argv[2],"it")==0) *language=4;
		else if(strcmp(argv[2],"es")==0) *language=5;
		else printf("I do not understand: %s. I select default language - English\n",argv[2]);
	}	
	
}

void check_gridsize(int*x,int*y,char*argv[],int argc,int language)
{
		for(int i=1;i<argc;i++)
	{
		if(strcmp(argv[i],"--x")==0) {if(i+1>=argc)error_falgargument("--x",language);error_number("--x",argv[i+1],language);error_number_size("--x",atoi(argv[i+1]),1,100,language);*x=atoi(argv[i+1]);}
		if(strcmp(argv[i],"--y")==0) {if(i+1>=argc)error_falgargument("--y",language);error_number("--y",argv[i+1],language);error_number_size("--y",atoi(argv[i+1]),1,100,language);*y=atoi(argv[i+1]);}
	}
	
}

void check_graphicsettings(int*pixel_size,int*lred,int*lblue,int*lgreen,int*dred,int*dblue,int*dgreen,char*argv[],int argc,int language)
{
		for(int i=1;i<argc;i++)
	{
			if(strcmp(argv[i],"--pixelsize")==0) {if(i+1>=argc)error_falgargument("--pixelsize",language);error_number("--pixelsize",argv[i+1],language);*pixel_size=atoi(argv[i+1]);}
			if(strcmp(argv[i],"--livecolor")==0)
			{
				if(i+3>=argc)error_falgargument("--livecolor",language);
				error_number("--livecolor",argv[i+1],language);error_number("--livecolor",argv[i+2],language);error_number("--livecolor",argv[i+3],language);
				error_number_size("--livecolor",atoi(argv[i+1]),0,255,language);error_number_size("--livecolor",atoi(argv[i+2]),0,255,language);error_number_size("--livecolor",atoi(argv[i+3]),0,255,language);
				*lred=atoi(argv[i+1]);*lblue=atoi(argv[i+2]);*lgreen=atoi(argv[i+3]);
			}
	
			if(strcmp(argv[i],"--deadcolor")==0)
			{
				if(i+3>=argc)error_falgargument("--deadcolor",language);
				error_number("--deadcolor",argv[i+1],language);error_number("--deadcolor",argv[i+2],language);error_number("--deadcolor",argv[i+3],language);
				error_number_size("--deadcolor",atoi(argv[i+1]),0,255,language);error_number_size("--deadcolor",atoi(argv[i+2]),0,255,language);error_number_size("--deadcolor",atoi(argv[i+3]),0,255,language);
				*dred=atoi(argv[i+1]);*dblue=atoi(argv[i+2]);*dgreen=atoi(argv[i+3]);
			}	
	}
}


void check_filenames(char**filename,char**graphicfile,char**txtfile,int*is_filename,int*is_graphicname,int*is_txtname,char*argv[],int argc,int language)
{
	for(int i=1;i<argc;i++)
	{
		if(strcmp(argv[i],"--filename")==0) {if(i+1>=argc)error_falgargument("--filename",language);*filename=argv[i+1];*is_filename=1;}
		if(strcmp(argv[i],"--graphicfile")==0) {if(i+1>=argc)error_falgargument("--graphicfile",language);*graphicfile=argv[i+1];*is_graphicname=1;}
		if(strcmp(argv[i],"--txtfile")==0){if(i+1>=argc)error_falgargument("--txtfile",language);*txtfile=argv[i+1];*is_txtname=1;}	
	}

	
}
