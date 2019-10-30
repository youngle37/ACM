#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string.h>

#define MAXN 105

using namespace std;

struct Point {
    double x, y;
};

Point gopher[MAXN], hole[MAXN];
bool edge[MAXN][MAXN];
int llink[MAXN], rlink[MAXN];
bool vis[MAXN];

bool DFS(int u, const int m) {
    for(int v=0; v<m; ++v) {
        if(edge[u][v] == false || vis[v]) continue;
        vis[v] = true;
        if(rlink[v] == -1 || DFS(rlink[v], m)) {
            llink[u] = v;
            rlink[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m, s, v;
    while(scanf("%d %d %d %d", &n, &m, &s, &v) == 4) {
        for(int i=0; i<n; ++i) scanf("%lf %lf", &gopher[i].x, &gopher[i].y);
        for(int i=0; i<m; ++i) scanf("%lf %lf", &hole[i].x, &hole[i].y);

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                double dis = sqrt(pow(gopher[i].x-hole[j].x,2)+pow(gopher[i].y-hole[j].y,2));
                if(dis/v <= s)
                    edge[i][j] = true;
                else
                    edge[i][j] = false;
            }
        }

        int ans = 0;
        memset(llink, -1, sizeof(llink));
        memset(rlink, -1, sizeof(rlink));
        for(int i=0; i<n; ++i) {
            memset(vis, 0, sizeof(vis));
            if(DFS(i, m)) ++ans;
        }

        printf("%d\n", n-ans);
    }

    return 0;
}
