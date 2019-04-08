#include<stdio.h>
#include "file_writer.h"
#include "writer.h"
#include "settings.h"
#include "change.h"
#include "game.h"

void game(int x,int y,int pixel_size,int lred,int lgreen,int lblue,int dred,int dgreen,int dblue,int N,int*grid[],int*change[],char*txtfile,char*graphicfile)
{
	//tablice znaków bêd¹ce nazwami plików wynikowych
	char graphic[30];
	char txt[30];
	//zmienna wskazuj¹ca numer generacji komórek
	int generation_number=0;
	
	//towrzenie nazw plików
	sprintf(graphic,"%s%d.ppm",graphicfile,generation_number);
	sprintf(txt,"%s%d.txt",txtfile,generation_number);
	generation_number++;
	
	//wypisanie na konsolê oraz do plików pocz¹tkowego uk³adu komórek
	write(x,y,grid);
	write_graphic(x,y,grid,pixel_size,graphic,lred,lgreen,lblue,dred,dgreen,dblue);
	write_txt(x,y,grid,txt);


	//zmienna wskazuj¹ca czy uk³ad komórek siê zmienia
	int how_many_change=0;
	
	//zmienna wskazuj¹ca czy na planszy znajduj¹ sie ¿ywe komórki
    int how_many_live=0;
    
	

	do{
	
        how_many_change=0;
        how_many_live=0;
        
        //towrzenie nazw plików
   		sprintf(graphic,"%s%d.ppm",graphicfile,generation_number);
		sprintf(txt,"%s%d.txt",txtfile,generation_number);
    	
    	//oznaczenie komórek których stan sie zmienia
    	check_cellstochange(x,y,grid,change,&how_many_change);
    	
    	//zmiana stanów komórek
    	change_cells(x,y,grid,change,&how_many_live,&how_many_change);

    	
       

		//wypisanie uk3adu komórek na konsoli
    	write(x,y,grid);

    	//zapisanie uk3adu komórek do pliku graficznego i testowego
		write_graphic(x,y,grid,pixel_size,graphic,lred,lgreen,lblue,dred,dgreen,dblue);
		write_txt(x,y,grid,txt);
	
	
	
 		printf("\n\n\n\n");
 		//zwiêkszenie numeru generacji komórek
 		generation_number++;
    
	} while(how_many_change>0&&how_many_live>0&&generation_number<N);	/*pêtla bêdzie wykonywaæ siê dopóki zostan¹ spe³nione 3 warunki:
																		**nast¹pi zmiana w uk³adu komórek na planszy
																		**na planszy bêdzie znajdowaæ siê co najmniej jedna ¿ywa komórka
																		**numer generacji bêdzie mniejszy ni¿ ¿¹dana iloœæ generacji przez u¿ytkownika
																		*/
} 
