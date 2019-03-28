#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void wait( double seconds )
{
    clock_t end_wait;
    end_wait = clock() + seconds * CLOCKS_PER_SEC;
    while( clock() < end_wait ) { }
}
