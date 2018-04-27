#include <stdio.h>
#include <vector>

using namespace std;

int p[32]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};
vector<int> ans(20);
vector<bool> used(20);
int n;
int T;

void DFS(int cur){
    if(cur == n && p[ans[0] + ans[n-1]]){
        printf("%d", ans[0]);
        for(int i=1;i<n;++i)
            printf(" %d", ans[i]);
        printf("\n");

        return;
    }

    for(int i=2;i<=n;++i){
        if(!used[i] && p[ans[cur-1] + i]){
            ans[cur] = i;
            used[i] = true;
            DFS(cur+1);
            used[i] = false;
        }
    }
}

int main(){
    T = 1;
    while(scanf("%d", &n) != EOF){
        if(T > 1)
            printf("\n");

        printf("Case %d:\n", T);
        ans.clear();
        used.clear();
        ans[0] = 1;
        used[1] = true;
        DFS(1);
        ++T;

    }
    return 0;
}
