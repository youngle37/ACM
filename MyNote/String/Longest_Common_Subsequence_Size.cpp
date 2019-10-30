/*
 * 找出 s1 和 s2 的最長共同子序列 LCS(s1, s2)
 *
 * 假設 e1 為 s1 最後一個元素 e2 為 s2 最後一個元素
 * 可以將 s1 及 s2 寫成以下形式
 * s1 = sub1 + e1
 * s2 = sub2 + e2
 *
 * 現在有四種情形
 * 1. 有 e1 沒 e2
 *  LCS(s1, s2) = LCS(s1, sub2)
 * 2. 有 e2 沒 e1
 *  LCS(s1, s2) = LCS(sub1, s2)
 * 3. 都沒 e1 和 e2
 *  LCS(s1, s2) = LCS(sub1, sub2)
 * 4. 都有 e1 和 e2
 *  LCS(s1, s2) = LCS(sub1, sub2) + e1
 *
 * 所以簡化為
 * LCS(s1, s2) = max(LCS(s1, sub2) , LCS(sub1, s2)) when e1 != e2
 *               LCS(sub1, sub2) + e1               when e1 == e2
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "2579312";
    string s2 = "35328";

    int n = s1.size();
    int m = s2.size();

    int dp[2][n+1];
    bool bi;
    for(int i=0; i<=m; ++i) {
        bi = i&1;
        for(int j=0; j<=n; ++j) {
            if(i==0 || j==0)
                dp[bi][j] = 0;
            else if(s1[j-1] == s2[i-1])
                dp[bi][j] = dp[1-bi][j-1]+1;
            else
                dp[bi][j] = max(dp[bi][j-1], dp[1-bi][j]);
        }
    }

    cout << dp[bi][n];

    return 0;
}
