//
//  273redo.c
//  
//
//  Created by Tiffany Chandra on 10/4/18.
//

#include <stdio.h>


//Redo problem 2.73, this time using a call to the __builtin_add_overflow_p function available in GCC 7 and later; the third argument of the call should be a cast that consists of a parenthesized type followed by the constant 0. In other respects your function should continue to follow the bit-level integer coding rules.

int saturating_add(int x, int y){
    int sum = x + y;
    int checkoverflow = __builtin_add_overflow_p(x, y, (int)0);
    checkoverflow = ~(checkoverflow - 1);
    
    int sign = INT_MIN;
    int posi_overflow = ~(x & sign) & ~(y & sign) & (sum & sign); // if x > 0 and y > 0 and sun < 0, there is positive overflow
    int neg_overflow = (x & sign) & (y & sign) & ~(sum & sign); // if x < 0 and y < 0 and sum >= 0, there is negative overflow
    int no_overflow = ~checkoverflow;
    
    (posi_overflow && (sum = INT_MAX) || neg_overflow && (sum = INT_MIN) || no_overflow && (sum = sum));
    return sum;
}










