#include <stdio.h>
#include <string.h>

int repre(char c){
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'H' || c == 'W' || c == 'Y')
        return 0;
    if(c == 'B' || c == 'F' || c == 'P' || c == 'V')
        return 1;
    if(c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z')
        return 2;
    if(c == 'D' || c == 'T')
        return 3;
    if(c == 'L')
        return 4;
    if(c == 'M' || c == 'N')
        return 5;
    if(c == 'R')
        return 6;

    return 0;
}

int main(){
    char input[20];
    char output[20];
    int last = 0;
    int size = 0;
    int count = 0;
    int temp;

    while(scanf("%s", input) != EOF){
        last = count = 0;
        size = strlen(input);

        for(int i=0; i<size; ++i){
            temp = repre(input[i]);
            if(temp != last){
                last = temp;
                if(temp != 0){
                    output[count] = temp + 48;
                    ++count;
                }
            }
        }
        output[count] = '\0';

        printf("%s\n", output);
    }
    return 0;
}
