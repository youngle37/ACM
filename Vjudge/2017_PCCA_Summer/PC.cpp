#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int m, n;
    while(cin >> m >> n) {
        cout << floor(m*n*0.5) << '\n';
    }

    return 0;
}
