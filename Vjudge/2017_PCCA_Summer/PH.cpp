#include <iostream>
#include <string>

using namespace std;

int main(){
    int b,a;
    string what;
    int n;
    while(cin >> n){
        bool good = false;

        for(int i=0;i<n;++i){
            cin >> what >> b >> a;
            if(b >= 2400 && a - b > 0)
                good = true;
        }

        if(good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
