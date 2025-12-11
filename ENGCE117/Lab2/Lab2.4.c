#include <stdio.h>
#include <string.h>

//prototype
void explode(char str1[], char splitter, char str2[][10], int *count);

int main()
{
    char out[20][10];
    int num;

    char str1[] = "I/Love/You";
    char splitter = '/';

    explode(str1, splitter, out, &num);

    printf("str2[0] = %s\n", out[0]);
    printf("str2[1] = %s\n", out[1]);
    printf("str2[2] = %s\n", out[2]);
    printf("count = %d\n", num);

    return 0;
}

void explode(char str1[], char splitter, char str2[][10], int *count)
{
    int i = 0, j = 0;
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
