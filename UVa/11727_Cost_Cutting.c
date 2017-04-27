#include <stdio.h>

int main()
{
    int n;
    int i;
    int each;
    int input[3];
    int min, max;
    while(scanf("%d", &n) != EOF)
    {
        for(i=0; i<n; ++i)
        {
            min = max = 0;
            for(each=0; each<3; ++each)
            {
                scanf("%d", &input[each]);
                if(input[each] > input[max])
                    max = each;
                else if(input[each] < input[min])
                    min = each;
            }
            printf("Case %d: ", i+1);
            for(each=0; each<3; ++each)
                if(each != min && each != max)
                    printf("%d\n", input[each]);

        }
    }
    return 0;
}
