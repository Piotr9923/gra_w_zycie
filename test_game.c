//Komórki powinny znikaæ w ka¿edj genaracji bo jedenej na ka¿dym koñcu przek¹tnej//

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "file_reader.h"
#include "settings.h"
#include "game.h"

int main(int argc, char *argv[])
{

        /*ustawienie wartoœci domyœlnych dla zmiennych odpowiedzialnych za ustawienia*/
        char* filename;   // nazwa pliku z danymi
        char name_graphic[]="image";
        char name_txt[]="cells";

        SET setting={20,20,name_graphic,name_txt,1,0,0,0,255,255,255,1000};


        setting.width=10;
        setting.height=10;

        GRID **grid;            //grid - tablica zawieraj¹ca informacjê czy komórka jest ¿ywa czy martwa
        CHANGE **change;        //change - tablica zawieraj¹ca infrmacjê czy dana komórka zmienia swój stan

        //alokacja pamiêci dla tablic
        grid=malloc(sizeof(GRID*)*setting.height);
        change=malloc(sizeof(CHANGE*)*setting.height);

        for(int i=0;i<setting.height;++i)
        {
                grid[i]=malloc(sizeof(GRID)*setting.width);
                change[i]=malloc(sizeof(CHANGE)*setting.width);
        }
        //koniec alokacji pamiêci

        //ustawienie wartoœci tablic grid i change na domyœlne
        for(int i=0;i<setting.height;i++)
        {
            for(int j=0;j<setting.width;j++)
            {
                grid[i][j]=DEAD;
                change[i][j]=NO;
            }
        }


        //tworzenie folderu do którego bêd¹ zapisywane pliki wynikowe
        system("mkdir results");

        grid[0][9]=ALIVE;
        grid[1][8]=ALIVE;
        grid[2][7]=ALIVE;
        grid[3][6]=ALIVE;
        grid[4][5]=ALIVE;
        grid[5][4]=ALIVE;
        grid[6][3]=ALIVE;
        grid[7][2]=ALIVE;
        grid[8][1]=ALIVE;
        grid[9][0]=ALIVE;


        game(setting,grid,change);

        //zwolnienie pamiêci
        for(int i=0;i<setting.height;++i)
        {
                free(grid[i]);
                free(change[i]);
        }
        free(grid);
        free(change);

        return 0;
}

