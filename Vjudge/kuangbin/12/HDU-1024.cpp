#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>

#define MAXN 1000005

using namespace std;

int num[MAXN];
int pre_max[MAXN];
int dp[MAXN];

int main(){
    int m, n;
    while(~scanf("%d %d", &m, &n)) {
        for(int i=1; i<=n; ++i)
            scanf("%d", &num[i]);

        memset(dp, 0, sizeof(int)*(n+1));
        memset(pre_max, 0, sizeof(int)*(n+1));

        int tmp;
        for(int i=1; i<=m; ++i) {
            tmp = -1e9;
            for(int j=i; j<=n; ++j) {
                dp[j] = max(dp[j-1], pre_max[j-1]) + num[j];
                pre_max[j-1] = tmp;
                tmp = max(tmp, dp[j]);
            }
        }

        printf("%d\n", tmp);
    }

    return 0;
}
