
int ile_sasiadow(int x,int y ,int *tab[], int x1 ,int y1)
{

        int ile=0;
       if(x1==0&&y1==0)
        {
                if (tab[x1+1][y1+1]==1) ile++;
                if (tab[x1][y1+1]==1) ile++;
                if (tab[x1+1][y1]==1) ile++;
        }
        else if(x1==0&&y1==y-1)
        {
                if (tab[x1+1][y1-1]==1) ile++;
                if (tab[x1][y1-1]==1) ile++;
                if (tab[x1+1][y1]==1) ile++;

        }
        else if(x1==y-1&&y1==0)
        {
                if (tab[x1][y1+1]==1) ile++;
                if (tab[x1-1][y1]==1) ile++;
                if (tab[x1-1][y1+1]==1) ile++;
        }
        else if(x1==y-1&&y1==y-1)
        {
                if (tab[x1-1][y1-1]==1) ile++;
                if (tab[x1-1][y1]==1) ile++;
                if (tab[x1][y1-1]==1) ile++;
        }
        else if(x1==0&&y1!=0&&y1!=y-1)
        {
        if (tab[x1][y1-1]==1) ile++;
        if (tab[x1+1][y1-1]==1) ile++;
        if (tab[x1+1][y1]==1) ile++;
        if (tab[x1][y1+1]==1) ile++;
        if (tab[x1+1][y1+1]==1) ile++;
        }
 else if(x1==y-1&&y1!=0&&y1!=y-1)
        {
        if (tab[x1-1][y1-1]==1) ile++;
        if (tab[x1][y1-1]==1) ile++;
        if (tab[x1-1][y1]==1) ile++;
        if (tab[x1-1][y1+1]==1) ile++;
        if (tab[x1][y1+1]==1) ile++;
        }
                else if(y1==0&&x1!=0&&x1!=y-1)
        {
        if (tab[x1-1][y1]==1) ile++;
        if (tab[x1+1][y1]==1) ile++;
        if (tab[x1-1][y1+1]==1) ile++;
        if (tab[x1][y1+1]==1) ile++;
        if (tab[x1+1][y1+1]==1) ile++;
        }
                        else if(y1==y-1&&x1!=0&&x1!=y-1)
        {
        if (tab[x1-1][y1-1]==1) ile++;
        if (tab[x1][y1-1]==1) ile++;
        if (tab[x1+1][y1-1]==1) ile++;
        if (tab[x1-1][y1]==1) ile++;
        if (tab[x1+1][y1]==1) ile++;
        }
        else
        {
        if (tab[x1-1][y1-1]==1) ile++;
        if (tab[x1][y1-1]==1) ile++;
        if (tab[x1+1][y1-1]==1) ile++;
        if (tab[x1-1][y1]==1) ile++;
        if (tab[x1+1][y1]==1) ile++;
        if (tab[x1-1][y1+1]==1) ile++;
        if (tab[x1][y1+1]==1) ile++;
        if (tab[x1+1][y1+1]==1) ile++;
        }

  
        return ile;
}
