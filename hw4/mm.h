#ifndef __MY_MM_H_INCLUDED__
#define __MY_MM_H_INCLUDED__
#include <stdlib.h>
#include <string.h>
#define NALLOC 1024

typedef long Align;

union header
{
    struct
    {
        union header *ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Header;

static Header base;
static Header *freep=NULL;

void myfree(void *ap);
static Header *morecore(unsigned nu);
void* mymalloc(unsigned nbytes);
void* mycalloc(unsigned num, unsigned size);
void* myrealloc(void *ptr, unsigned size);
#endif
