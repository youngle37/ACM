#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <string.h>

#define INF 0x3f3f3f3f
#define MAXN 105

int n, m;
int s, t;
int sum;
int G[MAXN][MAXN];
int d[MAXN];
int vis[MAXN];
int path[MAXN];

using namespace std;

void spfa() {
    queue<int> q;
    for(int i=1; i<=n; ++i) {
        d[i] = INF;
        vis[i] = 0;
        path[i] = s;
    }

    d[s] = 0;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()) {
        int u;
        u = q.front();
        q.pop();
        vis[u] = 0;
        for(int v=1; v<=n; ++v) {
            if(d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
                path[v] = u;
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    
    return;
}

void change(int v) {
    int u = path[v];
    G[u][v] = -G[u][v];
    G[v][u] = INF;
    if(u == s) return;
    change(u);
}

int main(){
    while(scanf("%d", &n) != EOF && n) {
        cin >> m;
        memset(G, 0x3f, sizeof(G));
        for(int i=1; i<=m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            G[u][v] = G[v][u] = w;
        }

        s = 1;
        t = n;

        spfa();
        sum = d[t];
        if(d[t] == INF) {
            cout << "Back to jail\n";
            continue;
        }

        change(t);

        s = n;
        t = 1;

        spfa();
        if(d[t] == INF)
            cout << "Back to jail\n";
        else
            cout << sum+d[t] << '\n';
    }

    return 0;
}
