#include <iostream>

using namespace std;

int main() {
    long long n;
    while(cin >> n) {
        if(n & 1)
            cout << (n / 2 + 1) * -1 << '\n';
        else
            cout << n / 2 << '\n';
    }
    return 0;
}
