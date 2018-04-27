#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 32767;

vector<int> g[MAXN];
int dist[MAXN];
int deg[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            g[i].clear(), deg[i] = 0, dist[i] = -1;

        int u,v;
        for(int i=1;i<n;++i){
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++,deg[v]++;
        }

        queue<int> Q;
        for(int i=0;i<n;++i)
            if(deg[i] == 1)
                Q.push(i), dist[i] = 1;

        while(!Q.empty()){
            u = Q.front(), Q.pop();
            for(int i=0;i<g[u].size();++i){
                v = g[u][i];
                if(--deg[v] == 1){
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
        }

        int mx = 0, ans;
        for(int i=0;i<n;++i){
            if(dist[i] > mx)
                mx = dist[i], ans = i;
        }

        printf("%d\n", ans);
    }
    return 0;
}
