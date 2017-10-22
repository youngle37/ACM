#include <iostream>
#include <vector>
#include <queue>

#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define INF 0x3FFFFFFF

using namespace std;

int solve(vector<vector<int>> &G, int n, int m) {
    int left, right;
    for(int i = 0; i < m; ++i) {
        cin >> left >> right;
        --left;
        --right;
        G[left].push_back(right);
        G[right].push_back(left);
    }

    vector<int> distance(n, INF);
    vector<bool> visited(n, false);
    vector<int> set1, set2;
    queue<int> q;
    for(int i = 0; i < n; ++i) {
        if(visited[i])
            continue;

        visited[i] = true;
        distance[i] = 0;
        q.push(i);
        set1.push_back(0);
        set2.push_back(0);
        while(!q.empty()) {
            int now = q.front();
            q.pop();

            if(distance[now] % 2 == 0)
                ++set1.back();
            else
                ++set2.back();

            for(int j = 0; j < G[now].size(); ++j) {
                int neighbor = G[now][j];

                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[now] + 1;
                    q.push(neighbor);
                } else if(distance[now] % 2 == distance[neighbor] % 2)
                    return -1;
            }
        }
    }

    vector<bool> capacity(n + 1, false);
    capacity[0] = true;
    int most = 0, least = 0;
    for(int i = 0; i < set1.size(); ++i) {
        most += max(set1[i], set2[i]);
        for(int j = most ; j >= least; --j) {
            capacity[j] = (j >= set1[i] && capacity[j - set1[i]]) || (j >= set2[i] && capacity[j - set2[i]]);
        }
        least += min(set1[i], set2[i]);
    }

    for(int i = n / 2; i <= n; ++i)
        if(capacity[i])
            return i;

    return -1;

}

int main() {
    _
    int T;
    int n, m;
    cin >> T;
    vector<vector<int>> G(1001, vector<int>());

    while(T--) {
        for(int i = 0; i < 1001; ++i)
            G[i].clear();

        cin >> n >> m;
        cout << solve(G, n, m) << '\n';
    }

    return 0;
}
