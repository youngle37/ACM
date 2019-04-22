#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define Inf 0x3fffffff

string MAP[20];
int N,M;
int grass;
bool vis[200][200];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct node{
    int x;
    int y;
    int step;
};

node map[200];

bool valid(node a){
    return a.x >=0 && a.x < N && a.y >= 0 && a.y < M;
}

int bfs(int x1, int y1, int x2, int y2){
    int time = 0;

    node p, q;
    
    p.x = x1; p.y = y1; p.step = 0;
    q.x = x2; q.y = y2; q.step = 0;

    queue<node> Q;
    Q.push(p);
    Q.push(q);
    while(!Q.empty()){
        node now, next;
        now = Q.front();
        Q.pop();

        for(int i=0;i<4;++i){
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];

            if(valid(next) && !vis[next.x][next.y] && MAP[next.x][next.y] == '#'){
                vis[next.x][next.y] = true;
                next.step = now.step+1;
                Q.push(next);
            }
        }

        time = max(time, now.step);
    }

    return time;
}

int main(){
    int T;
    scanf("%d", &T);
    int t=1;
    while(T--){
        scanf("%d %d\n", &N, &M);

        printf("Case %d: ",t++);

        grass = 0;
        for(int i=0;i<N;++i){
            getline(cin, MAP[i]);
            for(int j=0;j<M;++j){
                if(MAP[i][j] == '#'){
                    map[grass].x = i;
                    map[grass].y = j;
                    grass++;
                }
            }
        }

        if(grass <= 2){
            printf("%d\n", 0);
            continue;
        }

        int ans = Inf;
        for(int i=0;i<grass;++i){
            for(int j=i;j<grass;++j){
                memset(vis, 0, sizeof(vis));

                bool remain_grass = false;

                vis[map[i].x][map[i].y] = true;
                vis[map[j].x][map[j].y] = true;

                int time = bfs(map[i].x, map[i].y, map[j].x, map[j].y);

                for(int k=0;k<N;++k){
                    if(remain_grass)
                        break;
                    for(int l=0;l<M;++l){

                        if(MAP[k][l] != '#')
                            continue;

                        if(!vis[k][l]){
                            remain_grass = true;
                            break;
                        }
                    }
                }

                if(!remain_grass)
                    ans = min(ans, time);
            }
        }

        if(ans == Inf)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}
