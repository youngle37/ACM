#include <cstdio>
#include <cstring>

#define min(a,b) a<b ? a : b

const int N = 55;
const int INF = 0x3fffffff;

int l, n;
int points[N];
int dp[N][N];

int cut(int l, int r){
    for(int i=r-2; i>=0; i--){
        for(int j=i+2; j<=r; j++){
            int minv = INF;
            for(int k=i+1; k<j; k++){
                minv = min(minv, dp[i][k] + dp[k][j]);
            }
            dp[i][j] = points[j] - points[i] + minv;
        }
    }
    
    return dp[l][r];
}

int main(){
    while(scanf("%d", &l), l){
        scanf("%d", &n);
        
        points[0] = 0;
        for(int i=1;i<=n;i++)
            scanf("%d", &points[i]);
        points[n+1] = l;

        for(int i=0;i<=n+1; i++){
            for(int j=0; j<=n+1; j++){
                dp[i][j] = 0;
            }
        }

        printf("The minimum cutting is %d.\n", cut(0, n+1));
    }
    return 0;
}
