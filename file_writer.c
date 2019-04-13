#include <stdio.h>
#include<string.h>
#include "file_writer.h"
#include "settings.h"

 void write_graphic(SET setting,GRID *grid[],char*name) 
 {
 	
	
    	const int dimx = setting.width; 
	const int dimy = setting.height;
	int i, j;
    	int size=setting.pixel_size;
    	char path[100]="./results/";
    	char* path_pointer=path;
        
    	strcat(path_pointer,name);
        
    	FILE * fp = fopen(path, "wb"); /* b - tryb binarny */
    	fprintf(fp, "P6\n%d %d\n255\n", dimx*size, dimy*size);
    
   		
    	for(j=0; j<dimy; ++j)
	{
    		for(int p1=0;p1<size;p1++)
        	{
        		for(i=0; i<dimx; ++i)
			{         
        			static unsigned char color[3];
                		if(grid[j][i]==YES)
                		{
                			color[0]=setting.lred; /* red-czerwony */
                    			color[1]=setting.lgreen; /* green-zielony */
                    			color[2]=setting.lblue; /* blue-niebieski */
                		}
                		else
                		{
                    			color[0]=setting.dred; /* red-czerwony */
                    			color[1]=setting.dgreen; /* green-zielony */
                    			color[2]=setting.dblue; /* blue-niebieski */
                		}
                		for(int p2=0;p2<size;p2++)fwrite(color,1,3,fp);
           		}
        	}
    }
    fclose(fp);
 }
 
 
 void write_txt(SET setting,GRID *grid[], char* name)
 {
 	char path[100]="./results/";
    	char* path_pointer=path;
        
    	strcat(path_pointer,name);
        
        
 	FILE *fp=fopen(path,"w");
 	
 	for(int x=0;x<setting.width;x++)
 		for(int y=setting.height-1;y>=0;y--)
 		{
 			if(grid[y][x]==YES) fprintf(fp,"%d %d\n",x+1,setting.height-y);
		}
 	fclose(fp);
 }
