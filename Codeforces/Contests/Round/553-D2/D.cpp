#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define maxn 100010

using namespace std;

int n;
pair< long long, long long > p[maxn];

bool cmp(const pair< long long, long long > l, const pair< long long, long long > r) {
    if(l.first + r.second > l.second + r.first) return true;
    else return false;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p, p + n, cmp);

    long long ans = 0;
    for(int i=0;i<n;i++)
        ans += i*(p[i].first) + (n-i-1)*(p[i].second);

    cout << ans << '\n';

    return 0;
}
