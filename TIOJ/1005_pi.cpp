#include <stdio.h>
#include <math.h>

int GCD(int a, int b)
{
    int t;
    if(b>a)
    {
        t = a;
        a = b;
        b = t;
    }
    int remain;
    do
    {
        a %= b;
        remain = a;
        t = b;
        b = a;
        a = t;
    }while(remain);

    return a;

}

int main()
{
    int n;
    int counter, coprime_counter;
    int input[50];
    while(scanf("%d", &n))
    {
        if(!n)
            break;
        
        counter = n * (n-1) / 2;
        coprime_counter = 0;

        for(int i=0; i<n; ++i)
            scanf("%d", &input[i]);

        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                if(GCD(input[i], input[j]) == 1)
                    ++coprime_counter;
            }
        }

        if(!coprime_counter)
            printf("No estimate for this data set.\n");
        else
            printf("%.6f\n", (float)sqrt((counter * 6 / coprime_counter)));

    }

    return 0;
}
