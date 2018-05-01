#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define maxn 1000

struct Seg{
    int left;
    int right;
    int val;
    Seg(){}
    Seg(int le, int ri):left(le),right(ri){
        val = 1;
    }
};

vector<Seg> place(maxn+5);
vector<int> G[maxn+5];
int N;
int dp[maxn+5];
int from[maxn+5];
int vis[maxn+5];

int main(){
    while(scanf("%d", &N) != EOF){
        for(int i=1;i<=N;++i)
            G[i].clear();

        int a, b;
        for(int i=1;i<=N;++i){
            scanf("%d %d", &a, &b);

            int left = a+1;
            int right = N-b;
            place[i] = Seg(left,right);

            if(left > right)
                continue;
            
            bool exist = false;
            for(int j=0;!exist&&j<G[right].size();++j){
                int id = G[right][j];
                Seg &now = place[id];

                if(now.left == left && now.right == right){
                    exist = true;
                    now.val = min(right-left+1, now.val+1);
                    break;
                }
            }

            if(exist)
                continue;

            G[right].push_back(i);
        }

        dp[0] = 0;
        from[0] = -1;
        for(int i=1;i<=N;++i){
            dp[i] = dp[i-1];
            from[i] = -1;
            for(int j=0;j<G[i].size();++j){
                int id = G[i][j];
                int p = place[id].left - 1;
                if(dp[p] + place[id].val > dp[i]){
                    from[i] = id;
                    dp[i] = dp[p] + place[id].val;
                }
            }
        }

        printf("%d", N-dp[N]);

        memset(vis, 0, sizeof(vis));

        int s = N;
        while(s){
            while(s && from[s] == -1)
                s--;

            if(!s)
                break;

            int id = from[s];
            int left = place[id].left;
            int cnt = place[id].val;
            for(int i=1;cnt && i<=N; ++i){
                if(place[i].left == left && place[i].right == s){
                    cnt--;
                    vis[i] = true;
                }
            }

            s = left - 1;
        }

        for(int i=1;i<=N;++i){
            if(!vis[i])
                printf(" %d", i);
        }

        printf("\n");
    }

    return 0;
}
