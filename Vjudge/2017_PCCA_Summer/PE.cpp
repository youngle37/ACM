#include <iostream>
#include <string>

using namespace std;

int main(){
    string in;
    while(cin >> in){
        int ans = 0;
        for(int i=0;i<26;++i)
            if(in.find_first_of(i+'a') != string::npos)
                ++ans;

        if(ans & 1)
            cout << "IGNORE HIM!\n";
        else
            cout << "CHAT WITH HER!\n";

    }

    return 0;
}
