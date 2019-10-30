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

#define MAXN 105

using namespace std;

int A[MAXN], B[MAXN];
bool edge[MAXN][MAXN];
int llink[MAXN], rlink[MAXN];
int vis[MAXN];

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

int main(){
    int cnt_case;
    scanf("%d", &cnt_case);
    for(int cnt=1; cnt<=cnt_case; ++cnt) {
        int n, m;
        scanf("%d", &n);
        for(int i=0; i<n; ++i) scanf("%d", &A[i]);
        scanf("%d", &m);
        for(int i=0; i<m; ++i) scanf("%d", &B[i]);

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if((A[i]!=0 && B[j]%A[i]==0)||(A[i]==0 && B[j]==0))
                    edge[i][j] = true;
                else
                    edge[i][j] = false;
            }
        }

        memset(llink, -1, sizeof(int)*(n+1));
        memset(rlink, -1, sizeof(int)*(m+1));
        int ans = 0;
        for(int i=0; i<n; ++i) {
            memset(vis, 0, sizeof(int)*(m+1));
            if(DFS(i, m)) ++ans;
        }

        printf("Case %d: %d\n", cnt, ans);
    }

    return 0;
}
