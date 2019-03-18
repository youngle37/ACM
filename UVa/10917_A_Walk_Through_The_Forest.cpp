/*
 * 反向從 home (2) 找單源最短路徑
 * 接著 DFS 計算路徑數
 */

#include <cstdio>
#include <cstring>

const int N = 1005;
const int INF = 0x3fffffff;

int n,m;

int dp[N];
int vis[N];
int map[N][N];
int d[N];

void init(){
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=n; i++) vis[i] = 0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            map[i][j] = i == j ? 0 : INF;
        }
    }
}

void input(){
    int a, b, w;
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &a, &b, &w);
        if(w > map[a][b]) continue;
        map[a][b] = map[b][a] = w;
    }
}

void Dijkstra(){
    int s = 2;
    
    for(int i=1; i<=n; i++) d[i] = map[s][i];
    
    vis[s] = 1;
    for(int i=1; i<m; i++){
        int min = INF;
        int k = s;
        for(int j=1; j<=n; j++){
            if(!vis[j] && d[j] < min){
                min = d[j];
                k = j;
            }
        }

        vis[k] = 1;
        for(int j=1; j<=n; j++){
            if(!vis[j] && d[j] > d[k] + map[k][j]){
                d[j] = d[k] + map[k][j];
            }
        }
    }
}

int DFS(int pos){
    if(pos == 2) return 1;
    if(dp[pos] > 0) return dp[pos];

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(map[pos][i] != INF && d[pos] > d[i]){
            ans += DFS(i);
        }
    }

    return dp[pos] = ans;
}

int main(){
    while(scanf("%d", &n) != EOF, n){
        init();
        scanf("%d", &m);
        input();
        Dijkstra();
        printf("%d\n", DFS(1));
    }

    return 0;
}
