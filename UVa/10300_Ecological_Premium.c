#include <stdio.h>
#include <stdlib.h>

int main()
{
    int case_number,count;
    int farmer_number,count_farmer;
    long long unsigned space, ani, env;
    long long unsigned sum;

    while(scanf("%d", &case_number) != EOF)
    {
        for(count = 0; count<case_number; ++count)
        {
            sum = 0;
            scanf("%d", &farmer_number);
            for(count_farmer=0; count_farmer<farmer_number; ++count_farmer)
            {
                scanf("%llu %llu %llu", &space, &ani, &env);
                sum += space * env;   
            }
            printf("%llu\n", sum);
        }
    }
    return 0;
}
