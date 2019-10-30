#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>

#define MAXN 205

using namespace std;

int n, m;
bool edge[MAXN][MAXN];
int color[MAXN];
int link[MAXN];
bool vis[MAXN];

bool IsBipartite(int node) {
    queue<int> q;
    q.push(node);
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int v=1; v<=n; ++v) {
            if(!edge[u][v]) continue;

            if(color[v] == -1) {
                color[v] = !color[u];
                q.push(v);
            } else if(color[v] == color[u])
                return false;
        }
    }

    return true;
}

bool DFS(int u) {
    for(int v=1; v<=n; ++v) {
        if(!edge[u][v] || vis[v]) continue;
        vis[v] = true;
        if(link[v] == -1 || DFS(link[v])) {
            link[v] = u;
            return true;
        }
    }
    return false;
}

int match() {
    int ans = 0;
    memset(link, -1, sizeof(link));
    for(int i=1; i<=n; ++i) {
        memset(vis, 0, sizeof(vis));
        if(DFS(i)) ++ans;
    }
    return ans/2;
}

int main(){
    while(~scanf("%d %d", &n, &m)) {
        memset(edge, 0, sizeof(edge));
        int u, v;
        for(int i=0; i<m; ++i) {
            scanf("%d %d", &u, &v);
            edge[u][v] = true;
            edge[v][u] = true;
        }

        memset(color, -1, sizeof(color));

        // If not bipartite
        bool bipartite = true;
        for(int i=1; i<=n; ++i) {
            if(color[i] == -1) {
                color[i] = 1;
                if(!IsBipartite(i)) {
                    bipartite = false;
                    break;
                }
            }
        }

        if(bipartite) printf("%d\n", match());
        else puts("No");

    }

    return 0;
}
