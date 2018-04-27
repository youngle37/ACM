#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> cnt(n+1, 0);
        int temp;
        for(int i=0;i<n;++i){
            cin >> temp;
            ++cnt[temp];
        }

        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = cnt[1];

        for(int i=2; i<=n; ++i)
            dp[i] = max(dp[i-1], dp[i-2] + cnt[i]*i);

        cout << dp[n] << '\n';
    }

    return 0;
}
