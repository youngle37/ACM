#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int L, R, C;
vector<vector<string>> map(31, vector<string>());
vector<vector<vector<bool>>> visit(31, vector<vector<bool>>(31, vector<bool>(31, false)));
int s_L, s_R, s_C;
int e_L, e_R, e_C;

int steps[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

class Node {
public:
    int l, r, c;
    int t;
};

bool valid(const Node& n) {
    int l = n.l;
    int r = n.r;
    int c = n.c;

    if(l >= 0 && l < L && r >= 0 && r < R && c >= 0 && c < C && map[l][r][c] != '#')
        return true;
    else
        return false;
}

int BFS() {
    Node start;
    start.l = s_L;
    start.r = s_R;
    start.c = s_C;
    start.t = 0;

    queue<Node> q;
    q.push(start);
    visit[s_L][s_R][s_C] = true;

    while(!q.empty()) {
        Node temp = q.front();
        q.pop();

        for(int i = 0; i < 6; ++i) {
            Node now = temp;

            now.l += steps[i][0];
            now.r += steps[i][1];
            now.c += steps[i][2];
            if(valid(now) && !visit[now.l][now.r][now.c]) {
                ++now.t;
                visit[now.l][now.r][now.c] = true;
                q.push(now);

                if(now.l == e_L && now.r == e_R && now.c == e_C)
                    return now.t;
            }
        }
    }

    return 0;
}

int main() {
    while(cin >> L >> R >> C) {
        if(!L && !R && !C)
            break;

        cin.ignore(255, '\n');

        string line;
        for(int i = 0; i < L; ++i) {
            for(int j = 0; j < R; ++j) {
                getline(cin, line);
                map[i].push_back(line);

                if(line.find('S') != string::npos) {
                    s_L = i;
                    s_R = j;
                    s_C = line.find('S');
                }

                if(line.find('E') != string::npos) {
                    e_L = i;
                    e_R = j;
                    e_C = line.find('E');
                }
            }
            cin.ignore(255, '\n');
        }

        for(int i = 0; i < 31; ++i)
            for(int j = 0; j < 31; ++j)
                fill(visit[i][j].begin(), visit[i][j].end(), false);

        int ans = BFS();

        if(ans)
            cout << "Escaped in " << ans << " minute(s).\n";
        else
            cout << "Trapped!\n";
    }

    return 0;
}
