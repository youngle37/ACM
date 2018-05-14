#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;

#define maxn 1050
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define x first
#define y second

int n;
char map[maxn][maxn];
bool vis[maxn][maxn];
int ans;

void BFS(int i, int j){
    queue<pii> Q;
    Q.push(mp(i,j));

    while(!Q.empty()){
        pii now = Q.front();
        Q.pop();

        if(now.x > 0 && !vis[now.x-1][now.y] && map[now.x-1][now.y] == '0'){
            Q.push(mp(now.x-1,now.y));
            vis[now.x-1][now.y] = 1;
        }
        if(now.x < n-1 && !vis[now.x+1][now.y] && map[now.x+1][now.y] == '0'){
            Q.push(mp(now.x+1, now.y));
            vis[now.x+1][now.y] = 1;
        }
        if(now.y > 0 && !vis[now.x][now.y-1] && map[now.x][now.y-1] == '0'){
            Q.push(mp(now.x, now.y-1));
            vis[now.x][now.y-1] = 1;
        }
        if(now.y < n-1 && !vis[now.x][now.y+1] && map[now.x][now.y+1] == '0'){
            Q.push(mp(now.x, now.y+1));
            vis[now.x][now.y+1] = 1;
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);

        for(int i=0;i<n;++i){
            scanf("%s", &map[i]);
        }

        ans = 0;

        memset(vis, 0, sizeof(vis));

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(vis[i][j] || map[i][j] == '1')
                    continue;

                BFS(i,j);
                ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
