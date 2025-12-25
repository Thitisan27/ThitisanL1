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

void SaveNode(struct studentNode *node, char name[], int age, char sex, float gpa);
void GoNext2(struct studentNode **walk);

int main() {
    struct studentNode *start;
    struct studentNode **now2;

    start = (struct studentNode *)malloc(sizeof(struct studentNode));
    SaveNode(start, "one", 6, 'M', 3.11);

    start->next = (struct studentNode *)malloc(sizeof(struct studentNode));
    SaveNode(start->next, "two", 8, 'F', 3.22);

    start->next->next = (struct studentNode *)malloc(sizeof(struct studentNode));
    SaveNode(start->next->next, "three", 10, 'M', 3.33);

    start->next->next->next =
        (struct studentNode *)malloc(sizeof(struct studentNode));
    SaveNode(start->next->next->next, "four", 12, 'F', 3.44);

    now2 = &start;

    GoNext2(now2);

    printf("now2 points to: %s\n", (*now2)->name);

    return 0;
}

void SaveNode(struct studentNode *node, char name[], int age, char sex, float gpa) {
    strcpy(node->name, name);
    node->age = age;
    node->sex = sex;
    node->gpa = gpa;
    node->next = NULL;
}

void GoNext2(struct studentNode **walk) {
    if (*walk != NULL) {
        if ((*walk)->next != NULL) {
            *walk = (*walk)->next;

            printf("Name: %s\n", (*walk)->name);
            printf("Age: %d\n", (*walk)->age);
            printf("Sex: %c\n", (*walk)->sex);
            printf("GPA: %.2f\n", (*walk)->gpa);
        } else {
            printf("No next node\n");
        }
    }
}
