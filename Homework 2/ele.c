#define R = 7
#define S = 5
#define T = 8

long A[R][S][T];

long ele (long i, long j, long k)
{
    return A[R - i][1 - j][k - 1];
}
// 1.
// To extend equation 3.1 to handle 3-dimensional arrays, we first see that for an array declared as T D[R][C];
// an array element D[i][j] is at memory address
// &D[i][j] = x_D + L(C*i + j).
// Then for a 3-dimensional array, we see that an array declared as A[R][S][T] is at memory address
// &D[i][j][k] = x_D + L(S*T*i + T*j + k) = x_D + L(S*(T*i + j) + k).

// 2. how to derive constants from the extended equation and from ele.s. (Or, if the constants cannot be derived exactly, explain why not.)
// We can derive the constants from the extended equation and from ele.s by reverse engineering the assembly code and matching the returned memory address to the derived equation. The following are steps to find the retrieved memory address from ele.s
// 2 set result = 7
// 3 i in %rdi; %rax = 7-i
// 4 %rax = 5(7 - i)
// 5 %rax = 5(7 - i) - j
// 6 %rax = (k + 8 * (5(7 - i) - j)) + 7
// 7 retrieve M[x_A +  8(8(5(7 - i) - j)) + k + 7])

// Then equating the two equations that we have from the extended equation and ele.s, we find that
// 8(5(7 - i) - j) + k + 7 = S*T*(R-i) + T*(1-j) + k
// R = 7
// 8*5*7 - 8*5*i - 8j + k + 7 = S*T*R - S*T*i + T - Tj + k - 1
// T = 8
// S = 5
// (R,S,T) = (7, 5, 8).


