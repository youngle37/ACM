#include <iostream>
#include <vector>

#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main() {
    _

    unsigned long long A;
    cin >> A;

    if(A == 1) {
        cout << 1 << '\n';
        return 0;
    }

    vector<int> cnt(10, 0);

    for(int i = 9; i > 1; --i) {
        while(A % i == 0) {
            A /= i;
            ++cnt[i];
        }
    }

    if(A != 1) {
        cout << -1 << '\n';
        return 0;
    }

    for(int i = 2; i < 10; ++i) {
        for(int j = 0; j < cnt[i]; ++j)
            cout << i;
    }

    cout << '\n';

    return 0;
}
