/*
 * 從 root 開始 DFS
 * 每個點會 return 離最遠 leave 的距離
 *
 */

#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<bool>> adj;
int N,E;

int DFS(int x, int parent){
    int h = 0;

    for(int i=0;i<N;++i){
        if(adj[x][i] && i != parent)
            h = max(h, DFS(i, x)+1);
    }

    return h;
}

int main(){
    printf("Input the number of node: ");
    scanf("%d", &N);
    printf("Input the edge of tree: ");
    scanf("%d", &E);
    int root;
    printf("Enter the index of root: ");
    scanf("%d", &root);
    printf("Enter the edges:\n");

    int u,v;
    adj.resize(N, vector<bool>(N, 0));
    for(int i=0;i<E;++i){
        scanf("%d%d", &u,&v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("The height of this tree is %d\n", DFS(root, root));

    return 0;
}
