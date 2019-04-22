#include <iostream>

typedef long long LL;

using namespace std;

int n, m;

LL _gcd(LL a, LL b){
    while(b != 0){
        LL t = a % b;
        a = b;
        b = t;
    }

    return a;
}

int main(){
    cin >> n >> m;

    LL first, last, cur;
    LL gcd = 0;
    cin >> first;
    last = first;
    for(int i=1;i<n;i++){
        cin >> cur;
        gcd = _gcd(gcd, cur-last);
        last = cur;
    }

    LL ans = -1;
    LL tmp;
    for(int i=0;i<m;i++){
        cin >> tmp;
        if(gcd % tmp == 0){
            ans = i+1;
        }
    }

    if(ans == -1){
        cout << "NO\n";
    } else {
        cout << "YES\n" << first << " " << ans << '\n';
    }

    return 0;
}
