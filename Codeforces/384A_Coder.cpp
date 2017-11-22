#include <iostream>
#include <math.h>

using namespace std;

#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define mp(a, b) make_pair(a, b)
#define pii pair<int, int>
#define ll long long

inline int rit() {
    int f = 0, key = 1;
    char c;
    do {
        c = getchar();
        if(c == '-') key = -1;
    } while(c < '0' || c > '9');

    do {
        f = f * 10 + c - '0';
        c = getchar();
    } while(c >= '0' && c <= '9');

    return f * key;
}

int main() {
    _

    int n;
    n = rit();

    char grid[1005][1005];

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if((i + j) & 1)
                grid[i][j] = '.';
            else {
                ++ans;
                grid[i][j] = 'C';
            }
        }
    }

    cout << ans << '\n';

    for(int i = 0; i < n; ++i)
        cout << grid[i] << '\n';

    return 0;
}
