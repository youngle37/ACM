#include <iostream>

using namespace std;

int main() {
    long long n, k;
    while(cin >> n >> k) {
        if(n & 1) {
            if(k > (n + 1) / 2)
                cout << (k - (n + 1) / 2) * 2 << '\n';
            else
                cout << k * 2 - 1 << '\n';
        } else {
            if(k > n / 2)
                cout << (k - n / 2) * 2 << '\n';
            else
                cout << k * 2 - 1 << '\n';
        }
    }

    return 0;
}
