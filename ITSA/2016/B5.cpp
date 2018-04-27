#include <stdio.h>
#include <vector>

using namespace std;

vector< vector<int> > adj(1010, vector<int>(1010));

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int vertex;
        scanf("%d", &vertex);

        for(int i=0;i<vertex;++i){
            for(int j=0;j<vertex;++j){
                scanf("%d", &adj[i][j]);
            }
        }

        int ans = 0;

        for(int i=0;i<vertex;++i){
            for(int j=i+1;j<vertex;++j){
                if(adj[i][j]){
                    for(int k=j+1;k<vertex;++k){
                        if(adj[j][k] && adj[i][k])
                            ans++;
                    }
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
