#include <iostream>

using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int cnt = 0;
        for(; n; n >>= 1)
            if(n & 1)
                cnt++;

        cout << cnt << '\n';
    }

    return 0;
}
