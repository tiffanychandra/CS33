//
//  273.c
//  
//
//  Created by Tiffany Chandra on 10/2/18.
//

#include <stdio.h>
/* Addition that saturates to TMin or TMax */

int saturating_add(int x, int y){
    int sum = x + y;
    int sign = INT_MIN;
    
    int posi_overflow = ~(x & sign) & ~(y & sign) & (sum & sign); // if x > 0 and y > 0 and sun < 0, there is positive overflow
    int neg_overflow = (x & sign) & (y & sign) & ~(sum & sign); // if x < 0 and y < 0 and sum >= 0, there is negative overflow
    (posi_overflow && (sum = INT_MAX) || neg_overflow && (sum = INT_MIN));
    return sum;
}






