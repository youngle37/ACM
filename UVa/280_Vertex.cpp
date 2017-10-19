#include <iostream>
#include <vector>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &discovered, int start) {
    discovered[start] = true;
    for(auto &v : adj[start]) {
        if(!discovered[v])
            dfs(adj, discovered, v);
    }
}

void solve(int n) {
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<bool> discovered(n + 1, false);

    int i, j;
    while(cin >> i && i != 0)
        while(cin >> j && j != 0)
            adj[i].push_back(j);

    int T, start;
    cin >> T;
    while(T--) {
        fill(discovered.begin(), discovered.end(), false);
        cin >> start;
        for(auto &v : adj[start])
            dfs(adj, discovered, v);

        int ans = 0;
        for(int i = 1; i <= n; ++i)
            if(!discovered[i])
                ++ans;

        cout << ans;
        for(int i = 1; i <= n; ++i) {
            if(!discovered[i])
                cout << ' ' << i;
        }

        cout << '\n';
    }
}

int main() {
        _
        int n;
        while(cin >> n && n != 0)
            solve(n);

        return 0;
    }
