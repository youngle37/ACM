#include <stdio.h>
#include <stdlib.h>

typedef enum {true = 1 == 1,false = 1 == 0} bool;

int main()
{
    char *buffer;
    size_t bufsize = 100;
    size_t characters;

    bool first = 0;
    int i;

    buffer = (char *)malloc(bufsize * sizeof(char));
    while((characters = getline(&buffer ,&bufsize, stdin)) != -1)
    {
        for(i = 0; i < characters ; ++i)
        {
            if(buffer[i] == '"' && !first)
            {
                printf("``");
                first = 1;
            }
            else if(buffer[i] == '"' && first)
            {
                printf("''");
                first = 0;
            }
            else
                printf("%c", buffer[i]);
        }
    }
    return 0;
}
