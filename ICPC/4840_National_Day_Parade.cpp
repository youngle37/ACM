#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0x3fffffff

int N, M;
vector<int> stu[60];

int main(){
    while(scanf("%d %d", &N, &M) && (N || M)){

        for(int i=0;i<N;++i)
            stu[i].clear();

        int x, y;
        for(int i=0;i<N*N;++i){
            scanf("%d %d", &x, &y);
            stu[x-1].push_back(y);
        }

        for(int i=0;i<N;++i){
            sort(stu[i].begin(), stu[i].end());
        }


        int ans = INF;
        int dis;
        for(int i=1;i<=M-N;++i){
            dis = 0;
            for(int k=0;k<N;++k){
                for(int l=0;l<N;++l){
                    dis += abs(stu[k][l]-(i+l));
                }
            }

            ans = min(ans, dis);
        }

        printf("%d\n", ans);

    }

    return 0;
}
