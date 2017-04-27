#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b1,b2,b3,g1,g2,g3,c1,c2,c3;
    int total;
    int bgc[6];
    int min;
    int i;
    while(scanf("%d%d%d%d%d%d%d%d%d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3) != EOF)
    {
        total = b1+b2+b3+g1+g2+g3+c1+c2+c3;
        
        bgc[0] = total - b1 - c2 - g3;
        bgc[1] = total - b1 - g2 - c3;
        bgc[2] = total - c1 - b2 - g3;
        bgc[3] = total - c1 - g2 - b3;
        bgc[4] = total - g1 - b2 - c3;
        bgc[5] = total - g1 - c2 - b3;
        
        min = 5;
        for(i = 4; i >= 0; --i)
        {
            if(bgc[i] <= bgc[min])
                min = i;
        }
        switch(min)
        {
            case 0:
                printf("BCG %d\n", bgc[0]);break;
            case 1:
                printf("BGC %d\n", bgc[1]);break;
            case 2:
                printf("CBG %d\n", bgc[2]);break;
            case 3:
                printf("CGB %d\n", bgc[3]);break;
            case 4:
                printf("GBC %d\n", bgc[4]);break;
            case 5:
                printf("GCB %d\n", bgc[5]);break;
        }
    }

    return 0;
}
