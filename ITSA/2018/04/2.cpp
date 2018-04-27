#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int left = 0, right = 0;
        bool fail_t = false;

        string buf;
        cin >> buf;

        for(int i=0;i<buf.size();++i){
            if(right > left){
                fail_t = true;
                break;
            }

            if(buf[i] == '\(')
                left++;
            else
                right++;
        }

        if(!fail_t && left == right)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
