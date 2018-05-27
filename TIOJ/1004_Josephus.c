#include <stdio.h>

int main()
{
    int now = 0;
    int i;
    int n;
    scanf("%d", &n);
    for (i = 3; i <= n; ++i)
    {
        now = (now + 2) % i;
    }
    printf("%d\n", now + 1);
    return 0;
}
