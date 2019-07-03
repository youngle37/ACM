#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>

#define x first
#define y second

using namespace std;

struct Node {
    int s[9];
    int cur;
    int n;
} st, res;

int fac[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
string path[362885];
int vis1[362885], vis2[362885];

int dx1[4] = {1, 0, 0, -1};
int dy1[4] = {0, -1, 1, 0};
int dx2[4] = {-1, 0, 0, 1};
int dy2[4] = {0, 1, -1, 0};
char p[4] = {'d', 'l', 'r', 'u'};

int cnt = 0;

int cantor(int *s) {
    int sum = 1;
    for(int i=0; i<8; i++){
        int k = 0;
        for(int j=i+1; j<9; j++){
            if(s[i] > s[j])
                k++;
        }
        sum += k*fac[8-i];
    }
    return sum;
}

string bfs() {
    if(st.n == res.n) return "";

    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));

    queue<Node> q1, q2;

    vis1[st.n] = 1;
    path[st.n] = "";
    q1.push(st);

    vis2[res.n] = 1;
    path[res.n] = "";
    q2.push(res);

    while(q1.size() && q2.size()){
        int q1_l = q1.size();
        for(int z=0; z<q1_l; z++){
            Node cur1 = q1.front();
            q1.pop();

            for(int i=0; i<4; i++){
                int nx = cur1.cur / 3 + dx1[i];
                int ny = cur1.cur % 3 + dy1[i];

                if(nx < 0 || ny < 0 || nx > 2 || ny > 2)
                    continue;

                Node tmp = cur1;
                tmp.cur = nx*3 + ny;
                swap(tmp.s[tmp.cur], tmp.s[cur1.cur]);
                tmp.n = cantor(tmp.s);

                if(vis2[tmp.n]) {
                    return path[cur1.n] + p[i] + path[tmp.n];
                }

                if(!vis1[tmp.n]) {
                    vis1[tmp.n] = 1;
                    path[tmp.n] = path[cur1.n] + p[i];
                    q1.push(tmp);
                }
            }
        }

        int q2_l = q2.size();
        for(int z=0; z<q2_l; z++){
            Node cur2 = q2.front();
            q2.pop();

            for(int i=0; i<4; i++){
                int nx = cur2.cur / 3 + dx2[i];
                int ny = cur2.cur % 3 + dy2[i];

                if(nx < 0 || ny < 0 || nx > 2 || ny > 2)
                    continue;

                Node tmp = cur2;
                tmp.cur = nx*3 + ny;
                swap(tmp.s[tmp.cur], tmp.s[cur2.cur]);
                tmp.n = cantor(tmp.s);

                if(vis1[tmp.n])
                    continue;

                string nxtPath = p[i]+path[cur2.n];
                if(!vis2[tmp.n]) {
                    vis2[tmp.n] = 1;
                    path[tmp.n] = nxtPath;
                    q2.push(tmp);
                } else if(path[tmp.n] > nxtPath) {
                    path[tmp.n] = nxtPath;
                }
            }
        }
    }

    return "unsolvable";
}

int main(){
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    cin.ignore();
    while(T--){
        string line;
        getline(cin, line, '\n');

        for(int i=0; i<9; i++) {
            if(line[i] == 'X') {
                st.s[i] = 0;
                st.cur = i;
        } else {
                st.s[i] = line[i] - '0';
            }
        }
        st.n = cantor(st.s);

        getline(cin, line, '\n');
        for(int i=0; i<9; i++) {
            if(line[i] == 'X') {
                res.s[i] = 0;
                res.cur = i;
            }
            else {
                res.s[i] = line[i] - '0';
            }
        }
        res.n = cantor(res.s);

        string ans = bfs();
        cout << "Case " << ++cnt << ": " << ans.size() << '\n';
        cout << ans << '\n';
    }

    return 0;
}
