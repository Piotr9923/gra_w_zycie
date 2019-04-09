#include<stdio.h>
#include "file_writer.h"
#include "writer.h"
#include "settings.h"
#include "change.h"
#include "game.h"

void game(SET setting,int*grid[],int*change[])
{
	
	
	//tablice znaków bêd¹ce nazwami plików wynikowych
	char graphic[30];
	char txt[30];
	//zmienna wskazuj¹ca numer generacji komórek
	int generation_number=0;
	
	//tworzenie nazw plików
	sprintf(graphic,"%s%d.ppm",setting.graphicfile,generation_number);
	sprintf(txt,"%s%d.txt",setting.txtfile,generation_number);
	generation_number++;
	
	//wypisanie na konsolê oraz do plików pocz¹tkowego uk³adu komórek
	write(setting.width,setting.height,grid);
	write_graphic(setting,grid,graphic);
	write_txt(setting,grid,txt);


	//zmienna wskazuj¹ca czy uk³ad komórek siê zmienia
	int how_many_change=0;
	
	//zmienna wskazuj¹ca czy na planszy znajduj¹ sie ¿ywe komórki
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
 		//zwiêkszenie numeru generacji komórek
 		generation_number++;
    
	} while(how_many_change>0&&how_many_live>0&&generation_number<setting.N);	/*pêtla bêdzie wykonywaæ siê dopóki zostan¹ spe³nione 3 warunki:
																		**nast¹pi zmiana w uk³adu komórek na planszy
																		**na planszy bêdzie znajdowaæ siê co najmniej jedna ¿ywa komórka
																		**numer generacji bêdzie mniejszy ni¿ ¿¹dana iloœæ generacji przez u¿ytkownika
																		*/
} 
