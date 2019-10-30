#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>

#define MAXN 1005

using namespace std;

int R,C,N;
vector<int> row[MAXN];
vector<int> col[MAXN];
bool visL[MAXN], visR[MAXN];
int llink[MAXN], rlink[MAXN];

bool DFS(int u) {
    visL[u] = true;
    for(int i=0; i<row[u].size(); ++i) {
        int v = row[u][i];
        if(visR[v]) continue;

        visR[v] = true;
        if(rlink[v] == -1 || DFS(rlink[v])) {
            rlink[v] = u;
            llink[u] = v;
            return true;
        }
    }
    return false;
}

int main(){
    while(scanf("%d %d %d", &R, &C, &N) && R && C && N) {
        for(int i=1; i<MAXN; ++i) {
            row[i].clear();
            col[i].clear();
        }

        int r, c;
        for(int i=0; i<N; ++i) {
            scanf("%d %d", &r, &c);
            row[r].push_back(c);
            col[c].push_back(r);
        }

        int ans = 0;
        memset(llink, -1, sizeof(llink));
        memset(rlink, -1, sizeof(rlink));
        for(int i=1; i<=R; ++i) {
            if(row[i].size()) {
                memset(visR, 0, sizeof(visR));
                if(DFS(i)) ++ans;
            }
        }

        memset(visL, 0, sizeof(visL));
        memset(visR, 0, sizeof(visR));
        for(int i=1; i<=R; ++i) {
            if(llink[i] == -1) 
                DFS(i);
        }

        printf("%d", ans);
        for(int i=1; i<=R; ++i) if(!visL[i]) printf(" r%d", i);
        for(int i=1; i<=C; ++i) if(visR[i]) printf(" c%d", i);
        printf("\n");
    }

    return 0;
}
