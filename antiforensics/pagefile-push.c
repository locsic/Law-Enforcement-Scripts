/*Page File Push - Allocate gobs of memory to push memory pages to the paging file
 *Copyright (C) 2012 Loc Nguyen
 */

/*
 *@Todo:    Pagefile purge
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **arv)
{
        int *p;
        while(1)
            p = (int*)calloc(0x1000,1);
        return(1);
}
