#include <cstdio>

int main(){
    int n, k;
    int f[13] = {1};
    for(int i=1;i<13;i++){
        f[i] = f[i-1] * i;
    }

    while(scanf("%d%d", &n, &k) == 2){
        int ans = f[n];
        int tmp;
        for(int i=0;i<k;++i){
            scanf("%d", &tmp);
            ans /= f[tmp];
        }
        printf("%d\n", ans);
    }

    return 0;
}
