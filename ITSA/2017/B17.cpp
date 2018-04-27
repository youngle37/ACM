#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int M;
        cin >> M;

        int s = 0;
        for(int k = 1; k <= 100; ++k)
            s = (s + M) % k;

        cout << s << '\n';
    }

    return 0;
}
