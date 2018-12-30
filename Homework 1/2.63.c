//
//  263.c
//  
//
//  Created by Tiffany Chandra on 10/2/18.
//
#include <stdio.h>
unsigned long srl(unsigned long x, int k) {
    /* Perform shift arithmetically */
    unsigned long xsra = (long) x >> k;
    int w = 8*sizeof(long);
    int mask = (1 << (w - k)) + -1;
    return xsra & mask;
}

long sra(long x, int k) {
    /* Perform shift logically */
    long xsrl = (unsigned long) x >> k;
    int w = 8*sizeof(long);
    int mask = (int) -1 << (w - k);
    int test = 1 << (w - 1);
    mask = mask & ! (x & test) - 1; 
    return xsrl | mask;
}

