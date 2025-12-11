#include <stdio.h>
#include <string.h>

void reverse(char str1[], char str2[]);

int main()
{
    char str1[50] = "I love you";
    char str2[50];

    char str3[50] = "Hello World";
    char str4[50];

    // Test Case 1
    reverse(str1, str2);
    printf("Input  : %s\n", str1);
    printf("Output : %s\n\n", str2);

    // Test Case 2
    reverse(str3, str4);
    printf("Input  : %s\n", str3);
    printf("Output : %s\n", str4);

    return 0;
}

void reverse(char str1[], char str2[])
{
    int len = strlen(str1);
    int i;

    for (i = 0; i < len; i++)
    {
        str2[i] = str1[len - 1 - i];
    }

    str2[len] = '\0';
}
