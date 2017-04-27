#include <stdio.h>

int main()
{
    int test_number;
    int a, b, sum;
    int i;

    scanf("%d", &test_number);
    for(i = 1; i <= test_number; ++i)
    {
        sum = 0;
        scanf("%d", &a);
        scanf("%d", &b);
        do
        {
            if(a & 1)
                sum += a;
            ++a;   
        }while(a <= b);
        
        printf("Case %d: %d\n", i, sum);
    }
    return 0;
}
