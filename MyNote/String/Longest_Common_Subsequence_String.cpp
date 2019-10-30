#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "2579312";
    string s2 = "35328";

    int n = s1.size();
    int m = s2.size();

    int dp[n+1][m+1];

    // Build table
    for(int i=0; i<=n; ++i) {
        for(int j=0; j<=m; ++j) {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    } 

    int len = dp[n][m];

    char lcs[len+1];
    lcs[len] = '\0';
    
    // Find path from right-most-bottom-most
    int i = n, j = m;
    while(i>0 && j>0) {
        if(s1[i-1] == s2[j-1]) {
            lcs[len-1] = s1[i-1];
            i--; j--; len--;
        } else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    cout << lcs << '\n';

    return 0;
}
