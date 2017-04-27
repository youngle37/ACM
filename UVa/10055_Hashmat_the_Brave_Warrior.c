#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long Ours, Oppo;
    while(scanf("%lld %lld", &Ours, &Oppo) != EOF)
    {
        printf("%lld\n", (Ours > Oppo) ? Ours - Oppo : Oppo - Ours);
    }
    exit(0);
}
