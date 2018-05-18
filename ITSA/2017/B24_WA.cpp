#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0x3fffffff
#define min(a,b) (a < b ? a : b)

#define maxn 500

vector<int> G[maxn+5];
int risk[maxn+5][maxn+5];
int length[maxn+5][maxn+5];
int d[maxn+5];
bool Select[maxn+5][maxn+5];
int vis[maxn+5];
int N, M;

int ans;

int minD(){
    int MIN = INF;
    int index;

    for(int i=0;i<N;++i){
        if(!vis[i] && d[i] <= MIN)
            MIN = d[i], index = i;
    }

    return index;
}

void DFS(int node, int sum){
    if(node == N-1){
        ans = min(ans, sum);
        return;
    }

    for(int i=0;i<N;++i){
        if(Select[node][i])
            DFS(i, sum+length[node][i]);
    }

    return;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);

        for(int i=0;i<N;++i)
            G[i].clear();

        memset(vis, 0, sizeof(vis));
        memset(Select, 0, sizeof(Select));
        
        fill(&risk[0][0], &risk[0][0]+sizeof(risk)/sizeof(int), INF);
        fill(&length[0][0], &length[0][0]+sizeof(length)/sizeof(int), INF);

        if(N == 1){
            int x,y,r,w;
            int MIN_index, MIN_len = INF, MIN_risk = INF;
            for(int i=0;i<M;++i){
                scanf("%d %d %d %d", &x, &y, &r, &w);
                if(r < MIN_risk)
                    MIN_risk = r, MIN_len = w;
                else if(r == MIN_risk && w < MIN_len)
                    MIN_len = w;
            }

            printf("%d %d\n", MIN_risk, MIN_len);
            continue;
        }

        int x, y, r, w;
        for(int i=0;i<M;++i){
            scanf("%d %d %d %d", &x, &y, &r, &w);
            G[x].push_back(y);
            risk[x][y] = min(risk[x][y], r);
            length[x][y] = min(length[x][y], w);
        }

        fill(d, d+maxn+5, INF);

        d[0] = 0;

        for(int count=0; count<N-1; count++){
            int u = minD();

            vis[u] = true;

            for(int v=0; v<G[u].size();++v){
                if(!vis[G[u][v]] && d[u] != INF && d[u]+risk[u][G[u][v]] < d[G[u][v]]){
                    d[G[u][v]] = d[u]+risk[u][G[u][v]], Select[u][G[u][v]] = 1;
                    for(int m=0;m<N;++m)
                        if(Select[m][G[u][v]] && m != u)
                            Select[m][G[u][v]] = 0;
                }else if(!vis[G[u][v]] && d[u] != INF && d[u]+risk[u][G[u][v]] == d[G[u][v]]){
                    Select[u][G[u][v]] = 1;
                }
            }

        }

        ans = INF;
        DFS(0, 0);
        if(ans != INF)
            printf("%d %d\n", d[N-1], ans);
        else
            printf("-1\n");
    }

    return 0;
}
