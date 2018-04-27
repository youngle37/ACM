#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n,q;
        scanf("%d %d", &n, &q);

        vector<int> V(n);

        for(int i=0;i<n;++i)
            scanf("%d", &V[i]);

        int k=0;

        int temp = 1;
        for(;k<n;++k){
            temp *= V[k]%q;
            temp %= q;
            if(temp == 1)
                break;
        }

        if(k != n)
            printf("%d\n", k+1);
        else
            printf("%d\n", -1);
    }

    return 0;
}
