#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);

    int input;
    int one = 0;
    int two = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &input);
        if(input == 1)
            ++one;
        else
            ++two;
    }

    if(one >= 3){
        printf("1 1 1");
        one -= 3;

        for(int i=0; i<two; i++)
            printf(" 2");

        for(int i=0; i<one; i++)
            printf(" 1");

        printf("\n");
    } else if(one == 2) {
        if(two){
            printf("2 1");
            for(int i=0; i<two-1; i++)
                printf(" 2");

            printf(" 1\n");
        } else{
            printf("1 1\n");
        }
    } else if(one == 1) {
        if(two){
            printf("2 1");

            for(int i=0; i<two-1; i++)
                printf(" 2");

            printf("\n");
        } else {
            printf("1\n");
        }
    } else {
        for(int i=0; i<two; i++){
            if(i)
                printf(" 2");
            else
                printf("2");
        }

        printf("\n");
    }

    return 0;
}
