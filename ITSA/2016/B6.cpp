#include <stdio.h>
#include <vector>

using namespace std;

int N[211];
int M[55];
bool dp[200100];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n,m;
        scanf("%d %d", &n, &m);

        for(int i=0;i<n;++i)
            scanf("%d", &N[i]);

        int MAX_M = -1;
        for(int i=0;i<m;++i){
            scanf("%d", &M[i]);
            if(M[i] > MAX_M)
                MAX_M = M[i];
        }

        memset(dp, 0, sizeof(dp));
        
        dp[0] = 1;
        for(int i=0;i<n;++i){
            for(int j=MAX_M; j>=N[i]; j--){
                if(dp[j-N[i]])
                    dp[j] = 1;
            }
        }

        int ans = 0;
        for(int i=0;i<m;++i){
            if(dp[M[i]])
                ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}
