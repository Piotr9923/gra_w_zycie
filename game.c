#include<stdio.h>
#include "file_writer.h"
#include "writer.h"
#include "settings.h"
#include "change.h"
#include "game.h"

void game(SET setting,GRID *grid[],CHANGE*change[])
{
	
	
	//tablice znaków będące nazwami plików wynikowych
	char graphic[30];
	char txt[30];
	//zmienna wskazująca numer generacji komórek
	int generation_number=0;
	
	//tworzenie nazw plików
	sprintf(graphic,"%s%d.ppm",setting.graphicfile,generation_number);
	sprintf(txt,"%s%d.txt",setting.txtfile,generation_number);
	generation_number++;
	
	//wypisanie na konsolę oraz do plików początkowego układu komórek
	write(setting.width,setting.height,grid);
	write_graphic(setting,grid,graphic);
	write_txt(setting,grid,txt);


	//zmienna wskazująca czy układ komórek się zmienia
	int how_many_change=0;
	
	//zmienna wskazująca czy na planszy znajdują sie żywe komórki
	int how_many_live=0;
    
	

	do{
	
  	      	how_many_change=0;
  	      	how_many_live=0;
        
        	//towrzenie nazw plików
		sprintf(graphic,"%s%d.ppm",setting.graphicfile,generation_number);
		sprintf(txt,"%s%d.txt",setting.txtfile,generation_number);
    	
    		//oznaczenie komórek których stan sie zmienia
    		check_cellstochange(setting.width,setting.height,grid,change,&how_many_change);
    	
    		//zmiana stanów komórek
    		change_cells(setting.width,setting.height,grid,change,&how_many_live,&how_many_change);

    	
       

		//wypisanie uk3adu komórek na konsoli
    		write(setting.width,setting.height,grid);

    		//zapisanie uk3adu komórek do pliku graficznego i testowego
		write_graphic(setting,grid,graphic);
		write_txt(setting,grid,txt);


 		printf("\n\n\n\n");
 		//zwiększenie numeru generacji komórek
 		generation_number++;
    
	} while(how_many_change>0&&how_many_live>0&&generation_number<setting.N);	/*pętla będzie wykonywać się dopóki zostaną spełnione 3 warunki:
											**nastąpi zmiana w układu komórek na planszy
											**na planszy będzie znajdować się co najmniej jedna żywa komórka
											**numer generacji będzie mniejszy niż żądana ilość generacji przez użytkownika
											*/
} 
