#include <cstdio>

#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a<b)?b:a)


int main(){
    int n, m, r;
    scanf("%d%d%d", &n, &m, &r);

    int morn_min = 2000000;
    int even_max = -1;
    int s;
    for(int i=0; i<n; i++){
        scanf("%d", &s);
        morn_min = min(morn_min, s);
    }
    for(int i=0; i<m; i++){
        scanf("%d", &s);
        even_max = max(even_max, s);
    }

    if(morn_min >= even_max || morn_min > r){
        printf("%d\n", r);
        return 0;
    }

    int buy = r/morn_min;
    printf("%d\n", (even_max-morn_min)*buy+r);

    return 0;
}
