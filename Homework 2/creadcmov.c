//
//  creadcmov.c
//  
//
//  Created by Tiffany Chandra on 10/15/18.
//

#include <stdio.h>

/*
long cread(long *xp) {
    return (xp ? xp[-1] : -1);
}
*/

long cread_alt(long *xp) {
     return (!xp ? -1 : xp[-1]); // to prevent dereferencing a null pointer
}
