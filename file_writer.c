#include <stdio.h>
#include<string.h>

 void grafika(int x,int y,int *tab[],int size,char*name, int lr,int lg,int lb,int dr,int dg,int db) {
 	
	

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
                        if(tab[j][i]==1)
                        {
                        color[0]=lr; /* red */
                        color[1]=lg; /* green */
                        color[2]=lb; /* blue */
                    	}
                    	 else
                        {
                        color[0]=dr; /* red */
                        color[1]=dg; /* green */
                        color[2]=db; /* blue */
                    	}
                    	for(int p2=0;p2<size;p2++)fwrite(color,1,3,fp);
                }
            }
        }
        fclose(fp);
 }
 
 
 
 
 
 
 
