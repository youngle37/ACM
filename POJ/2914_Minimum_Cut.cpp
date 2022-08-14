/*
 * POJ 2914
 * Stoer Wagner 算法
 * 
 * 任意選取 s-t 中
 * 若 s 和 t 為最小割異測 => s-t 最小割 = 答案
 * 若 s 和 t 為最小割同側 => s-t 最小割 >= 答案
 *
 * 利用 Maximum Adjacency Search O(V^2) 求得 s-t 最小割
 * 並且合併 s t 兩點
 */

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

#define MAXN 505
#define INF 0x3f3f3f3f

using namespace std;

int N, M;
int G[MAXN][MAXN];
int v[MAXN];        // v[i] 代表點 i 合併到點 v[i]
bool vis[MAXN];
int w[MAXN];        // w(A, x) = ∑w(v[i],x)，v[i]∈A

int minimum_cut_phase(int &n) {
    memset(vis, 0, sizeof(vis));
    memset(w, 0, sizeof(w));

    int pre = 0;                // 上次加入集合 A 的點
    int cur = -1;
    for(int i=1; i<n; ++i) {    // 尋找 V-A 中 w(A, j) 為最大的點
        cur = -1;
        for(int j=1; j<n; ++j) {
            if(!vis[v[j]]) {
                w[v[j]] += G[v[pre]][v[j]];
                if(cur == -1 || w[v[cur]] < w[v[j]])
                    cur = j;
            }
        }

        vis[v[cur]] = true;         // 加入集合 A

        if(i != n-1)
            pre = cur;
    }
    
    /* 最後加入的兩點為目前圖 G 的最小割 */
    const int s = v[pre], t = v[cur];
    for(int i=0; i<n; ++i) {        // 將 t 合併至 s
        G[s][v[i]] += G[v[i]][t];
        G[v[i]][s] += G[t][v[i]];
    }
    v[cur] = v[--n];                // 將最後一個點換到原本 t 位置

    return w[t];
}

int stoer_wagner(int n) {
    for(int i=0; i<n; ++i)
        v[i] = i;

    int min_cut = INF;
    while(n > 1) {
        min_cut = min(min_cut, minimum_cut_phase(n));
    }

    return min_cut;
}

int main(){
    while(scanf("%d %d", &N, &M) != EOF) {
        memset(G, 0, sizeof(G));
        for(int i=0; i<M; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            G[u][v] += w;
            G[v][u] += w;
        }

        printf("%d\n", stoer_wagner(N));
    }

    return 0;
}
