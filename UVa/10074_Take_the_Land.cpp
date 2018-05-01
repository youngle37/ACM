#include <stdio.h>
#include <vector>

using namespace std;

int N,M;
vector<int> rect[110];
vector<int> length[110];

int main(){
    while(scanf("%d %d", &N, &M) && (N || M)){
        for(int i=0;i<N;++i){
            rect[i].resize(M);
            length[i].resize(M);
        }

        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j)
                rect[i][j] = length[i][j] = 0;
        }

        int x;
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                scanf("%d", &x);
                rect[i][j] = x;
                if(j == 0 && rect[i][j] == 0)
                    length[i][j] = 1;
                else if(rect[i][j] == 0)
                    length[i][j] = length[i][j-1] + 1;
            }
        }


        int ans = 0;
        int temp;
        for(int i=N-1;i>=0;i--){
            for(int j=M-1;j>=0;j--){
                temp = 1e9;
                for(int k=i;k>=0;--k){
                    if(length[k][j] == 0)
                        break;

                    temp = min(temp, length[k][j]);
                    ans = max(ans, temp*(i-k+1));
                }
            }
        }

        printf("%d\n", ans);

        /*
        */
    }

    return 0;
}
