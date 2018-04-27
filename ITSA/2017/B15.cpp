#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;

        int ans = 0;
        for(int i = 1; i <= k; ++i) {
            if(k % i == 0 && i <= n && k/i <= n)
                ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
