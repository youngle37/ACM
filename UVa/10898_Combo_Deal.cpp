#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>

#define x first
#define y second

using namespace std;

int I;
int C;
int Q;
int Iprice[10];
int combo[10][10];
int Cprice[10];
map<int, int> dp;

// Memeory search
int dfs(int state) {
    if(state == 0) return 0;
    if(dp.find(state) != dp.end()) return dp[state];

    int &val = dp[state];
    val = 0x3fffffff;

    int v[6];
    for(int i = I - 1; i >= 0; i--)
        v[i] = state % 10, state /= 10;

    int st;

    for(int i = 0; i < C; i++) {
        // Check
        int j;
        for(j = 0; j < I; j++)
            if(v[j] < combo[i][j])
                break;
        if(j != I)
            continue;

        st = 0;
        for(j = 0; j < I; j++) {
            v[j] -= combo[i][j];
            st = st * 10 + v[j];
        }

        val = min(val, dfs(st) + Cprice[i]);

        for(j = 0; j < I; j++)
            v[j] += combo[i][j];
    }

    for(int i = 0; i < I; i++) {
        if(v[i] == 0) continue;

        v[i]--;
        st = 0;
        for(int j = 0; j < I; j++)
            st = st * 10 + v[j];

        val = min(val, dfs(st) + Iprice[i]);

        v[i]++;
    }

    return val;

}

int main() {
    ios::sync_with_stdio(false);

    while(cin >> I) {
        dp.clear();

        for(int i = 0; i < I; i++)
            cin >> Iprice[i];

        cin >> C;
        for(int i = 0; i < C; i++) {
            for(int j = 0; j < I; j++)
                cin >> combo[i][j];
            cin >> Cprice[i];
        }

        cin >> Q;
        while(Q--) {
            int hash = 0, tmp;
            for(int i = 0; i < I; i++) {
                cin >> tmp;
                hash = hash * 10 + tmp;
            }
            cout << dfs(hash) << '\n';
        }
    }

    return 0;
}
