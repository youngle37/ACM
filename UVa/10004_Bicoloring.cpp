#include <cstdio>
#include <string.h>

using namespace std;

int N, E;
bool adj[210][210];
bool visit[210];
bool color[210];

bool DFS(int n){
    for(int k=0;k<N;++k){
        if(!visit[k] && adj[n][k]){
            visit[k] = true;

            color[k] = !color[n];

            if(!DFS(k))
                return false;
        } else if(color[k] == color[n] && adj[n][k])
            return false;
    }

    return true;
}

int main(){
    while(scanf("%d", &N) && N){
        scanf("%d", &E);

        memset(color, false, sizeof(color));
        memset(adj, false, sizeof(adj));
        memset(visit, false, sizeof(visit));

        int x, y;
        for(int i=0;i<E;++i){
            scanf("%d%d", &x, &y);

            adj[x][y] = true;
            adj[y][x] = true;
        }

        color[0] = true;
        visit[0] = true;
        if(DFS(0))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }

    return 0;
}
