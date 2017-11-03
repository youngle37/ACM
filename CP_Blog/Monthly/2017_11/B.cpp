#include <iostream>
#include <vector>
#include <map>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main() {
    _

    int n, x, d, s;
    cin >> n >> x;

    map<int, int> m;

    for(int i = 0; i < n; ++i) {
        cin >> d >> s;
        ++m[d + s];
    }

    int ans = 0;

    for(map<int, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
        if(iter->second == x)
            ++ans;

    cout << ans;

    return 0;
}
