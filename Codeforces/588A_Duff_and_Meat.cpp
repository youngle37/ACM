#include <iostream>

#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

inline int rit() {
    int f = 0, key = 1;
    char c;
    do {
        c = getchar();
        if(c == '-') key = -1;
    } while(c < '0' || c > '9');

    do {
        f = f * 10 + c - '0';
        c = getchar();
    } while(c >= '0' && c <= '9');

    return f * key;
}

int main() {
    _

    int n,a,p,ans = 0;

    n = rit();
    
    int temp = 1000;
    for(int i=0;i<n;++i){
        a = rit();
        temp = min(temp, rit());
        ans += a*temp;
    }

    cout << ans << '\n';

    return 0;
}
