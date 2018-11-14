#include <cstdio>
#include <cstring>

#define min(a,b) ((a < b) ? a : b)
#define max(a,b) ((a < b) ? b : a)

bool dp[650][650];
int candies[35];

int difference(int a, int b, int c){
    return max(max(a,b), c) - min(min(a,b), c);
}

int main(){
    int T, t=1;
    scanf("%d", &T);
    
    while(T--){
        int n;
        scanf("%d", &n);

        int sum = 0;
        for(int i=0;i<n;++i){
            scanf("%d", &candies[i]);
            sum += candies[i];
        }

        memset(dp, 0, sizeof(dp));

        dp[0][0] = true;

        for(int k=0; k<n; k++){
            for(int i=sum; i>=0; i--){
                for(int j=sum; j>=0; j--){
                    if(dp[i][j]){
                        dp[i+candies[k]][j] = true;
                        dp[i][j+candies[k]] = true;
                    }
                }
            }
        }

        int ans = 0x3fffffff;
        for(int i=0; i<=sum; i++){
            for(int j=0; j<=sum; j++){
                if(dp[i][j]){
                    ans = min(ans, difference(i, j, sum-i-j));
                }
            }
        }

        printf("Case %d: %d\n", t++, ans);
    }

    return 0;
}
