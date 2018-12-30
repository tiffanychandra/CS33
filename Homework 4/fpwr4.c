//
//  fpwr4.c
//  
//
//  Created by Tiffany Chandra on 11/3/18.
//
#include <stdio.h>
//problem 2.90
//#compute 4**x rather than 2**x and call the resulting function fpwr4 instead of fpwr2.
//submit the source code for fpwr4 preceded by the definition of a function 'static float u2f(unsigned u) {...}' that returns a value described in 2.90 (fill in the '...')

static float u2f(unsigned u)
{
    return *(float*) &u;
}

float fpwr4(int x)
{
    /*Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;
    
    if (x < -74) {
        /* Too small, return 0.0 */
        exp = 0;
        frac = 0;
    } else if (x < -63) {
        /* Denormalized result */
        exp = 0;
        frac = 1 << (2*x + 149);
    } else if (x < 64) {
        /* Normalized result */
        exp = (2*x) + 127;
        frac = 0;
    } else {
        /* Too big, return +infinity */
        exp = 255;
        frac = 0;
    }
    
    /* Pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /*return as float*/
    return u2f(u);
}

