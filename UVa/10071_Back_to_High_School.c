#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v, t;
    while(scanf("%d %d", &v, &t) == 2)
    {
        v *= t * 2;
        printf("%d\n", v);
    }
    exit(0);
}
