#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a, b;
    int diff;
    vector<vector<int>> dp(1005, vector<int>(1005));
    vector<vector<int>> d(1005, vector<int>(1005));
    while(cin >> a >> b) {
        a = "_" + a;
        b = "_"+b;

        for(int j = 0; j <= a.size(); ++j){
            dp[0][j] = j;
            d[0][j] = 2;
        }
        for(int i = 0; i <= b.size(); ++i){
            dp[i][0] = i;
            d[i][0] = 1;
        }

        for(int i = 1; i <= b.size(); ++i) {
            for(int j = 1; j <= a.size(); ++j) {
                if(a.at(j - 1) == b.at(i - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                    d[i][j] = 3;
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                    if(dp[i][j] == dp[i - 1][j] + 1)
                        d[i][j] = 1;
                    else if(dp[i][j] == dp[i - 1][j-1] + 1)
                        d[i][j] = 3;
                    else
                        d[i][j] = 2;
                }
            }
        }

        int ans = dp[b.size()][a.size()];
        cout << ans << '\n';

        for(int i=0;i<=b.size();++i){
            for(int j=0;j<=a.size();++j)
                cout << d[i][j] << ' ';
            cout << '\n';
        }


        int i = b.size();
        int j = a.size();
        vector<string> sta;
        while(i != 0 || j != 0) {
            if(a.at(j-1) == b.at(i-1)){
                j--;
                i--;
                continue;
            }

            if(d[i][j] == 3){
                i--;
                j--;
                sta.push_back("REPLACE "+to_string(i)+" "+b.at(i)+"\n");
            }
            else if(d[i][j] == 2){
                j--;
                sta.push_back("DELETE "+to_string(i)+" \n");
            }
            else{
                i--;
                sta.push_back("INSERT "+to_string(i)+" "+b.at(i)+"\n");
            }
        }

        while(!sta.empty()){
            cout << sta.back();
            sta.pop_back();
        }

    }

    return 0;
}
