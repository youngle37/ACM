#include <iostream>

using namespace std;

int main(){
    int m,n,a;
    while(cin >> n >> m >> a){
        long long x = n % a ? n/a + 1 : n/a;
        long long y = m % a ? m/a + 1 : m/a;

        cout << x*y << '\n';
    }

    return 0;
}
