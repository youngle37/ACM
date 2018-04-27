#include <stdio.h>

int main(){
    int h, w, y;
    while(scanf("%d %d %d", &h, &w, &y) && h != -1){
        float hat = 0.0, cloth = 0.0, pants = 0.0;

        if(y >= 28){
            int cnt = (y - 28) / 2;
            pants += cnt * 0.25;
        }

        if(y >= 30){
            int cnt = (y - 30) / 5;
            cloth += cnt * 0.15;
        }

        hat += (float)(w * 41.2 / h);
        cloth += (float) (h * w / 634.4);
        pants += w * 0.4;

        printf("%.2f %.2f %.2f\n", hat, cloth, pants);

        int what;
        scanf("%d", &what);
        if(what == -1)
            break;
    }

    return 0;
}
