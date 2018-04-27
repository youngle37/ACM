#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    while(getline(cin, input)){
        int sum = 0;

        sum += (input[2] - '0') * 2;
        sum += (input[3] - '0') * 3;
        sum += (input[4] - '0') * 4;
        sum += (input[6] - '0') * 5;
        sum += (input[7] - '0') * 6;
        sum += (input[8] - '0') * 7;
        sum += (input[9] - '0') * 8;
        sum += (input[10] - '0') * 9;

        if(sum % 11 == input[12] - '0')
            printf("Pass\n");
        else
            printf("Fail\n");
    }

    return 0;
}
