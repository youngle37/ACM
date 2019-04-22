#include <cstdio>

int mat[510][510];

int main(){
    int n,m;
    scanf("%d%d", &n, &m);

    int row = -1, col = -1;
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &mat[i][j]);
            if(mat[i][j] != mat[i][0]){
                row = i;
                col = j;
            }
        }
        sum ^= mat[i][0];
    }

    if(sum == 0 && row == -1){
        puts("NIE");
        return 0;
    }

    if(sum != 0) col = 0;

    puts("TAK");
    for(int i=0; i<n; i++){
        if(i) printf(" ");
        printf("%d", (i==row)?col+1:1);
    }
    puts("");

    return 0;
}
