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
#include <vector>
#include <string>

using namespace std;

void LCS_length(vector<vector<int>> &DP, string &s1, string &s2) {
    // 初始化
    // 當s1 or s2為空時, LCS為空集合
    for(int i = 0; i < DP.size(); ++i)
        DP[i][0] = 0;
    for(int j = 0; j < DP[0].size(); ++j)
        DP[0][j] = 0;

    // 填表格
    for(int i = 1; i < DP.size(); ++i) {
        for(int j = 1; j < DP[0].size(); ++j) {
            if(s1.at(i) == s2.at(j))
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }

    cout << DP[s1.size() - 1][s2.size() - 1] << '\n';
}

int main() {
    // 從位置1開始計算 for 實作方便
    string s1 = "_2579312";
    string s2 = "_35328";

    // DP[i][j] 代表 s1前 i 個元素 和 s2前 j 個元素的LCS長度
    vector<vector<int>> DP(s1.size(), vector<int>());
    for(int i = 0; i < DP.size(); ++i)
        DP[i].resize(s2.size());

    LCS_length(DP, s1, s2);

    return 0;
}
