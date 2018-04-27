#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);

        vector<vector<int>> map(n, vector<int>(n));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &map[i][j]);

        int ans = 1e9;
        int sum;
        vector<int> p(n);
        for(int i=0;i<n;++i)
            p[i] = i;

        do{
            sum = 0;
            for(int i=0;i<n;++i){
                sum += map[i][p[i]];
            }

            if(sum < ans)
                ans = sum;
        }while(next_permutation(p.begin(), p.end()));

        printf("%d\n", ans);
    }
    return 0;
}
