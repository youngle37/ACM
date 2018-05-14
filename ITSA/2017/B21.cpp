#include <stdio.h>

int count;

void div(int n, int index){
    int a, next = index+1;

    if(n == 0){
        count++;
        return;
    }

    for(a = n; a >= 3; a--){
        div(n-a, next);
    }
}

int main(){
    int n;
    int T;
    scanf("%d", &T);

    while(T--){
        scanf("%d", &n);
        count = 0;

        div(n,1);

        if(n)
            printf("%d\n", count);
        else
            printf("0\n");
    }

    return 0;
}
