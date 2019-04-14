#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "settings.h"


int main(int argc, char *argv[])
{

        /*ustawienie wartoœci domyœlnych dla zmiennych odpowiedzialnych za ustawienia*/
        char* filename;   // nazwa pliku z danymi
        char name_graphic[]="image";
        char name_txt[]="cells";

        SET setting={20,20,name_graphic,name_txt,1,0,0,0,255,255,255,1000};
        SET* setting_pointer=&setting;

        //sprawdzenie czy u¿ytkownik wybra³ jêzyk.
        check_language(argv,argc);

        //sprawdzenie czy u¿ytkownik poda³ ustawienia i wczytanie ich
        check_gridsize(setting_pointer,argv,argc);
        check_graphicsettings(setting_pointer,argv,argc);
        check_filenames(&filename,setting_pointer,argv,argc);

        printf("width: %d\n",setting.width);
        printf("height: %d\n",setting.height);
        printf("graphic name: %s\n",setting.graphicfile);
        printf("txt name: %s\n",setting.txtfile);
        printf("pixel size name: %d\n",setting.pixel_size);
        printf("live color: red:%d, green:%d, blue:%d\n",setting.lred,setting.lgreen,setting.lblue);
        printf("dead color: red:%d, green:%d, blue:%d\n",setting.dred,setting.dgreen,setting.dblue);
        printf("N: %d\n",setting.N);



        return 0;
}

