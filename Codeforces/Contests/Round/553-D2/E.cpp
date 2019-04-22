#include <iostream>

#define maxn 100005
typedef long long LL;

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[maxn];
    for(int i = 0; i < n; i++) cin >> a[i];

    LL ans = (LL)(n + 1 - a[0]) * a[0];
    int L, R;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i - 1]) continue;
        if(a[i] > a[i - 1]) {
            L = a[i] - 1 - a[i - 1];
            R = n - a[i];
        } else if(a[i] < a[i - 1]) {
            L = a[i] - 1;
            R = a[i - 1] - 1 - a[i];
        }
        ans += (LL)L * R + L + R + 1;
    }

    cout << ans << '\n';

    return 0;
}
