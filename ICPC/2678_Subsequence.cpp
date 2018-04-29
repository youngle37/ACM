#include <stdio.h>
#include <algorithm>

#define min(a,b) (a < b ? a : b)
#define INF 0x3fffffff

using namespace std;

int N,S;
int num[100010];
int s[100010];

int main(){
    while(scanf("%d %d", &N, &S) != EOF){
        s[0] = 0;
        for(int i=1;i<=N;++i){
            scanf("%d", &num[i]);
            s[i] = s[i-1] + num[i];
        }

        int ans = INF;
        for(int i=1;i<=N;++i){
            int pos = lower_bound(s, s+i, s[i] - S) - s;
            if(pos > 0)
                ans = min(ans, i-pos+1);
        }

        printf("%d\n", ans == INF ? 0 : ans);
    }
    return 0;
}
