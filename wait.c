#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void czekaj( double sekundy )
{
    clock_t koniec_czekania;
    koniec_czekania = clock() + sekundy * CLOCKS_PER_SEC;
    while( clock() < koniec_czekania ) { }
}
