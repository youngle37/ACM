#include <stdio.h>

int main()
{
    char *dividend;
    char *divisor;
    size_t bufsize = 51;
    size_t dividend_size;
    size_t divisor_size;

    dividend_size = getline(&dividend, &bufsize, stdin);
    divisor_size = getline(&divisor, &bufsize, stdin);

    for(int i=0; i<dividend_size - 1; ++i)
    {
        dividend[i] -= 48;
        printf("%c\n", dividend[i]);
    }
    
    printf("%zu\n", dividend_size);

    return 0;
}
