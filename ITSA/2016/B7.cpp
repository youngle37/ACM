#include <stdio.h>
#include <vector>

using namespace std;

int M[510];
int dp[510][510];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);

        int temp;
        scanf("%d", &M[0]);
        for(int i=1;i<N;++i){
            scanf("%d", &temp);
            M[i] = temp;
            scanf("%d", &temp);
        }
        scanf("%d", &M[N]);

        memset(dp, 0, sizeof(dp));

        for(int k=0;k<N;++k){
            for(int i=1,j=1+k;j<=N;++i,++j){
                if(k == 0)
                    dp[i][i] = 0;
                else if(k == 1)
                    dp[i][j] = M[i-1]*M[i]*M[j];
                else{
                    int MIN = INT_MAX;
                    for(int l=i;l<j;++l){
                        int temp = dp[i][l]+dp[l+1][j]+M[i-1]*M[l]*M[j];
                        if(temp < MIN)
                            MIN = temp;
                    }

                    dp[i][j] = MIN;
                }
            }
        }

        printf("%d\n", dp[1][N]);
    }

    return 0;
}
