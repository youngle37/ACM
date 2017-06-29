#include <stdio.h>

int main(){
    
    int s, p, y, j;
    int Y;

    while(scanf("%d %d %d %d", &s, &p, &y, &j) == 4){

    Y = (12+j-p-y) / 3;
    if((12+j-p-y) % 3 == 0){
        printf("%d %d %d\n", y+Y, p+Y, Y);
    }
    else if((12+j-p-y) % 3 == 1){
       if(p+s == y){
            printf("%d %d %d\n", y+Y+1, p+Y, Y);
       }
       else
           printf("%d %d %d\n", y+Y, p+Y+1, Y);
    }
    else{
        printf("%d %d %d\n", y+Y+1, p+Y+1, Y);
    }
    }
    return 0;
}
