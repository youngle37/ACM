#include <iostream>
#include <string>

#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
    _

    string s;
    bool AB,BA;

    while(cin >> s){
        AB = BA = false;

        for(int i=0;i<s.size();++i){
            if(i != s.size()-1 && s[i] == 'A' && s[i+1] == 'B' && !AB && !BA){
                AB = true;
                ++i;
            }
            else if(i != s.size()-1 && s[i] == 'B' && s[i+1] == 'A' && !BA && AB){
                BA = true;
                ++i;
            }
        }

        if(AB && BA){
            cout << "YES" << '\n';
            continue;
        }

        AB = BA = false;


        for(int i=0;i<s.size();++i){
            if(i != s.size()-1 && s[i] == 'B' && s[i+1] == 'A' && !BA && !AB){
                BA = true;
                ++i;
            }
            else if(i != s.size()-1 && s[i] == 'A' && s[i+1] == 'B' && !AB && BA){
                AB = true;
                ++i;
            }
        }

        if(AB && BA)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    

    return 0;
}
