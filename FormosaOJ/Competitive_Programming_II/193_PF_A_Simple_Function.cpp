#include <iostream>
#include <vector>

using namespace std;

#define _ ios_base::sync_with_stdio(false);cin.tie(0);

inline int rit() {
    int f = 0, key = 1;
    char c;
    do {
        c = getchar();
        if(c == '-')key = -1;
    } while(c < '0' || c > '9');

    do {
        f = f * 10 + c - '0';
        c = getchar();
    } while(c >= '0' && c <= '9');

    return f * key;
}

int main() {
    _

    int T;
    cin >> T;

    

    while(T--){

    }

    return 0;
}
