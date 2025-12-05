#include <stdio.h>

void GetSet(int arr[], int *n) {
    int i;

    printf("Enter number of elements: ");
    scanf("%d", n);

    for (i = 0; i < *n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int main() {
    int data[50];
    int num;

    GetSet(data, &num);

    printf("\nData in the set:\n");
    for (int i = 0; i < num; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}
