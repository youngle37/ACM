#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    bool ans;
    size_t found;
    while(cin >> input){
        ans = false;

        found = input.find("AB");
        if(found != string::npos){
            found = input.find("BA", found+2);
            if(found != string::npos)
                ans = true;
        }

        found = input.find("BA");
        if(found != string::npos){
            found = input.find("AB", found+2);
            if(found != string::npos)
                ans = true;
        }

        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
