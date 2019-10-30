#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int N = 5;
const int V = 30;

void ZeroOnePack(int *dp, int c, int w) {
    for(int v=V; v >= c; --v)
        dp[v] = max(dp[v], dp[v-c] + w);
}

int main(){
    int C[N] = {5, 7, 10, 11, 12};
    int W[N] = {3, 4, 5 ,6 ,7};

    int dp[V+1] = {0};
    for(int i=1; i<=N; ++i)
        ZeroOnePack(dp, C[i], W[i]);

    cout << dp[V];

    return 0;
}
