#include <iostream>
#include <vector>
#include <algorithm>

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

    vector<pii> pos, neg;
    int x, a;
    for(int i = 0; i < n; ++i) {
        x = rit();
        a = rit();
        if(x > 0)
            pos.push_back(mp(x, a));
        else
            neg.push_back(mp(-1 * x, a));
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int times = min(pos.size(), neg.size());
    int ans = 0;
    for(int i = 0; i < times+1; ++i){
        if(i < pos.size()) ans += pos[i].second;
        if(i < neg.size()) ans += neg[i].second;
    }

    cout << ans << '\n';

    return 0;
}
