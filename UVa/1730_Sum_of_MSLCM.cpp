#include <cstdio>

typedef long long LL;

int main(){
    LL n;
    while(scanf("%lld", &n) && n){
        LL sum = 0;
        LL l = 1;
        LL val, r;

        while(l <= n){
            val = n / l;
            r = n / val;
            sum += val * ((l+r)*(r-l+1)/2);
            l = r+1;
        }

        printf("%lld\n", sum-1);
        
    }
    return 0;
}
