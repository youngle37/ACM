#include <stdio.h>
#include <vector>
#include <utility>

#define pii pair<int,int>
#define INF 0x3fffffff

using namespace std;

vector<bool> visible;
vector<pii> coor;
int n;

bool inbound(int l, int r, int d, int u, int i){
    return coor[i].first >= l && coor[i].first <= r && coor[i].second >= d && coor[i].second <= u;
}

void setVisi(int l, int r, int d, int u, bool v){
    for(int i=0;i<n;++i)
        if(inbound(l,r,d,u,i))
            visible[i] = v;
}

bool dfs(int d, int l){
    if(d > 3){
        int cnt = 0;
        for(int i=0;i<n;++i)
            cnt += visible[i];
        
        return cnt == n;
    }

    int minX = INF, maxX = -INF, minY = INF, maxY = -INF;
    for(int i=0;i<n;++i){
        if(visible[i])
            continue;

        minX = min(minX, coor[i].first);
        maxX = max(maxX, coor[i].first);
        minY = min(minY, coor[i].second);
        maxY = max(maxY, coor[i].second);
    }

    // 左上
    setVisi(minX, minX+l, maxY-l, maxY, true);
    if(dfs(d+1, l))
        return true;
    setVisi(minX, minX+l, maxY-l, maxY, false);

    // 左下
    setVisi(minX, minX+l, minY, minY+l, true);
    if(dfs(d+1, l))
        return true;
    setVisi(minX, minX+l, minY, minY+l, false);

    // 右上
    setVisi(maxX-l, maxX, maxY-l, maxY, true);
    if(dfs(d+1, l))
        return true;
    setVisi(maxX-l, maxX, maxY-l, maxY, false);

    // 右下
    setVisi(maxX-l, maxX, minY, minY+l, true);
    if(dfs(d+1, l))
        return true;
    setVisi(maxX-l, maxX, minY, minY+l, false);

    return false;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        coor.resize(n);
        visible.resize(n);

        for(int i=0;i<n; ++i)
            scanf("%d %d", &coor[i].first, &coor[i].second);

        int l = 0, r = 2e9+10;
        int m;
        while(l <= r){
            m = (l+r)>>1;
            fill(visible.begin(), visible.end(), false);
            if(dfs(1, m))
                r = m - 1;
            else
                l = m + 1;
        }

        printf("%d\n", l);
    }

    return 0;
}
