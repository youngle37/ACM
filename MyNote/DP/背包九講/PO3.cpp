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
const int V = 50;

void ZeroOnePack(int *dp, int c, int w) {
    for(int v=V; v >= c; --v) {
        dp[v] = max(dp[v], dp[v-c]+w);
    }
}

void CompletePack(int *dp, int c, int w) {
    for(int v=c; v<=V; ++v) {
        dp[v] = max(dp[v], dp[v-c]+w);
    }
}

void MultiplePack(int *dp, int c, int w, int m) {
    if(c*m >= V) {
        CompletePack(dp, c, w);
        return;
    }

    int k = 1;
    while(k < m) {
        ZeroOnePack(dp, c*k, w*k);
        m -= k;
        k <<= 1;
    }
    ZeroOnePack(dp, c*m, w*m);
}

int main(){
    int C[N] = {5, 7, 10, 11, 12};
    int W[N] = {5, 6, 7, 8, 9};
    int M[N] = {3, 2, 2, 3, 1};

    int dp[V+1] = {0};
    for(int i=1; i<=N; ++i)
        MultiplePack(dp, C[i], W[i], M[i]);

    cout << dp[V];

    return 0;
}
