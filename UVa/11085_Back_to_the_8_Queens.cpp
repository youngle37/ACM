#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

int init_row[8];
int row[8];
bool place[8];
bool right[15];
bool left[15];

int ans;
int cnt;

void Compare(){
    int temp = 0;
    for(int i=0;i<8;i++)
        if(init_row[i]-1 != row[i])
            temp++;

    ans = ans > temp ? temp : ans;

    return;
}

void DFS(int cur){
    if(cur == 8){
        Compare();
        return;
    }

    for(int i=0;i<8;++i){
        if(!place[i] && !right[cur+i] && !left[7-i+cur]){
            place[i] = true;
            right[cur+i]= true;
            left[7-i+cur] = true;
            row[cur] = i;

            DFS(cur+1);

            place[i] = false;
            right[cur+i]=false;
            left[7-i+cur]=false;
            row[cur] = 0;
        }
    }

    return;
}

int main(){
    int T = 1;
    while(scanf("%d", init_row) != EOF){
        for(int i=1;i<8;i++)
            scanf("%d", &init_row[i]);

        memset(row, 0, sizeof(row));
        memset(right, 0 ,sizeof(right));
        memset(left, 0 ,sizeof(left));
        memset(place, 0,sizeof(place));

        cnt = 0;
        ans = 8;

        DFS(0);

        printf("Case %d: %d\n", T, ans);
        T++;
    }
    return 0;
}
