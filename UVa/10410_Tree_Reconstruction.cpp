/*
 * DFS 順序的區間可看成一個子樹
 * 利用 BFS 順序去找區間的切點
 * 不一定為二元樹
 */
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define maxn 1000

struct Seg {
    int l, r;
    Seg(){}
    Seg(int l, int r){
        this->l = l;
        this->r = r;
    }
};

int n;
vector<int> ans[maxn+5];
int b[maxn+10], d[maxn+10];

void bfs(){
    int now = 1;
    queue<Seg> q;
    q.push(Seg(0, n));
    while(!q.empty()){
        Seg cur = q.front();
        q.pop();
        if(now == n || cur.l+1 == cur.r) continue;
        int v = d[cur.l];
        int pre = cur.l + 1;
        ans[v].push_back(d[pre]);
        now++;
        for(int i=cur.l+2; i<cur.r; i++){
            if(b[now] == d[i]){
                ans[v].push_back(d[i]);
                q.push(Seg(pre, i));
                pre = i;
                now++;
            }
        }
        if(pre < cur.r){
            q.push(Seg(pre, cur.r));
        }
    }
}

int main(){
    while(scanf("%d", &n) != EOF){
        for(int i=0; i<n; i++)
            ans[i+1].clear();
        for(int i=0; i<n; i++)
            scanf("%d", &b[i]);
        for(int i=0; i<n; i++)
            scanf("%d", &d[i]);

        bfs();

        for(int i=1; i<=n; i++){
            printf("%d:", i);
            for(int j=0; j<ans[i].size(); j++)
                printf(" %d", ans[i][j]);
            printf("\n");
        }
    }

    return 0;
}
