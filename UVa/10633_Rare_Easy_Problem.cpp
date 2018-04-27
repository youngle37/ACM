#include <stdio.h>

typedef long long LL;

int main() {
    LL n;
    while(scanf("%lld", &n) && n) {
        LL count = 0;
        for(LL b = 9; b >= 0; --b) {
            if((n-b)%9 == 0){
                if(count++) printf(" ");
                printf("%lld", (n-b)/9*10 + b);
            }
        }
        printf("\n");
    }
    return 0;
}
