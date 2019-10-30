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

int cnt[MAXN];

int main(){
    int n;
    while(~scanf("%d", &n)) {
        memset(cnt, 0, sizeof(cnt));
        int num;
        for(int i=0; i<n; ++i) {
            scanf("%d", &num);
            cnt[num]++;
            if(cnt[num] == (n+1)/2)
                printf("%d\n", num);
        }
    }

    return 0;
}
