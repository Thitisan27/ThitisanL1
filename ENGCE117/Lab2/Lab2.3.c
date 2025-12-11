#include <stdio.h>
#include <string.h>

void explode(char str1[], char splitter, char str2[][50], int *count)
{
    int i = 0;
    int j = 0;

    *count = 0;

    while (str1[i] != '\0')
    {
        if (str1[i] == splitter)
        {
            str2[*count][j] = '\0';  
            (*count)++;              
            j = 0;                   
        }
        else
        {
            str2[*count][j] = str1[i];
            j++;
        }

        i++;
    }

    str2[*count][j] = '\0';
    (*count)++;
}

int main()
{
    char out[20][50];
    int num;
    
    explode("I/Love/You", '/', out, &num);

    for (int i = 0; i < num; i++)
    {
        printf("str2[%d] = %s\n", i, out[i]);
    }

    printf("count = %d\n", num);

    return 0;
}
