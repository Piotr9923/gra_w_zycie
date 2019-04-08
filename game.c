#include<stdio.h>
#include "file_writer.h"
#include "writer.h"
#include "settings.h"
#include "change.h"
#include "game.h"

void game(int x,int y,int pixel_size,int lred,int lgreen,int lblue,int dred,int dgreen,int dblue,int N,int*grid[],int*change[],char*txtfile,char*graphicfile)
{
	//tablice znak�w b�d�ce nazwami plik�w wynikowych
	char graphic[30];
	char txt[30];
	//zmienna wskazuj�ca numer generacji kom�rek
	int generation_number=0;
	
	//towrzenie nazw plik�w
	sprintf(graphic,"%s%d.ppm",graphicfile,generation_number);
	sprintf(txt,"%s%d.txt",txtfile,generation_number);
	generation_number++;
	
	//wypisanie na konsol� oraz do plik�w pocz�tkowego uk�adu kom�rek
	write(x,y,grid);
	write_graphic(x,y,grid,pixel_size,graphic,lred,lgreen,lblue,dred,dgreen,dblue);
	write_txt(x,y,grid,txt);


	//zmienna wskazuj�ca czy uk�ad kom�rek si� zmienia
	int how_many_change=0;
	
	//zmienna wskazuj�ca czy na planszy znajduj� sie �ywe kom�rki
    int how_many_live=0;
    
	

	do{
	
        how_many_change=0;
        how_many_live=0;
        
        //towrzenie nazw plik�w
   		sprintf(graphic,"%s%d.ppm",graphicfile,generation_number);
		sprintf(txt,"%s%d.txt",txtfile,generation_number);
    	
    	//oznaczenie kom�rek kt�rych stan sie zmienia
    	check_cellstochange(x,y,grid,change,&how_many_change);
    	
    	//zmiana stan�w kom�rek
    	change_cells(x,y,grid,change,&how_many_live,&how_many_change);

    	
       

		//wypisanie uk3adu kom�rek na konsoli
    	write(x,y,grid);

    	//zapisanie uk3adu kom�rek do pliku graficznego i testowego
		write_graphic(x,y,grid,pixel_size,graphic,lred,lgreen,lblue,dred,dgreen,dblue);
		write_txt(x,y,grid,txt);
	
	
	
 		printf("\n\n\n\n");
 		//zwi�kszenie numeru generacji kom�rek
 		generation_number++;
    
	} while(how_many_change>0&&how_many_live>0&&generation_number<N);	/*p�tla b�dzie wykonywa� si� dop�ki zostan� spe�nione 3 warunki:
																		**nast�pi zmiana w uk�adu kom�rek na planszy
																		**na planszy b�dzie znajdowa� si� co najmniej jedna �ywa kom�rka
																		**numer generacji b�dzie mniejszy ni� ��dana ilo�� generacji przez u�ytkownika
																		*/
} 
