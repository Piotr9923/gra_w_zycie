#include"neighbourhood.h"

int check_neighbourhood(int width,int height ,GRID *grid[], int y, int x)
{
	int how_many_live_neighbourhood=0;
 
 
 	/*sprawdzenie czy			**sprawdzenie czy s�siad	**zwi�kszenie liczby 
 	**kom�rka posiada 			**jest �yw� kom�rk�			**�wych s�siad�w kom�rki
 	**s�siada 																	*/	
    if (x-1>=0&&y-1>=0)			 if (grid[y-1][x-1]==ALIVE) how_many_live_neighbourhood++;
    if (x>=0&&y-1>=0)			 if (grid[y-1][x]==ALIVE) 	how_many_live_neighbourhood++;
    if (x+1<width&&y-1>=0) 		 if (grid[y-1][x+1]==ALIVE) how_many_live_neighbourhood++;
   	if (x-1>=0&&y>=0)			 if (grid[y][x-1]==ALIVE) 	how_many_live_neighbourhood++;
    if (x+1<width&&y>=0)		 if (grid[y][x+1]==ALIVE) 	how_many_live_neighbourhood++;
    if (x-1>=0&&y+1<height)		 if (grid[y+1][x-1]==ALIVE) how_many_live_neighbourhood++;
    if (x>=0&&y+1<height)		 if (grid[y+1][x]==ALIVE) 	how_many_live_neighbourhood++;
    if (x+1<width&&y+1<height)	 if (grid[y+1][x+1]==ALIVE) how_many_live_neighbourhood++;
        
    return how_many_live_neighbourhood;
}
