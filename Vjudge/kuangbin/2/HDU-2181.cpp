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

int graph[25][3];
int ans[25];
int vis[25];
int T;
int m;

void DFS(int node, int k) {
    if(m == node && k != 0 && k < 20)
        return;
    if(m == node && k == 20) {
        cout << T++ << ":  " << m;
        for(int i=0; i<20; i++)
            cout << " " << ans[i];
        cout << '\n';
    }

    for(int i=0; i<3; i++){
        if(!vis[graph[node][i]]){
            vis[graph[node][i]] = 1;
            ans[k] = graph[node][i];
            DFS(graph[node][i], k+1);
            vis[graph[node][i]] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);

    for(int i=1; i<=20; i++)
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];

    while(cin >> m && m){
        memset(vis, 0, sizeof(vis));
        T = 1;
        DFS(m, 0);
    }

    return 0;
}
