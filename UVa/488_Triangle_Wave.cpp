#include <cstdio>

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int A,F;
        scanf("%d%d", &A, &F);

        for(int i=0;i<F;++i){
            for(int j=1;j<=A;++j){
                for(int k=0;k<j;++k){
                    printf("%d", j);
                }
                printf("\n");
            }
            for(int j=A-1;j>0;--j){
                for(int k=0;k<j;++k)
                    printf("%d", j);
                printf("\n");
            }
            if(i != F-1)
                printf("\n");
        }

        if(T != 0)
            printf("\n");
    }

    return 0;
}
