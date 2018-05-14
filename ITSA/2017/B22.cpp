#include <stdio.h>
#include <string.h>

#define max(a,b) ((a < b)?b:a)

int num[55];
int dp[55];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);

        for(int i=0;i<n;++i){
            scanf("%d", &num[i]);
            dp[i] = 1;
        }
/* AC too.
        for(int i=0;i<n;++i){
            for(int j=i+1; j<n;++j){
                if(num[j] <= num[i])
                    dp[j] = max(dp[j], dp[i]+1);
            }
        }
*/

        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(num[i] <= num[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }

        int ans = -1;
        for(int i=0;i<n;++i)
            if(ans < dp[i])
                ans = dp[i];

        printf("%d\n", ans);
    }

    return 0;
}
