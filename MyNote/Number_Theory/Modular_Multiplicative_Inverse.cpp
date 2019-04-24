/*
 * Finding the inverse 'x' such that
 *      a * x = 1 (mod m)
 * The inverse exists if and only if gcd(a, m) = 1
 *
 * The method below uses the idea of Extended Euclidean Algorithm which is
 * given 'a' and 'b', find integer 'x' and 'y' such that
 *      a * x + b * y = gcd(a, b)
 *
 * Proof & Reference: https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
 */
#include <cstdio>
#include <unistd.h>

int gcdEx(int a, int b, int &x, int &y) {
    // Base
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;     // To store results of recursive call
    int gcd = gcdEx(b % a, a, x1, y1);

    // Update x and y using results of recursive call
    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

void modInverse_recur(int a, int m) {
    int x, y;
    int g = gcdEx(a, m, x, y);
    if(g != 1)
        printf("Inverse doesn't exist\n");
    else {
        printf("Inverse is %d\n", (x % m + m) % m);
    }
}

int modInverse_iter(int a, int m){
    int m0 = m;
    int y = 0, x = 1;

    if(m == 1) return 0;

    while(a > 1){
        // q is quotient, m is divisor
        int q = a / m;
        // store divisor for next loop
        int temp = m;  

        // m        = a % m
        // ^remainder     ^divisor
        m = a % m;
        // m is remainder now, process as Euclidean's algo
        a = temp;
        // store y for temp
        temp = y;

        // Update y and x
        y = x - q * y;
        x = temp;
    }

    if(x < 0) x += m0;

    return x;
}

// Compute x^y (mod m)
int powe(int x, int y, int mod){
    if(y == 0) return 1;
    if(y&1) return (x*powe(x, y-1, mod)) % mod;

    int i = powe(x, y/2, mod);
    return (i*i) % mod;
}

// Works only when m is prime
//      a^(m-1) = 1 (mod m)
// =>   a * a^(m-2) = 1 (mod m)
// So a^(m-2) is inverse of a
int Fermats_Little(int a, int m){
    return powe(a, m-2, m);
}

int main(){
    modInverse_recur(14, 15);
    printf("Inverse is %d\n", modInverse_iter(9, 22));
    printf("Inverse is %d\n", Fermats_Little(7, 13));   // Works only when m is prime

    return 0;
}
