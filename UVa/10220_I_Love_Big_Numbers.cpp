#include <stdio.h>
#include <string.h>

int digits[2600];
int num[1010] = {0};
int now_digit = 1;

void init(){
    num[0] = 1;
    digits[0] = 1;

    for(int i=1; i<=1000; i++){
        for(int j=0; j<now_digit; j++){
            digits[j] *= i;
        }

        for(int j=0; j<now_digit; j++){
            digits[j+1] += digits[j]/10;
            digits[j] %= 10;

            if(j+1 >= now_digit && digits[j+1] > 0){
                now_digit++;
            }

            num[i] += digits[j];
        }
    }
}

int main(){
    init();

    int n;
    while(scanf("%d", &n) != EOF)
        printf("%d\n", num[n]);

    return 0;
}
