/*
 * words[0]：Religion 1's description
 * words[1]：Religion 2's description
 * words[2]：Religion 3's description
 *
 * dp[i][j][k]：words[0] 的長度 i 前綴, words[1] 的長度 j 前綴, words[2] 的長度 k 前綴的最小所需 pattern 的前綴長度
 *
 * dp[i][j][k] = min(dp[i-1][j][k]+下個出現 words[0][i-1] 的位置,
 *                   dp[i][j-1][k]+下個出現 words[1][j-1] 的位置,
 *                   dp[i][j][k-1]+下個出現 words[2][k-1] 的位置 )
 *
 * 由於 query 是一個一個加上去的
 * 所以如果這次是 words[0] 加字元
 * 那代表 dp[i-1][j][k] 已經被計算過了
 * 所以上面的其中一個迴圈就不需要跑了
 * 因此每個 query 複雜度為 O(250*250)
 *
 */
#include <iostream>
#include <string>

using namespace std;

int n, q;
string pattern;
string words[3];
int dp[255][255][255];
int next_char[100005][26];      // next_char[i][c] 為從 i 位置往後找第一個 c 的位置，沒有則為 n

void helper(){
    for(int i=0; i<26; i++)
        next_char[n][i] = next_char[n+1][i] = n;
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<26; j++){
            next_char[i][j] = pattern[i] == 'a' + j ? i : next_char[i+1][j];
        }
    }
}

void compute(int a, int b, int c){
    int &val = dp[a][b][c];
    val = n;
    if(a) val = min(val, next_char[dp[a-1][b][c] + 1][words[0][a-1] - 'a']);
    if(b) val = min(val, next_char[dp[a][b-1][c] + 1][words[1][b-1] - 'a']);
    if(c) val = min(val, next_char[dp[a][b][c-1] + 1][words[2][c-1] - 'a']);
}

int main(){
    cin >> n >> q >> pattern;

    helper();

    dp[0][0][0] = -1;

    for(int k=0; k<q; k++){
        char type, c;
        int i;
        cin >> type >> i;
        i--;
        if(type == '+'){
            cin >> c;
            words[i] += c;
            
            int max0 = words[0].size(), max1 = words[1].size(), max2 = words[2].size();
            int min0 = i == 0 ? max0 : 0;
            int min1 = i == 1 ? max1 : 0;
            int min2 = i == 2 ? max2 : 0;
            
            for(int A=min0; A<=max0; A++){
                for(int B=min1; B<=max1; B++){
                    for(int C=min2; C<=max2; C++){
                        compute(A, B, C);
                    }
                }
            }
        } else {
            words[i].pop_back();
        }

        bool answer = dp[words[0].size()][words[1].size()][words[2].size()] < n;
        cout << (answer ? "YES\n" : "NO\n");
    }


    return 0;
}
