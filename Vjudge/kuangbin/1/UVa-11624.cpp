#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define Inf 0x3fffffff

int N,M;
char MAP[1010][1010];
int F[1010][1010];
int J[1010][1010];
int f_x,f_y;
int j_x,j_y;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int ans;

struct Node{
    int x;
    int y;
};

bool bfs(){
    Node now, next;

    queue<Node> Q;

    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(MAP[i][j] == 'F'){
                now.x = i; now.y = j;
                Q.push(now);
                F[i][j] = 1;
            }
        }
    }

    while(!Q.empty()){
        now = Q.front();
        Q.pop();

        for(int i=0;i<4;++i){
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];

            if(next.x < 0 || next.x >= N || next.y < 0 || next.y >= M || MAP[next.x][next.y] == '#')
                continue;

            if(F[next.x][next.y] == 0){
                F[next.x][next.y] = F[now.x][now.y] + 1;
                Q.push(next);
            }
        }
    }

    now.x = j_x; now.y = j_y;
    Q.push(now);
    J[j_x][j_y] = 1;

    while(!Q.empty()){
        now = Q.front();
        Q.pop();

        if(now.x == 0 || now.x == N-1 || now.y == 0 || now.y == M-1){
            ans = J[now.x][now.y];
            return true;
        }

        for(int i=0;i<4;++i){
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];

            if(next.x < 0 || next.x >= N || next.y < 0 || next.y >= M || MAP[next.x][next.y] == '#')
                continue;

            if(J[next.x][next.y] == 0 && (J[now.x][now.y] + 1 < F[next.x][next.y] || F[next.x][next.y] == 0)){
                J[next.x][next.y] = J[now.x][now.y] + 1;
                Q.push(next);
            }
        }
    }

    return false;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d\n", &N, &M);

        for(int i=0;i<N;++i){
            scanf("%s", MAP[i]);
            for(int j=0;j<M;++j){
                if(MAP[i][j] == 'J'){
                    MAP[i][j] = '.';
                    j_x = i;
                    j_y = j;
                }

                if(MAP[i][j] == 'F'){
                    f_x = i;
                    f_y = j;
                }

                F[i][j] = 0;
                J[i][j] = 0;
            }
        }

        if(bfs())
            printf("%d\n", ans);
        else
            printf("IMPOSSIBLE\n");

    }

    return 0;
}
