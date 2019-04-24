#include <cstdio>

// a 為上個式子的餘數
// b 為上個式子的除數
int gcd(int a, int b){
    return a == 0 ? b : gcd(b%a, a);
}

int main(){
    printf("%d\n", gcd(200, 151));

    return 0;
}
