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

using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 105

struct Edge {
    int to;
    int next;
    int cap, flow, r;

    Edge(int to, int next, int cap): to(to), next(next), cap(cap), flow(0), r(cap) {}
};

vector<Edge> e;
int head[MAXN];
int level[MAXN];
int cur[MAXN];

void add_edge(int from, int to, int cap) {
    e.push_back(Edge(to, head[from], cap));
    head[from] = e.size() - 1;
    e.push_back(Edge(from, head[to], cap));
    head[to] = e.size() - 1;
}

int dfs(int u, int t, int cur_flow = INF) {
    if(u == t || !cur_flow) return cur_flow;

    int df, tf = 0;
    for(int &i=cur[u]; ~i; i=e[i].next) {
        if(level[e[i].to]==level[u]+1 && e[i].r) {
            if(df=dfs(e[i].to, t, min(cur_flow, e[i].r))) {
                e[i].flow += df;
                e[i^1].flow -= df;
                e[i].r -= df;
                e[i^1].r += df;
                tf += df;
                if(!(cur_flow -= df)) break;
            }
        }
    }
    if(!df) level[u] = 0; // 最後一個邊也沒用處，不需要 u 了
    return tf;
}

bool bfs(int s, int t) {
    memset(level, 0, sizeof(level));
    memcpy(cur, head, sizeof(head));

    queue<int> q;
    q.push(s);
    level[s] = 1;
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int i=head[u]; ~i; i=e[i].next) {
            if(!level[e[i].to] && e[i].r) {
                level[e[i].to] = level[u] + 1;
                q.push(e[i].to);
                if(e[i].to == t) return true;
            }
        }
    }

    return false;
}

int dinic(int s, int t) {
    int flow = 0;
    while(bfs(s, t))
        flow += dfs(s, t);
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    int s, t, m;
    int cnt = 1;
    while(cin >> n && n) {
        e.clear();
        memset(head, -1, sizeof(head));

        cin >> s >> t >> m;

        int from, to, cap;
        for(int i = 0; i < m; ++i) {
            cin >> from >> to >> cap;
            add_edge(from, to, cap);
        }

        cout << "Network " << cnt++ << "\nThe bandwidth is " << dinic(s, t) << ".\n\n";
    }

    return 0;
}
