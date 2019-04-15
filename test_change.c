#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "file_reader.h"
#include "settings.h"
#include "change.h"

int main(int argc, char *argv[])
{

        SET setting={20,20,"test","test",1,0,0,0,255,255,255,1000};

        SET* setting_pointer=&setting;

        setting.height=4;
        setting.width=4;

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

        grid[0][0]=ALIVE;
        grid[0][3]=ALIVE;
        grid[1][2]=ALIVE;
        grid[2][1]=ALIVE;
        grid[3][0]=ALIVE;
        grid[3][3]=ALIVE;

        int how_many_change;
        int how_many_live;

        int test=1;
                //oznaczenie komórek których stan sie zmienia
                check_cellstochange(setting.width,setting.height,grid,change,&how_many_change);

                if(
                                change[0][0]==YES &&
                                change[0][3]==YES &&
                                change[1][1]==YES &&
                                change[3][0]==YES &&
                                change[3][3]==YES &&
                                change[2][2]==YES &&
                                change[0][1]==NO




                ) test=test;
                else test=0;




                //zmiana stanów komórek
                change_cells(setting.width,setting.height,grid,change,&how_many_live,&how_many_change);

                if(
                                grid[0][0]==DEAD &&
                                grid[0][3]==DEAD &&
                                grid[3][0]==DEAD &&
                                grid[3][3]==DEAD &&
                                grid[1][2]==ALIVE &&
                                grid[2][1]==ALIVE
                  )
                        test=test;
                else test=0;

                if(test==1) printf("Test result: OK\n");
                else printf("Test result: ERROR\n");
        
        
for(int i=0;i<setting.height;++i)
                {
                free(grid[i]);
                free(change[i]);
                }
free(grid);
change(grid);
        
        
        
        return 0;
}

