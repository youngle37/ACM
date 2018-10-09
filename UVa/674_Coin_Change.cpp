#include <cstdio>
#include <cstring>

int price[5] = {1, 5, 10, 25, 50};
int c[10000] = {0};

int main(){
    int m;
   
    c[0] = 1;

    for(int i=0; i<5; i++)
        for(int j=price[i]; j<=7489; j++)
            c[j] += c[j - price[i]];

    while(scanf("%d", &m) != EOF){
        printf("%d\n", c[m]);
    }

    return 0;
}
