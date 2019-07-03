#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

namespace godLike {
    int gcd(int a, int b){
        return b==0 ? a : gcd(b, a%b);
    }

    void solve(int S, int N, int M){
        S /= gcd(N, M);
        if(S&1)
            cout << "NO\n";
        else
            cout << S-1 << '\n';
    }
}

struct State {
    int v[3];
    int step;
};
queue<State> q;
State tmp;
int vis[105][105][105];
int v[3];
int ans;

void pour(int from, int to){
    int all = tmp.v[from]+tmp.v[to];
    if(all >= v[to]) tmp.v[to] = v[to];
    else tmp.v[to] = all;
    tmp.v[from] = all-tmp.v[to];
}

void BFS(){
    State s;
    s.v[0] = v[0], s.v[1] = 0, s.v[2] = 0, s.step = 0;
    vis[v[0]][0][0] = 1;
    q.push(s);
    
    while(!q.empty()){
        State cur = q.front();
        q.pop();

        if((cur.v[0]==cur.v[1]&&cur.v[0]!=0&&cur.v[2]==0)||(cur.v[0]==cur.v[2]&&cur.v[0]!=0&&cur.v[1]==0)||(cur.v[1]==cur.v[2]&&cur.v[1]!=0&&cur.v[0]==0)){
            ans = cur.step;
            return;
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i!=j){
                    tmp = cur;
                    pour(i, j);
                    if(!vis[tmp.v[0]][tmp.v[1]][tmp.v[2]]){
                        vis[tmp.v[0]][tmp.v[1]][tmp.v[2]] = 1;
                        tmp.step++;
                        q.push(tmp);
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);

    while(cin >> v[0] >> v[1] >> v[2] && v[0]){
        if(v[0]&1){
            cout << "NO\n";
            continue;
        }

        while(!q.empty()) q.pop();
        memset(vis, 0, sizeof(vis));
        ans = 1<<30;

        BFS();

        if(ans < (1<<30))
            cout << ans << '\n';
        else
            cout << "NO\n";

        // 神仙解法
        // https://www.cnblogs.com/ECJTUACM-873284962/p/6750320.html
        //godLike::solve(v[0], v[1], v[2]);
    }

    return 0;
}
