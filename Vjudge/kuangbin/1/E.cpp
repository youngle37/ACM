#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    char c[110];
    int cnt;
    int mod;
};

vector<bool> visit(220);

void BFS(int n) {
    fill(visit.begin(), visit.end(), false);

    Node start;
    start.c[0] = '1';
    start.cnt = 1;
    start.mod = 1 % n;

    queue<Node> q;
    q.push(start);

    Node temp;
    while(!q.empty()) {
        temp = q.front();
        q.pop();

        if(!temp.mod) {
            for(int i = 0; i < temp.cnt; ++i)
                cout << temp.c[i];
            cout << '\n';
            break;
        }

        visit[temp.mod] = true;

        temp.cnt++;
        temp.mod = (temp.mod * 10) % n;
        temp.c[temp.cnt - 1] = '0';
        if(!visit[temp.mod])
            q.push(temp);

        temp.mod = (temp.mod + 1) % n;
        temp.c[temp.cnt - 1] = '1';
        if(!visit[temp.mod])
            q.push(temp);
    }
}

int main() {
    int n;
    while(cin >> n && n)
        BFS(n);

    return 0;
}
