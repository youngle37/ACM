#include <cstdio>

int main(){
    int n;
    char s[100010];

    scanf("%d %s", &n, s);

    int test = 0;
    for(int i=0;i<n-10;i++){
        if(s[i] == '8')
            test++;
        else
            test--;
    }

    if(test > 0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
