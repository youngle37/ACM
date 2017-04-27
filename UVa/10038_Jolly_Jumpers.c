#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;
    int jolly[3005];
    bool confirm = 1;
    int i,temp;
    while(scanf("%d", &n) != EOF)
    {
        bool jump[3005] = {0};
        confirm = 1;
        for(i=0;i<n;++i)
            scanf("%d", &jolly[i]);
        for(i=1;i<n;++i)
        {
            temp = abs(jolly[i] - jolly[i-1]);
            if(temp >= n || temp <= 0 || jump[temp])
            {
                confirm = 0;
                break;
            }
            jump[temp] = 1;
        }
        if(confirm)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
