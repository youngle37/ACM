#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int N;
int G;
int P[1005], W[1005];
int dp[1005][35];

int dfs(int n, int w) {
    if(w < 0) return -1e9;
    if(n < 0) return 0;
    if(dp[n][w]) return dp[n][w];

    return dp[n][w] = max(dfs(n-1, w), dfs(n-1, w-W[n])+P[n]);
}

int main(){
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) {
        memset(dp, 0, sizeof(dp));

        cin >> N;
        for(int i=0; i<N; i++)
            cin >> P[i] >> W[i];

        int ans = 0;
        int MW;
        cin >> G;
        for(int i=0; i<G; i++) {
            cin >> MW;
            ans += dfs(N-1, MW);
        }
        cout << ans << '\n';
    }

    return 0;
}
