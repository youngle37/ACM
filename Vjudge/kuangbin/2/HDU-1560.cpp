#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Node {
    int cur[10];
    int len;
} st;

int T;
int N;
int ans;
string str[10];
string gene = "ACGT";
int endHash;

int vis[55555555];

void BFS() {
    for(int i = 0; i < N; i++)
        st.cur[i] = 0;
    st.len = 0;

    queue<Node> q;
    q.push(st);
    vis[0] = T;

    while(!q.empty()) {
        Node cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int has = 0;
            for(int j=0; j<N;j++){
                if(cur.cur[j] == str[j].size())
                    has += cur.cur[j];
                else
                    has += cur.cur[j] + (str[j][cur.cur[j]] == gene[i]);
                has *= 10;
            }
            has /= 10;


            if(vis[has] == T) continue;
            if(has == endHash){
                ans = cur.len + 1;
                return;
            }

            Node tmp;
            for(int j=0; j<N;j++){
                if(cur.cur[j] == str[j].size())
                    tmp.cur[j] = cur.cur[j];
                else
                    tmp.cur[j] = cur.cur[j] + (str[j][cur.cur[j]] == gene[i]);
            }
            tmp.len = cur.len + 1;

            vis[has] = T;
            q.push(tmp);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while(T) {
        cin >> N;
        cin.ignore();
        
        endHash = 0;
        for(int i = 0; i < N; i++){
            getline(cin, str[i], '\n');
            endHash += str[i].size();
            endHash *= 10;
        }
        endHash /= 10;

        ans = 1<<30;

        BFS();

        cout << ans << '\n';

        --T;
    }

    return 0;
}
