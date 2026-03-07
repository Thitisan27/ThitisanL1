#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void InsNode(struct studentNode **start, char n[], int a, char s, float g) {
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = newNode;
    } else {
        struct studentNode *temp = *start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void writefile(struct studentNode *start) {
    FILE *fp = fopen("student.txt", "w");
    if (fp == NULL) return;
    
    struct studentNode *temp = start;
    while (temp != NULL) {
        fprintf(fp, "%s %d %c %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
        temp = temp->next;
    }
    fclose(fp);
}

void readfile(struct studentNode **start) {
    FILE *fp = fopen("student.txt", "r");
    if (fp == NULL) return;

    char n[20], s; int a; float g;
    while (fscanf(fp, "%s %d %c %f", n, &a, &s, &g) != EOF) {
        InsNode(start, n, a, s, g);
    }
    fclose(fp);
}

int main() {
    struct studentNode *listA = NULL;
    int menu;

    readfile(&listA);

    do {
        printf("\n--- Menu (1)Add (5)ShowAll (0)Exit : ");
        scanf("%d", &menu);

        if (menu == 1) {
            char n[20], s; int a; float g;
            printf("Enter Data: ");
            scanf("%s %d %c %f", n, &a, &s, &g);
            InsNode(&listA, n, a, s, g);
        } else if (menu == 5) {
            struct studentNode *temp = listA;
            while (temp != NULL) {
                printf("%s %d %c %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
                temp = temp->next;
            }
        }
    } while (menu != 0);

    writefile(listA);
    return 0;
}