#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a, b, counter, sum;
    bool carry;
    int a_dig, b_dig;

    while (scanf("%d %d", &a, &b) != EOF && (a || b))
    {
        carry = false;
        sum = 0;
        counter = 0;

        while (a || b)
        {
            a_dig = a % 10;
            a /= 10;

            b_dig = b % 10;
            b /= 10;

            sum = a_dig + b_dig;

            if (sum > 9 || (sum == 9 && carry))
            {
                ++counter;
                carry = true;
            }
            else
                carry = false;
        }

        if (!counter)
            printf("No carry operation.\n");
        else if (counter != 1)
            printf("%d carry operations.\n", counter);
        else
            printf("1 carry operation.\n");
    }

    return 0;
}
