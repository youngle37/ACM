#include <stdio.h>
#include <string.h>

#define max(a,b) (a > b ? a : b)

#define maxn 6000

int n;
int dp[maxn+5][2];
int father[maxn+5];
int vis[maxn+5];

void tree_dp(int node){
    vis[node] = 1;
    for(int i=1;i<=n;++i){
        if(!vis[i] && father[i] == node){
            tree_dp(i);

            dp[node][0] += max(dp[i][1], dp[i][0]);
            dp[node][1] += dp[i][0];
        }
    }
}

int main(){
    while(scanf("%d", &n) != EOF){
        memset(dp, 0, sizeof(dp));
        memset(father, 0, sizeof(father));
        memset(vis, 0, sizeof(vis));

        for(int i=1;i<=n;++i)
            scanf("%d", &dp[i][1]);

        int root = 0;
        int f,c;
        while(scanf("%d %d", &c, &f) && (c || f)){
            father[c] = f;
            root = f;
        }

        while(father[root]){
            root = father[root];
        }

        tree_dp(root);

        int MAX = max(dp[root][0], dp[root][1]);
        printf("%d\n", MAX);
    }

    return 0;
}
