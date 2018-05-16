#include <stdio.h>
#include <string.h>

#define maxn 100
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)

char map[maxn+5][maxn+5];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int M, N, Q;
        scanf("%d %d %d\n", &M, &N, &Q);
        printf("%d %d %d\n", M, N, Q);

        for(int i=0;i<M;++i)
            gets(map[i]);

        int x,y;
        while(Q--){
            scanf("%d %d", &x, &y);
            int ans = 1;
            for(int i=0;i<=M || i<=N;++i){
                int flag = 0;
                for(int a=x-i; a<=x+i;++a){
                    for(int b=y-i; b<=y+i; ++b){
                        if(a < 0 || b < 0 || a >= M || b >= N){
                            flag = 1;
                            break;
                        }
                        if(map[a][b] != map[x][y])
                            flag = 1;
                    }
                }

                if(flag == 0){
                    ans = max(ans, 2*i+1);
                }else
                    break;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
