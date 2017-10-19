/*
 * 先把起始點 i 設為紅或藍然後丟到 queue 裡跑迴圈
 * 將所有鄰近的點丟到 queue 並把顏色設為目前點的另外一種
 * 若發現鄰近的點的顏色已經被改過且跟目前的點的顏色一樣則無法成為二分圖
 *
 *
 */

#include <iostream>
#include <queue>
#include <vector>

#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

bool isBipartite(vector<vector<int>> &G, int n, int i) {
    vector<int> color(n, -1);

    queue<int> q;
    
    color[i] = 0;
    q.push(i);

    int now;
    while(!q.empty()){
        now = q.front();
        q.pop();

        // be care of self-loop
        if(G[now][now] == 1) return false;

        for(int i=0;i<n;++i){
            if(G[now][i] == 1 && color[i] != -1){
                // color[now] == 0 ? color[i] = 1 : color[i] = 0;
                color[i] = 1 - color[now];
                q.push(i);
            }
            else if(G[now][i] == 1 && color[i] == color[now])
                return false;
        }
    }

    return true;
}

int main() {
    _

    int n;
    cin >> n;

    int temp;
    vector<vector<int>> G(n, vector<int>());
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            cin >> temp;
            G[i].push_back(temp);
        }

    cout << isBipartite(G, n, 0) << '\n';

    return 0;
}
