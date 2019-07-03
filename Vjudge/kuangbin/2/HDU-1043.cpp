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
    int cur; // 目前 x 位置
    int n; // 康托展開值 (hash)
} state;

int fac[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int endState[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char p1[4] = {'d', 'u', 'r', 'l'};
char p2[4] = {'u', 'd', 'l', 'r'};

int vis1[362885], vis2[362885]; // 9! = 362880
string path[362885];

int getReverseOrderNum(){
    int num = 0;
    for(int i=0; i<8; i++){
        if(state.s[i]){
            for(int j=i+1; j<9; j++)
                if(state.s[j] < state.s[i] && state.s[j])
                    num++;
        }
    }
    return num;
}

int cantor(int *s){
    int sum = 1;
    for(int i=0; i<8; i++){
        int k = 0;
        for(int j=i+1; j<9; j++)
            if(s[j] < s[i]) k++;
        sum += k * fac[8 - i];
    }
    return sum;
}

void dbfs(){
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    queue<Node> q1, q2;

    state.n = cantor(state.s);
    q1.push(state);
    vis1[state.n] = 1;
    path[state.n] = "";

    Node end;
    memcpy(end.s, endState, sizeof(end.s));
    end.cur = 8;
    end.n = cantor(end.s);
    q2.push(end);
    vis2[end.n] = 1;
    path[end.n] = "";

    while(q1.size() || q2.size()){
        Node cur1 = q1.front();
        q1.pop();
        int x1 = cur1.cur / 3;
        int y1 = cur1.cur % 3;
        for(int i=0; i<4; i++){
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];
            if(nx < 0 || ny < 0 || nx > 2 || ny > 2) continue;

            Node tmp = cur1;
            tmp.cur = nx*3 + ny;
            swap(tmp.s[tmp.cur], tmp.s[cur1.cur]);
            tmp.n = cantor(tmp.s);

            if(vis2[tmp.n]){
                reverse(path[tmp.n].begin(), path[tmp.n].end());
                cout << path[cur1.n] << p1[i] << path[tmp.n] << '\n';
                return;
            }

            if(!vis1[tmp.n]){
                vis1[tmp.n] = 1;
                path[tmp.n] = path[cur1.n];
                path[tmp.n] += p1[i];
                q1.push(tmp);
            }
        }

        Node cur2 = q2.front();
        q2.pop();
        int x2 = cur2.cur / 3;
        int y2 = cur2.cur % 3;
        for(int i=0; i<4; i++){
            int nx = x2 + dx[i];
            int ny = y2 + dy[i];
            if(nx < 0 || ny < 0 || nx > 2 || ny > 2) continue;

            Node tmp = cur2;
            tmp.cur = nx*3 + ny;
            swap(tmp.s[tmp.cur], tmp.s[cur2.cur]);
            tmp.n = cantor(tmp.s);

            if(vis1[tmp.n]){
                reverse(path[cur2.n].begin(), path[cur2.n].end());
                cout << path[tmp.n] << p2[i] << path[cur2.n] << '\n';
                return;
            }

            if(!vis2[tmp.n]){
                vis2[tmp.n] = 1;
                path[tmp.n] = path[cur2.n];
                path[tmp.n] += p2[i];
                q2.push(tmp);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);

    string line;
    while(getline(cin, line, '\n')){
        istringstream SI(line);

        char c;
        int cnt = 0;
        while(SI >> c){
            if(c == 'x'){
                state.s[cnt] = 0;
                state.cur = cnt++;
            } else {
                state.s[cnt++] = c - '0';
            }
        }

        // 檢查逆序數 (忽略 x)
        // 由於目標狀態 (12345678) 為偶，因此當前狀態也應為偶
        // 否則無解
        // 證明：https://blog.csdn.net/tailzhou/article/details/3002442
        if(getReverseOrderNum() & 1)
            cout << "unsolvable\n";
        else
            dbfs(); // 雙向 BFS
    }

    return 0;
}
