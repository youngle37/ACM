/**
 * 朱劉算法
 * in[v]：指向 v 的最小權重邊 (入邊)
 * pre[v]：指向 v 的最小權重邊的點
 **/
#include <cstdio>
#include <cstring>

#define maxn 1005
#define maxe 40005
#define INF 0x3fffffff

struct Edge{
    int from;
    int to;
    int cost;
} edges[maxe];

int n, m;
int in[maxn];
int pre[maxn];
int id[maxn];
int vis[maxn];

int directed_mst(int root){
    int ans = 0;
    while(true){
        // 找最小入邊
        for(int i=0; i<n; i++)
            in[i] = INF;
        for(int i=0; i<m; i++){
            int u = edges[i].from;
            int v = edges[i].to;
            int w = edges[i].cost;
            if(w < in[v] && u != v){
                in[v] = w;
                pre[v] = u;
            }
        }

        for(int i=0; i<n; i++){
            if(i == root) continue;
            if(in[i] == INF) return -1;     // 代表圖不連通
        }

        // 找環
        int node_cnt = 0;   // 將環縮成點後的點數量
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;
        for(int i=0; i<n; i++){
            ans += in[i];
            int v = i;
            while(vis[v] != i && id[v] == -1 && v != root){
                vis[v] = i;
                v = pre[v];
            }
            if(id[v] == -1 && v != root){   // 代表上面的 while 是因為找到環才跳出來
                // 將此環的編號全設為一樣
                for(int u=pre[v]; u!=v; u=pre[u]){
                    id[u] = node_cnt;
                }
                id[v] = node_cnt++;
            }
        }

        if(node_cnt == 0)   // 代表沒有環，已經找到最小生成樹
            break;

        // 將沒編號的點補上
        for(int i=0; i<n; i++){
            if(id[i] == -1)
                id[i] = node_cnt++;
        }

        // 縮點，重新編號
        for(int i=0; i<m; i++){
            int v = edges[i].to;
            edges[i].from = id[edges[i].from];
            edges[i].to = id[edges[i].to];
            if(edges[i].from != edges[i].to){
                edges[i].cost -= in[v];
            }
        }

        n = node_cnt;
        root = id[root];
    }
    return ans;
}

int main(){
    int T;
    int cnt = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i=0; i<m; i++){
            scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].cost);
        }
        int ans = directed_mst(0);
        printf("Case #%d: ", ++cnt);
        if(ans == -1)
            printf("Possums!\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}
