#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a, b, i;
    for(i=0; i<n; ++i)
    {
        scanf("%d %d", &a, &b);
        if(a == b)
            printf("%c\n", '=');
        else if(a > b)
            printf("%c\n", '>');
        else
            printf("%c\n", '<');
    }
    exit(0);
}
