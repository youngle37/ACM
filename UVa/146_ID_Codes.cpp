/*
 * 若 s[j-1] > s[j] for all j
 * 則代表 No Successor
 *
 * 找出最後一個 s[i-1] < s[i]  (也就是 i 後面的子字串為最大字典序)
 * 再找出最後一個比 s[i-1] 還大的 character 設為 s[h] (h >= i)
 * 將 s[i-1] 與 s[h] 互換
 * 將 s[i] ~ s[length - 1] reverse (也就是從最大字典序變最小字典序)
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[100];

int main(){
    while(scanf("%s", s) && strcmp(s, "#")){
        int len = strlen(s);
        int i = -1;
        for(int j=1; j<len; j++){
            if(s[j] > s[j-1])
                i = j;
        }

        if(i == -1){
            printf("No Successor\n");
            continue;
        }
        
        int h = -1;
        for(int j=1; j<len; j++){
            if(s[j] > s[i-1])
                h = j;
        }

        swap(s[i-1], s[h]);
        reverse(s+i, s+len);
        puts(s);
    }
}
