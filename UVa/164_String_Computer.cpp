#include <cstdio>
#include <cstring>

char a[25], b[25];
int dp[25][25];
int p[25][25];

int MMIN(int i, int j, int *s){
    int rtn, k;
    for(k=1; k<=3; k++){
        if(s[k] < dp[i][j]){
            dp[i][j] = s[k];
            rtn = k;
        }
    }
    if(rtn == 3 && a[i] == b[j]){
        rtn = 0;
    }

    return rtn;
}

void print(int i, int j){
    if(!i && !j){
        return;
    }

    if(p[i][j] == 1){ // delete
        print(i-1, j);
        printf("D%c%02d", a[i], j+1);
    } else if(p[i][j] == 2){ // insert
        print(i, j-1);
        printf("I%c%02d", b[j], j);
    } else if(p[i][j] == 0){ // do nothing
        print(i-1, j-1);
    } else { // change
        print(i-1, j-1);
        printf("C%c%02d", b[j], j);
    }

    return;
}

int main(){
    int len_a, len_b;
    while(true){
        scanf("%s", a+1);
        if(a[1] == '#')
            break;

        scanf("%s", b+1);

        len_a = strlen(a+1);
        len_b = strlen(b+1);

        memset(dp, 0x3f, sizeof(dp));
        memset(p, -1, sizeof(p));

        for(int i=0; i<=len_a; i++){
            dp[i][0] = i;
            p[i][0] = 1; // delete
        }
        for(int i=0; i<=len_b; i++){
            dp[0][i] = i;
            p[0][i] = 2; // insert
        }

        // DP
        for(int i=1; i<=len_a; i++){
            for(int j=1; j<=len_b; j++){
                int s[4];
                s[1] = dp[i-1][j] + 1; // delete
                s[2] = dp[i][j-1] + 1; // insert
                s[3] = dp[i-1][j-1] + (a[i] == b[j] ? 0 : 1);
                p[i][j] = MMIN(i, j, s);
            }
        }

        //for(int i=0; i<=len_a; i++){
            //for(int j=0; j<=len_b; j++){
                //printf("%d ",dp[i][j]);
            //}
            //printf("\n");
        //}
        //printf("\n");
        //for(int i=0; i<=len_a; i++){
            //for(int j=0; j<=len_b; j++){
                //printf("%d ", p[i][j]);
            //}
            //printf("\n");
        //}

        print(len_a, len_b);
        printf("E\n");
    }

    return 0;
}
