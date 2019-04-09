#include<stdio.h>
#include "file_writer.h"
#include "writer.h"
#include "settings.h"
#include "change.h"
#include "game.h"

void game(SET setting,int*grid[],int*change[])
{
	
	
	//tablice znak�w b�d�ce nazwami plik�w wynikowych
	char graphic[30];
	char txt[30];
	//zmienna wskazuj�ca numer generacji kom�rek
	int generation_number=0;
	
	//tworzenie nazw plik�w
	sprintf(graphic,"%s%d.ppm",setting.graphicfile,generation_number);
	sprintf(txt,"%s%d.txt",setting.txtfile,generation_number);
	generation_number++;
	
	//wypisanie na konsol� oraz do plik�w pocz�tkowego uk�adu kom�rek
	write(setting.width,setting.height,grid);
	write_graphic(setting,grid,graphic);
	write_txt(setting,grid,txt);


	//zmienna wskazuj�ca czy uk�ad kom�rek si� zmienia
	int how_many_change=0;
	
	//zmienna wskazuj�ca czy na planszy znajduj� sie �ywe kom�rki
	int how_many_live=0;
    
	

	do{
	
        how_many_change=0;
        how_many_live=0;
        
        //towrzenie nazw plik�w
   		sprintf(graphic,"%s%d.ppm",setting.graphicfile,generation_number);
		sprintf(txt,"%s%d.txt",setting.txtfile,generation_number);
    	
    	//oznaczenie kom�rek kt�rych stan sie zmienia
    	check_cellstochange(setting.width,setting.height,grid,change,&how_many_change);
    	
    	//zmiana stan�w kom�rek
    	change_cells(setting.width,setting.height,grid,change,&how_many_live,&how_many_change);

    	
       

		//wypisanie uk3adu kom�rek na konsoli
    	write(setting.width,setting.height,grid);

    	//zapisanie uk3adu kom�rek do pliku graficznego i testowego
		write_graphic(setting,grid,graphic);
		write_txt(setting,grid,txt);
	
	
	
 		printf("\n\n\n\n");
 		//zwi�kszenie numeru generacji kom�rek
 		generation_number++;
    
	} while(how_many_change>0&&how_many_live>0&&generation_number<setting.N);	/*p�tla b�dzie wykonywa� si� dop�ki zostan� spe�nione 3 warunki:
																		**nast�pi zmiana w uk�adu kom�rek na planszy
																		**na planszy b�dzie znajdowa� si� co najmniej jedna �ywa kom�rka
																		**numer generacji b�dzie mniejszy ni� ��dana ilo�� generacji przez u�ytkownika
																		*/
} 
