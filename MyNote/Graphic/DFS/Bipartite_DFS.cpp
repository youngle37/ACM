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

bool isBipartite(vector<vector<int>> &G, vector<int> &color, vector<int> &discover, int n, int i) {
    for(int k = 0; k < n; ++k) {
        if(!discover[k] && G[i][k]) {
            discover[k] = 1;

            color[k] = !color[i];

            if(!isBipartite(G, color, discover, n, k))
                return false;
        } else if(color[k] == color[i] && G[i][k]) {
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

    vector<int> color(n, -1);
    vector<int> discover(n, 0);

    color[0] = 0;
    isBipartite(G, color, discover, n, 0) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
