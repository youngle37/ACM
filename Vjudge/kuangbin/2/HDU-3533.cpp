#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Castle {
    char c;
    int t, v, x, y;
} castles[105];

struct Node {
    int t;
    int x, y;
};

int M, N, K, D;
int ans;

bool vis[105][105][1005];
bool bullet[105][105][1005];
bool maze[105][105];
int dx[5] = {1, -1, 0, 0, 0};
int dy[5] = {0, 0, 1, -1, 0};

void processBullet() {
    for(int i = 0; i < K; i++) {
        Castle ca = castles[i];
        int limit;
        switch(ca.c) {
        case 'N':
            limit = 0;
            for(int x = ca.x - 1; x >= 0; x--) {
                if(maze[x][ca.y]) {
                    limit = x;
                    break;
                }
            }

            for(int t = 1; t <= D; t += ca.t) {
                int tmp = t;
                for(int pos = ca.x - ca.v; pos >= limit; pos -= ca.v)
                    bullet[pos][ca.y][tmp++] = 1;
            }

            break;
        case 'E':
            limit = N;
            for(int y = ca.y + 1; y <= N; y++) {
                if(maze[ca.x][y]) {
                    limit = y;
                    break;
                }
            }

            for(int t = 1; t <= D; t += ca.t) {
                int tmp = t;
                for(int pos = ca.y + ca.v; pos <= limit; pos += ca.v)
                    bullet[ca.x][pos][tmp++] = 1;
            }

            break;
        case 'S':
            limit = M;
            for(int x = ca.x + 1; x <= M; x++) {
                if(maze[x][ca.y]) {
                    limit = x;
                    break;
                }
            }

            for(int t = 1; t <= D; t += ca.t) {
                int tmp = t;
                for(int pos = ca.x + ca.v; pos <= limit; pos += ca.v)
                    bullet[pos][ca.y][tmp++] = 1;
            }

            break;
        case 'W':
            limit = 0;
            for(int y = ca.y - 1; y >= 0; y--) {
                if(maze[ca.x][y]) {
                    limit = y;
                    break;
                }
            }

            for(int t = 1; t <= D; t += ca.t) {
                int tmp = t;
                for(int pos = ca.y - ca.v; pos >= limit; pos -= ca.v)
                    bullet[ca.x][pos][tmp++] = 1;
            }

            break;
        }
    }
}

bool check(Node n) {
    if(n.x < 0 || n.y < 0 || n.x > M || n.y > N) return false;
    if(maze[n.x][n.y]) return false;
    if(vis[n.x][n.y][n.t]) return false;
    if(bullet[n.x][n.y][n.t]) return false;
    return true;
}

void BFS() {
    queue<Node> q;

    Node init;
    init.t = 0;
    init.x = 0, init.y = 0;
    vis[0][0][0] = 1;
    q.push(init);

    while(!q.empty()) {
        Node cur = q.front();
        q.pop();

        if(cur.t >= D) return;
        if(cur.x == M && cur.y == N) {
            ans = cur.t;
            return;
        }

        for(int i = 0; i < 5; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            Node tmp;
            tmp.t = cur.t + 1;
            tmp.x = nx, tmp.y = ny;

            if(check(tmp)) {
                vis[tmp.x][tmp.y][tmp.t] = 1;
                q.push(tmp);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    while(cin >> M >> N >> K >> D) {
        memset(vis, 0, sizeof(vis));
        memset(maze, 0, sizeof(maze));
        memset(bullet, 0, sizeof(bullet));
        ans = 1 << 30;

        for(int i = 0; i < K; i++) {
            cin >> castles[i].c >> castles[i].t;
            cin >> castles[i].v >> castles[i].x >> castles[i].y;
            maze[castles[i].x][castles[i].y] = 1;
        }

        if(maze[M][N]) {
            cout << "Bad luck!\n";
            continue;
        }

        processBullet();
        BFS();

        if(ans == (1 << 30))
            cout << "Bad luck!\n";
        else
            cout << ans << '\n';
    }

    return 0;
}
