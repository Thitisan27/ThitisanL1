#include <stdio.h>
#include <string.h>

void reverse(char str1[], char str2[]) {
    int len = strlen(str1);
    int i;
    for (i = 0; i < len; i++) {
        str2[i] = str1[len - 1 - i];
    }
    str2[len] = '\0';
}

int main() {
    char text[50];
    char out[50];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    reverse(text, out);
    printf("%s\n", out);

    return 0;
}
