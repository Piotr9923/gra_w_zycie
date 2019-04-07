#include<stdio.h>
#include"file_writer.h"
#include"write.h"
#include"settings.h"
#include"change.h"
#include"game.h"

void game(int x,int y,int pixel_size,int lred,int lgreen,int lblue,int dred,int dgreen,int dblue,int N,int*grid[],int*change[],char*txtfile,char*graphicfile)
{
	
	char graphic[30];
	char txt[30];
	int generation_number=0;
	
	sprintf(graphic,"%s%d.ppm",graphicfile,generation_number);
	sprintf(txt,"%s%d.txt",txtfile,generation_number);
	generation_number++;
	
	write(x,y,grid);
	write_graphic(x,y,grid,pixel_size,graphic,lred,lgreen,lblue,dred,dgreen,dblue);
	write_txt(x,y,grid,txt);



		int how_many_change=0;
    	int how_many_live=0;
    
	

	do{
		//zwiêkszenie numeru nazwy w pliku graficznym i tekstowym
		

        how_many_change=0;
        how_many_live=0;
        
    sprintf(graphic,"%s%d.ppm",graphicfile,generation_number);
	sprintf(txt,"%s%d.txt",txtfile,generation_number);
    	
    	//oznaczenie komórek których stan siê zmienia
    	check_cellstochange(x,y,grid,change,&how_many_change);
    	
    	//zmiana stanów komórek
    	change_cells(x,y,grid,change,&how_many_live);

    	
       

		//wypisanie uk³adu komórek na konsoli
    	write(x,y,grid);

    	//zapisanie uk³adu komórek do pliku graficznego i testowego
		write_graphic(x,y,grid,pixel_size,graphic,lred,lgreen,lblue,dred,dgreen,dblue);
		write_txt(x,y,grid,txt);
	
	
	
		sleep(0.25);
 		printf("\n\n\n\n");
 		generation_number++;
    
	} while(how_many_change>0&&how_many_live>0&&generation_number<N);

	
	
	
	
}	
