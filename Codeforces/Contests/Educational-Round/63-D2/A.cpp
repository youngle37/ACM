#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    char tmp = s[0];
    for(int i=1;i<n;i++){
        if(s[i] < tmp){
            cout << "YES\n" << i << " " << i+1 << '\n';
            return 0;
        }

        tmp = s[i];
    }

    cout << "NO\n";

    return 0;
}
