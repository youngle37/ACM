#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>

#define x first
#define y second

using namespace std;

int N, M;
int maze[805][805];
int vis[2][805][805];
vector<pair<int, int>> ghost(2);
pair<int, int> Err, Girl;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q[2];
int step;

int check(pair<int, int> pos) {
    if(pos.x<0 || pos.y<0 || pos.x>=N || pos.y>=M || maze[pos.x][pos.y])
        return 0;
    if((abs(pos.x-ghost[0].x)+abs(pos.y-ghost[0].y)) <= 2*step)
        return 0;
    if((abs(pos.x-ghost[1].x)+abs(pos.y-ghost[1].y)) <= 2*step)
        return 0;
    
    return 1;
}

int bfs(int person) {
    int time = q[person].size();
    while(time--) {
        pair<int, int> cur = q[person].front();
        q[person].pop();
        if(check(cur)) {
            for(int i=0; i<4; i++){
                pair<int, int> next;
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];

                if(!check(next))
                    continue;
                
                if(!vis[person][next.x][next.y]) {
                    if(vis[person^1][next.x][next.y])
                        return 1;
                    q[person].push(next);
                    vis[person][next.x][next.y] = 1;
                }
            }
        }
    }
    return 0;
}

int solve() {
    while(q[0].size() || q[1].size()) {
        step++;
        if(bfs(0))
            return step;
        if(bfs(0))
            return step;
        if(bfs(0))
            return step;
        if(bfs(1))
            return step;
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        cin >> N >> M;
        cin.ignore();

        string line;
        ghost.clear();
        memset(maze, 0, sizeof(maze));
        for(int i=0; i<N; i++){
            getline(cin, line, '\n');
            for(int j=0; j<M; j++){
                switch(line[j]){
                case '.': maze[i][j] = 0; break;
                case 'X': maze[i][j] = 1; break;
                case 'M': Err.x = i; Err.y = j; break;
                case 'G': Girl.x = i; Girl.y = j; break;
                case 'Z': ghost.push_back(make_pair(i, j)); break;
                }
            }
        }

        memset(vis, 0, sizeof(vis));
        while(!q[0].empty()) q[0].pop();
        while(!q[1].empty()) q[1].pop();

        vis[0][Err.x][Err.y] = 1;
        vis[1][Girl.x][Girl.y] = 1;

        q[0].push(Err);
        q[1].push(Girl);

        step = 0;

        cout << solve() << '\n';
    }

    return 0;
}
