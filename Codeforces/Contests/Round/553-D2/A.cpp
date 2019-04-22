#include <iostream>
#include <string>

#define min(a,b) ((a<b)?a:b)

using namespace std;

int dist(string s){
    int ret = 0;

    ret += min((s[0]-'A' + 26) % 26, ('A'-s[0] + 26) % 26);
    ret += min((s[1]-'C' + 26) % 26, ('C'-s[1] + 26) % 26);
    ret += min((s[2]-'T' + 26) % 26, ('T'-s[2] + 26) % 26);
    ret += min((s[3]-'G' + 26) % 26, ('G'-s[3] + 26) % 26);

    return ret;
}

int main(){
    int n;
    string s;

    cin >> n;
    cin >> s;

    int ans = 1000000000;
    for(int i=0; i<s.size()-3; i++){
        ans = min(ans, dist(s.substr(i, 4)));
    }

    cout << ans << '\n';

    return 0;
}
