#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    char *buffer;
    size_t bufsize = 1000;
    size_t character;

    size_t counter;
    size_t i;
    bool start,contin;
    char temp;

    buffer = (char *)malloc(bufsize * sizeof(char));

    while((character = getline(&buffer, &bufsize, stdin)) != EOF)
    {
        counter = 0;
        start = false;
        contin = false;

        for(i=0; i<character; ++i)
        {
            temp = buffer[i];
            if((temp > 64 && temp < 91) || (temp > 96 && temp < 123))
            {
                if(!start)
                    start = true;
                else
                    contin = true;
            }
            else
            {
               start = false;
               contin = false;
            }

            if(start && !contin)
                ++counter;
        }

        printf("%zu\n", counter);
    }
    return 0;
}
