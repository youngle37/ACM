#include <iostream>
#include <string>

using namespace std;

int main(){
    string X, Y;
    int n;
    while(cin >> n){
        cin.ignore(256, '\n');

        getline(cin, X);
        getline(cin, Y);

        bool pass = true;

        for(int i=1; i<=n; ++i){
            if(X.find(to_string(i)) == string::npos && Y.find(to_string(i)) == string::npos){
                pass = false;
                break;
            }
        }

        if(pass)
            cout << "I become the guy.\n";
        else
            cout << "Oh, my keyboard!\n";
    }

    return 0;
}
