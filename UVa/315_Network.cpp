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

#define MAXN 105

using namespace std;

int N;
int ttime;
int dis[MAXN], low[MAXN];
bool ap[MAXN];
vector<int> G[MAXN];

void Tarjan(int parent, int u) {
    dis[u] = low[u] = ++ttime;

    int son = 0;
    for(int i=0; i<G[u].size(); ++i) {
        int v = G[u][i];
        if(v == parent) continue;
        if(!dis[v]) {
            ++son;
            Tarjan(u, v);
            if(low[u] > low[v])
                low[u] = low[v];
            if(u != parent && low[v] >= dis[u])
                ap[u] = true;
        } else if(low[u] > dis[v]) {
            low[u] = dis[v];
        }
    }

    if(parent == u && son > 1) ap[u] = true;
}

int main(){
    while(scanf("%d", &N) && N) {
        memset(dis, 0, sizeof(dis));
        memset(low, 0, sizeof(low));
        memset(ap, 0, sizeof(ap));
        for(int i=1; i<MAXN; ++i) G[i].clear();
        ttime = 0;

        int u, v;
        char ch;
        while(scanf("%d", &u) && u) {
            while(scanf("%d%c", &v, &ch)) {
                G[u].push_back(v);
                G[v].push_back(u);
                if(ch == '\n') break;
            }
        }

        int ans = 0;
        for(int i=1; i<=N; ++i) if(!dis[i]) Tarjan(i, i);
        for(int i=1; i<=N; ++i) if(ap[i]) ++ans;
        printf("%d\n", ans);
    }

    return 0;
}
