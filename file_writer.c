#include <stdio.h>
#include<string.h>

 void write_graphic(int x,int y,int *grid[],int size,char*name, int lr,int lg,int lb,int dr,int dg,int db) {
 	
	
	    const int dimx = x; 
        const int dimy = y;
        int i, j;
        FILE * fp = fopen(name, "wb"); /* b - tryb binarny */
        fprintf(fp, "P6\n%d %d\n255\n", dimx*size, dimy*size);
    
   		
        for(j=0; j<dimy; ++j){
        	for(int p1=0;p1<size;p1++)
        	{
          for(i=0; i<dimx; ++i){         
                        static unsigned char color[3];
                        if(grid[j][i]==1)
                        {
                        color[0]=lr; /* red-czerwony */
                        color[1]=lg; /* green-zielony */
                        color[2]=lb; /* blue-niebieski */
                    	}
                    	 else
                        {
                        color[0]=dr; /* red-czerwony */
                        color[1]=dg; /* green-zielony */
                        color[2]=db; /* blue-niebieski */
                    	}
                    	for(int p2=0;p2<size;p2++)fwrite(color,1,3,fp);
                }
            }
        }
        fclose(fp);
 }
 
 
 void write_txt(int x,int y,int *grid[], char* name)
 {
 	
 	FILE *fp=fopen(name,"w");
 	
 	for(int j=0;j<x;j++)
 	for(int i=y-1;i>=0;i--)
 	{
 		if(grid[i][j]==1) fprintf(fp,"%d %d\n",j+1,y-i);
 		
	}
 	 fclose(fp);
 }
 
 
 
 
 
 
 
